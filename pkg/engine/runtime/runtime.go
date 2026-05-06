// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package runtime provide a runtime for the pipeline
package runtime

import (
	"fmt"
	"reflect"
	"strings"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/token"
	"github.com/spf13/cast"
)

type (
	FuncCheck func(*Task, *ast.CallExpr) *errchain.PlError
	FuncCall  func(*Task, *ast.CallExpr) *errchain.PlError
)

type Script struct {
	CallRef []*ast.CallExpr

	FuncCall map[string]FuncCall

	Name      string
	Namespace string
	Category  string
	FilePath  string

	Content string // deprecated

	Ast ast.Stmts
}

type Signal interface {
	ExitSignal() bool
}

type Opt func(ctx *Task)

func WithPrivate(v map[string]any) Opt {
	return func(ctx *Task) {
		ctx.private = v
	}
}

func (s *Script) Run(data Input, signal Signal, fn ...Opt) *errchain.PlError {
	if s == nil {
		return nil
	}

	ctx := GetContext()
	defer PutContext(ctx)

	for _, fn := range fn {
		fn(ctx)
	}

	ctx = InitCtx(ctx, data, s, signal)
	return RunStmts(ctx, s.Ast)
}

func (s *Script) RefRun(ctx *Task) *errchain.PlError {
	if s == nil {
		return nil
	}

	newctx := GetContext()
	defer PutContext(newctx)

	InitCtx(newctx, ctx.input, s, ctx.signal)

	return RunStmts(newctx, s.Ast)
}

func (s *Script) Check(funcsCheck map[string]FuncCheck) *errchain.PlError {
	if s == nil {
		return nil
	}

	ctx := GetContext()
	defer PutContext(ctx)
	InitCtxForCheck(ctx, s, funcsCheck)
	if err := RunStmtsCheck(ctx, &ContextCheck{}, s.Ast); err != nil {
		return err
	}

	s.CallRef = ctx.callRef
	return nil
}

func RunStmts(ctx *Task, nodes ast.Stmts) *errchain.PlError {
	for _, node := range nodes {
		var err *errchain.PlError
		if node != nil && node.NodeType == ast.TypeAssignmentExpr {
			_, _, err = RunAssignmentExpr(ctx, node.AssignmentExpr())
		} else {
			_, _, err = RunStmt(ctx, node)
		}
		if err != nil {
			ctx.procExit = true
			return err
		}

		if ctx.StmtRetrun() {
			return nil
		}
	}
	return nil
}

func runScoped(ctx *Task, fn func() *errchain.PlError) (err *errchain.PlError) {
	ctx.StackEnterNew()
	defer ctx.StackExitCur()
	return fn()
}

func RunIfElseStmt(ctx *Task, stmt *ast.IfelseStmt) (any, ast.DType, *errchain.PlError) {
	ctx.StackEnterNew()
	defer ctx.StackExitCur()

	// check if or elif condition
	for _, ifstmt := range stmt.IfList {
		// check condition
		val, dtype, err := RunStmt(ctx, ifstmt.Condition)
		if err != nil {
			return nil, ast.Invalid, err
		}
		if !condTrue(val, dtype) {
			continue
		}

		if ifstmt.Block != nil {
			// run if or elif stmt
			if err := runScoped(ctx, func() *errchain.PlError {
				return RunStmts(ctx, ifstmt.Block.Stmts)
			}); err != nil {
				return nil, ast.Void, err
			}
		}

		return nil, ast.Void, nil
	}

	if stmt.Else != nil {
		// run else stmt
		if err := runScoped(ctx, func() *errchain.PlError {
			return RunStmts(ctx, stmt.Else.Stmts)
		}); err != nil {
			return nil, ast.Void, err
		}
	}

	return nil, ast.Void, nil
}

func condTrue(val any, dtype ast.DType) bool {
	switch dtype { //nolint:exhaustive
	case ast.String:
		if v, ok := val.(string); ok {
			return v != ""
		}
		if cast.ToString(val) == "" {
			return false
		}
	case ast.Bool:
		if v, ok := val.(bool); ok {
			return v
		}
		return cast.ToBool(val)
	case ast.Int:
		if v, ok := val.(int64); ok {
			return v != 0
		}
		if cast.ToInt64(val) == 0 {
			return false
		}
	case ast.Float:
		if v, ok := val.(float64); ok {
			return v != 0
		}
		if cast.ToFloat64(val) == 0 {
			return false
		}
	case ast.List:
		if v, ok := val.([]any); ok {
			return len(v) != 0
		}
		if len(cast.ToSlice(val)) == 0 {
			return false
		}
	case ast.Map:
		switch v := val.(type) {
		case map[string]any:
			if len(v) == 0 {
				return false
			}
		default:
			return false
		}
	default:
		return false
	}
	return true
}

func RunForStmt(ctx *Task, stmt *ast.ForStmt) (any, ast.DType, *errchain.PlError) {
	ctx.StackEnterNew()
	defer ctx.StackExitCur()

	// for init
	if stmt.Init != nil {
		_, _, err := RunStmt(ctx, stmt.Init)
		if err != nil {
			return nil, ast.Invalid, err
		}
	}

	for {
		if stmt.Cond != nil {
			if ok, fast := runFastBoolNode(ctx, stmt.Cond); fast {
				if !ok {
					break
				}
			} else {
				val, dtype, err := RunStmt(ctx, stmt.Cond)
				if err != nil {
					return nil, ast.Invalid, err
				}
				if !condTrue(val, dtype) {
					break
				}
			}
		}

		if stmt.Body != nil {
			ctx.StackEnterNew()
			var err *errchain.PlError
			if len(stmt.Body.Stmts) == 1 && stmt.Body.Stmts[0] != nil &&
				stmt.Body.Stmts[0].NodeType == ast.TypeAssignmentExpr {
				_, _, err = RunAssignmentExpr(ctx, stmt.Body.Stmts[0].AssignmentExpr())
				if err != nil {
					ctx.procExit = true
				}
			} else {
				err = RunStmts(ctx, stmt.Body.Stmts)
			}
			ctx.StackExitCur()
			if err != nil {
				return nil, ast.Invalid, err
			}
		}

		if ctx.loopBreak {
			ctx.loopBreak = false
			break
		}

		if ctx.loopContinue {
			ctx.loopContinue = false
		}

		if ctx.StmtRetrun() {
			break
		}

		// loop stmt
		if stmt.Loop != nil {
			if stmt.Loop.NodeType == ast.TypeAssignmentExpr {
				_, _, err := RunAssignmentExpr(ctx, stmt.Loop.AssignmentExpr())
				if err != nil {
					return nil, ast.Invalid, err
				}
				continue
			}
			_, _, err := RunStmt(ctx, stmt.Loop)
			if err != nil {
				return nil, ast.Invalid, err
			}
		}
	}

	return nil, ast.Void, nil
}

func runFastBoolNode(ctx *Task, node *ast.Node) (bool, bool) {
	switch node.NodeType { //nolint:exhaustive
	case ast.TypeBoolLiteral:
		return node.BoolLiteral().Val, true
	case ast.TypeIdentifier:
		v, err := ctx.GetKey(node.Identifier().Name)
		if err != nil || v.DType != ast.Bool {
			return false, false
		}
		return fastBool(v.Value), true
	case ast.TypeConditionalExpr:
		expr := node.ConditionalExpr()
		switch expr.Op { //nolint:exhaustive
		case ast.EQEQ, ast.NEQ, ast.LT, ast.LTE, ast.GT, ast.GTE:
			if lhs, ok := runIntLikeNode(ctx, expr.LHS); ok {
				if rhs, ok := runIntLikeNode(ctx, expr.RHS); ok {
					return compareIntFast(lhs, rhs, expr.Op), true
				}
			}
		}
	case ast.TypeParenExpr:
		return runFastBoolNode(ctx, node.ParenExpr().Param)
	}
	return false, false
}

func compareIntFast(lhs, rhs int64, op ast.Op) bool {
	switch op { //nolint:exhaustive
	case ast.EQEQ:
		return lhs == rhs
	case ast.NEQ:
		return lhs != rhs
	case ast.LT:
		return lhs < rhs
	case ast.LTE:
		return lhs <= rhs
	case ast.GT:
		return lhs > rhs
	case ast.GTE:
		return lhs >= rhs
	default:
		return false
	}
}

func runAssignmentExprFast(ctx *Task, expr *ast.AssignmentExpr, lhs *ast.Node, rhs *ast.Node) (
	any, ast.DType, bool, *errchain.PlError) {
	if lhs.NodeType != ast.TypeIdentifier {
		return nil, ast.Invalid, false, nil
	}

	name := lhs.Identifier().Name
	switch expr.Op { //nolint:exhaustive
	case ast.EQ:
		if v, ok, err := runIntArithmeticNode(ctx, rhs, expr.OpPos); err != nil {
			return nil, ast.Invalid, true, err
		} else if ok {
			_ = ctx.SetVarb(name, v, ast.Int)
			return v, ast.Int, true, nil
		}
	case ast.SUBEQ,
		ast.ADDEQ,
		ast.MULEQ,
		ast.DIVEQ,
		ast.MODEQ:
		lVarb, err := ctx.GetKey(name)
		if err != nil || (lVarb.DType != ast.Int && lVarb.DType != ast.Bool) {
			return nil, ast.Invalid, false, nil
		}
		rhsVal, ok := runIntLikeNode(ctx, rhs)
		if !ok {
			return nil, ast.Invalid, false, nil
		}
		v, dt, errOp := arithAssignIntFast(fastInt64(lVarb.Value), rhsVal, expr.Op)
		if errOp != nil {
			return nil, ast.Invalid, true, NewRunError(ctx, errOp.Error(), expr.OpPos)
		}
		lVarb.Value = v
		lVarb.DType = dt
		return v, dt, true, nil
	}
	return nil, ast.Invalid, false, nil
}

func runIntArithmeticNode(ctx *Task, node *ast.Node, pos token.LnColPos) (int64, bool, *errchain.PlError) {
	if node.NodeType != ast.TypeArithmeticExpr {
		return 0, false, nil
	}
	expr := node.ArithmeticExpr()
	lhs, ok := runIntLikeNode(ctx, expr.LHS)
	if !ok {
		return 0, false, nil
	}
	rhs, ok := runIntLikeNode(ctx, expr.RHS)
	if !ok {
		return 0, false, nil
	}
	v, _, errOp := arithOpInt(lhs, rhs, expr.Op)
	if errOp != nil {
		return 0, true, NewRunError(ctx, errOp.Error(), pos)
	}
	return v, true, nil
}

func arithAssignIntFast(lhs, rhs int64, op ast.Op) (int64, ast.DType, error) {
	switch op { //nolint:exhaustive
	case ast.ADDEQ:
		return lhs + rhs, ast.Int, nil
	case ast.SUBEQ:
		return lhs - rhs, ast.Int, nil
	case ast.MULEQ:
		return lhs * rhs, ast.Int, nil
	case ast.DIVEQ:
		if rhs == 0 {
			return 0, ast.Invalid, fmt.Errorf("integer division by zero")
		}
		return lhs / rhs, ast.Int, nil
	case ast.MODEQ:
		if rhs == 0 {
			return 0, ast.Invalid, fmt.Errorf("integer modulo by zero")
		}
		return lhs % rhs, ast.Int, nil
	default:
		return 0, ast.Invalid, fmt.Errorf("unsupported op: %s", op)
	}
}

func RunForInStmt(ctx *Task, stmt *ast.ForInStmt) (any, ast.DType, *errchain.PlError) {
	ctx.StackEnterNew()
	defer ctx.StackExitCur()

	iter, dtype, err := RunStmt(ctx, stmt.Iter)
	if err != nil {
		return nil, ast.Invalid, err
	}

	ctx.StackEnterNew()
	defer ctx.StackExitCur()
	switch dtype { //nolint:exhaustive
	case ast.String:
		iter, ok := iter.(string)
		if !ok {
			return nil, ast.Invalid, NewRunError(ctx,
				"inner type error", stmt.Iter.StartPos())
		}
		for _, x := range iter {
			char := string(x)
			if stmt.Varb.NodeType != ast.TypeIdentifier {
				return nil, ast.Invalid, err
			}
			_ = ctx.SetVarb(stmt.Varb.Identifier().Name, char, ast.String)
			if stmt.Body != nil {
				if err := RunStmts(ctx, stmt.Body.Stmts); err != nil {
					return nil, ast.Invalid, err
				}
			}
			ctx.StackClear()

			if forbreak(ctx) {
				break
			}
			forcontinue(ctx)
			if ctx.StmtRetrun() {
				break
			}
		}
	case ast.Map:
		iter, ok := iter.(map[string]any)
		if !ok {
			return nil, ast.Invalid, NewRunError(ctx,
				"inner type error", stmt.Iter.StartPos())
		}
		for x := range iter {
			ctx.StackClear()
			_ = ctx.SetVarb(stmt.Varb.Identifier().Name, x, ast.String)
			if stmt.Body != nil {
				if err := RunStmts(ctx, stmt.Body.Stmts); err != nil {
					return nil, ast.Invalid, err
				}
			}
			if forbreak(ctx) {
				break
			}
			forcontinue(ctx)
			if ctx.StmtRetrun() {
				break
			}
		}
	case ast.List:
		iter, ok := iter.([]any)
		if !ok {
			return nil, ast.Invalid, NewRunError(ctx,
				"inner type error", stmt.Iter.StartPos())
		}
		for _, x := range iter {
			ctx.StackClear()
			x, dtype := ast.DectDataType(x)
			if dtype == ast.Invalid {
				return nil, ast.Invalid, NewRunError(ctx,
					"inner type error", stmt.Iter.StartPos())
			}
			_ = ctx.SetVarb(stmt.Varb.Identifier().Name, x, dtype)
			if stmt.Body != nil {
				if err := RunStmts(ctx, stmt.Body.Stmts); err != nil {
					return nil, ast.Invalid, err
				}
			}
			if forbreak(ctx) {
				break
			}
			forcontinue(ctx)
			if ctx.StmtRetrun() {
				break
			}
		}
	default:
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"unsupported type: %s, not iter value", dtype), stmt.Iter.StartPos())
	}

	return nil, ast.Void, nil
}

func forbreak(ctx *Task) bool {
	if ctx.loopBreak {
		ctx.loopBreak = false
		return true
	}
	return false
}

func forcontinue(ctx *Task) {
	if ctx.loopContinue {
		ctx.loopContinue = false
	}
}

func RunBreakStmt(ctx *Task, stmt *ast.BreakStmt) (any, ast.DType, *errchain.PlError) {
	ctx.loopBreak = true
	return nil, ast.Void, nil
}

func RunContinueStmt(ctx *Task, stmt *ast.ContinueStmt) (any, ast.DType, *errchain.PlError) {
	ctx.loopContinue = true
	return nil, ast.Void, nil
}

// RunStmt for all expr.
func RunStmt(ctx *Task, node *ast.Node) (any, ast.DType, *errchain.PlError) {
	// TODO
	// 存在个别 node 为 nil 的情况
	if node == nil {
		return nil, ast.Void, nil
	}
	switch node.NodeType { //nolint:exhaustive
	case ast.TypeParenExpr:
		return RunParenExpr(ctx, node.ParenExpr())
	case ast.TypeArithmeticExpr:
		return RunArithmeticExpr(ctx, node.ArithmeticExpr())
	case ast.TypeConditionalExpr:
		return RunConditionExpr(ctx, node.ConditionalExpr())
	case ast.TypeUnaryExpr:
		return RunUnaryExpr(ctx, node.UnaryExpr())
	case ast.TypeAssignmentExpr:
		return RunAssignmentExpr(ctx, node.AssignmentExpr())
	case ast.TypeCallExpr:
		return RunCallExpr(ctx, node.CallExpr())
	case ast.TypeSliceExpr:
		return RunSliceExpr(ctx, node.SliceExpr())
	case ast.TypeInExpr:
		return RunInExpr(ctx, node.InExpr())
	case ast.TypeListLiteral:
		return RunListInitExpr(ctx, node.ListLiteral())
	case ast.TypeIdentifier:
		if v, err := ctx.GetKey(node.Identifier().Name); err != nil {
			return nil, ast.Nil, nil
		} else {
			return v.Value, v.DType, nil
		}
	case ast.TypeMapLiteral:
		return RunMapInitExpr(ctx, node.MapLiteral())
	// use for map, slice and array
	case ast.TypeIndexExpr:
		return RunIndexExprGet(ctx, node.IndexExpr())

	// TODO
	case ast.TypeAttrExpr:
		return nil, ast.Void, nil

	case ast.TypeBoolLiteral:
		return node.BoolLiteral().Val, ast.Bool, nil

	case ast.TypeIntegerLiteral:
		return node.IntegerLiteral().Val, ast.Int, nil

	case ast.TypeFloatLiteral:
		return node.FloatLiteral().Val, ast.Float, nil

	case ast.TypeStringLiteral:
		return node.StringLiteral().Val, ast.String, nil

	case ast.TypeNilLiteral:
		return nil, ast.Nil, nil

	case ast.TypeIfelseStmt:
		return RunIfElseStmt(ctx, node.IfelseStmt())
	case ast.TypeForStmt:
		return RunForStmt(ctx, node.ForStmt())
	case ast.TypeForInStmt:
		return RunForInStmt(ctx, node.ForInStmt())
	case ast.TypeBreakStmt:
		return RunBreakStmt(ctx, node.BreakStmt())
	case ast.TypeContinueStmt:
		return RunContinueStmt(ctx, node.ContinueStmt())
	default:
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"unsupported ast node: %s", reflect.TypeOf(node).String()), node.StartPos())
	}
}

func RunUnaryExpr(ctx *Task, expr *ast.UnaryExpr) (any, ast.DType, *errchain.PlError) {
	switch expr.Op {
	case ast.SUB, ast.ADD:
		v, dtype, err := RunStmt(ctx, expr.RHS)
		if err != nil {
			return nil, ast.Invalid, err
		}
		switch dtype {
		case ast.Bool:
			val, _ := v.(bool)
			if expr.Op == ast.SUB {
				if val {
					return int64(-1), ast.Int, nil
				} else {
					return 0, ast.Int, nil
				}
			} else {
				if val {
					return int64(1), ast.Int, nil
				} else {
					return 0, ast.Int, nil
				}
			}
		case ast.Float:
			val, _ := v.(float64)
			if expr.Op == ast.SUB {
				return -val, ast.Float, nil
			} else {
				return val, ast.Float, nil
			}
		case ast.Int:
			val, _ := v.(int64)
			if expr.Op == ast.SUB {
				return -val, ast.Int, nil
			} else {
				return val, ast.Int, nil
			}
		default:
			return nil, ast.Invalid, NewRunError(ctx,
				fmt.Sprintf("unsuppored operand type for unary op %s: %s",
					expr.Op, reflect.TypeOf(expr).String()), expr.OpPos)
		}

	case ast.NOT:
		v, _, err := RunStmt(ctx, expr.RHS)
		if err != nil {
			return nil, ast.Invalid, err
		}

		if v == nil {
			return true, ast.Bool, nil
		}

		switch v := v.(type) {
		case bool:
			return !v, ast.Bool, nil
		case float64:
			if v == 0 {
				return true, ast.Bool, nil
			} else {
				return false, ast.Bool, nil
			}
		case int64:
			if v == 0 {
				return true, ast.Bool, nil
			} else {
				return false, ast.Bool, nil
			}
		case string:
			if len(v) == 0 {
				return true, ast.Bool, nil
			} else {
				return false, ast.Bool, nil
			}
		case map[string]any:
			if len(v) == 0 {
				return true, ast.Bool, nil
			} else {
				return false, ast.Bool, nil
			}
		case []any:
			if len(v) == 0 {
				return true, ast.Bool, nil
			} else {
				return false, ast.Bool, nil
			}

		default:
			return nil, ast.Invalid, NewRunError(ctx,
				fmt.Sprintf("unsuppored operand type for unary op %s: %s",
					expr.Op, reflect.TypeOf(expr).String()), expr.OpPos)
		}
	default:
		return nil, ast.Invalid, NewRunError(ctx,
			fmt.Sprintf("unsupported op for unary expr: %s", expr.Op), expr.OpPos)
	}
}

func RunListInitExpr(ctx *Task, expr *ast.ListLiteral) (any, ast.DType, *errchain.PlError) {
	ret := make([]any, 0, len(expr.List))
	for _, node := range expr.List {
		if v, _, ok := runBasicLiteralNode(node); ok {
			ret = append(ret, v)
			continue
		}
		v, _, err := RunStmt(ctx, node)
		if err != nil {
			return nil, ast.Invalid, err
		}
		ret = append(ret, v)
	}
	return ret, ast.List, nil
}

func RunMapInitExpr(ctx *Task, expr *ast.MapLiteral) (any, ast.DType, *errchain.PlError) {
	ret := make(map[string]any, len(expr.KeyValeList))

	for _, item := range expr.KeyValeList {
		var key string
		if item[0].NodeType == ast.TypeStringLiteral {
			key = item[0].StringLiteral().Val
		} else {
			k, keyType, err := RunStmt(ctx, item[0])
			if err != nil {
				return nil, ast.Invalid, err
			}
			var ok bool
			key, ok = k.(string)
			if !ok {
				return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
					"unsupported key data type: %s", keyType), item[0].StartPos())
			}
		}

		value, valueType, ok := runBasicLiteralNode(item[1])
		if !ok {
			var err *errchain.PlError
			value, valueType, err = RunStmt(ctx, item[1])
			if err != nil {
				return nil, ast.Invalid, err
			}
		}
		switch valueType { //nolint:exhaustive
		case ast.String, ast.Bool, ast.Float, ast.Int,
			ast.Nil, ast.List, ast.Map:
		default:
			return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
				"unsupported value data type: %s", valueType), item[1].StartPos())
		}
		ret[key] = value
	}

	return ret, ast.Map, nil
}

// func indexKeyType(dtype ast.DType) bool {
// 	switch dtype { //nolint:exhaustive
// 	case ast.Int, ast.String:
// 		return true
// 	default:
// 		return false
// 	}
// }

func RunIndexExprGet(ctx *Task, expr *ast.IndexExpr) (any, ast.DType, *errchain.PlError) {
	key := expr.Obj.Name

	varb, err := ctx.GetKey(key)
	if err != nil {
		return nil, ast.Invalid, NewRunError(ctx, err.Error(), expr.Obj.Start)
	}
	switch varb.DType { //nolint:exhaustive
	case ast.List:
		switch varb.Value.(type) {
		case []any:
		default:
			return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
				"unsupported type: %v", reflect.TypeOf(varb.Value)), expr.Obj.Start)
		}
	case ast.Map:
		switch varb.Value.(type) {
		case map[string]any: // for json map
		default:
			return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
				"unsupported type: %v", reflect.TypeOf(varb.Value)), expr.Obj.Start)
		}
	default:
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"unindexable type: %s", varb.DType), expr.Obj.Start)
	}

	if len(expr.Index) == 1 {
		return indexSingle(ctx, varb.Value, expr.Index[0])
	}
	return searchListAndMap(ctx, varb.Value, expr.Index)
}

func indexSingle(ctx *Task, obj any, node *ast.Node) (any, ast.DType, *errchain.PlError) {
	key, keyType, err := runIndexKey(ctx, node)
	if err != nil {
		return nil, ast.Invalid, err
	}
	switch curVal := obj.(type) {
	case map[string]any:
		if keyType != ast.String {
			return nil, ast.Invalid, NewRunError(ctx,
				"key type is not string", node.StartPos())
		}
		v, ok := curVal[fastString(key)]
		if !ok {
			return nil, ast.Nil, nil
		}
		v, dtype := dataTypeFast(v)
		return v, dtype, nil
	case []any:
		if keyType != ast.Int {
			return nil, ast.Invalid, NewRunError(ctx,
				"key type is not int", node.StartPos())
		}
		keyInt := fastInt(key)
		if keyInt < 0 {
			keyInt = len(curVal) + keyInt
		}
		if keyInt < 0 || keyInt >= len(curVal) {
			return nil, ast.Invalid, NewRunError(ctx,
				"list index out of range", node.StartPos())
		}
		v, dtype := dataTypeFast(curVal[keyInt])
		return v, dtype, nil
	default:
		return nil, ast.Invalid, NewRunError(ctx,
			"not found", node.StartPos())
	}
}

func searchListAndMap(ctx *Task, obj any, index []*ast.Node) (any, ast.DType, *errchain.PlError) {
	cur := obj

	for _, i := range index {
		key, keyType, err := runIndexKey(ctx, i)
		if err != nil {
			return nil, ast.Invalid, err
		}
		switch curVal := cur.(type) {
		case map[string]any:
			if keyType != ast.String {
				return nil, ast.Invalid, NewRunError(ctx,
					"key type is not string", i.StartPos())
			}
			var ok bool
			cur, ok = curVal[fastString(key)]
			if !ok {
				return nil, ast.Nil, nil
			}
		case []any:
			if keyType != ast.Int {
				return nil, ast.Invalid, NewRunError(ctx,
					"key type is not int", i.StartPos())
			}
			keyInt := fastInt(key)

			// 反转负数
			if keyInt < 0 {
				keyInt = len(curVal) + keyInt
			}

			if keyInt < 0 || keyInt >= len(curVal) {
				return nil, ast.Invalid, NewRunError(ctx,
					"list index out of range", i.StartPos())
			}
			cur = curVal[keyInt]
		default:
			return nil, ast.Invalid, NewRunError(ctx,
				"not found", i.StartPos())
		}
	}
	var dtype ast.DType
	cur, dtype = dataTypeFast(cur)
	return cur, dtype, nil
}

func dataTypeFast(v any) (any, ast.DType) {
	switch x := v.(type) {
	case nil:
		return nil, ast.Nil
	case string:
		return x, ast.String
	case int64:
		return x, ast.Int
	case float64:
		return x, ast.Float
	case bool:
		return x, ast.Bool
	case []any:
		return x, ast.List
	case map[string]any:
		return x, ast.Map
	default:
		return ast.DectDataType(v)
	}
}

func runBasicLiteralNode(node *ast.Node) (any, ast.DType, bool) {
	if node == nil {
		return nil, ast.Invalid, false
	}
	switch node.NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
		return node.StringLiteral().Val, ast.String, true
	case ast.TypeIntegerLiteral:
		return node.IntegerLiteral().Val, ast.Int, true
	case ast.TypeFloatLiteral:
		return node.FloatLiteral().Val, ast.Float, true
	case ast.TypeBoolLiteral:
		return node.BoolLiteral().Val, ast.Bool, true
	case ast.TypeNilLiteral:
		return nil, ast.Nil, true
	default:
		return nil, ast.Invalid, false
	}
}

func runIndexKey(ctx *Task, node *ast.Node) (any, ast.DType, *errchain.PlError) {
	if v, dtype, ok := runBasicLiteralNode(node); ok {
		return v, dtype, nil
	}
	return RunStmt(ctx, node)
}

func RunParenExpr(ctx *Task, expr *ast.ParenExpr) (any, ast.DType, *errchain.PlError) {
	return RunStmt(ctx, expr.Param)
}

// BinarayExpr

func RunInExpr(ctx *Task, expr *ast.InExpr) (any, ast.DType, *errchain.PlError) {
	lhs, lhsT, err := RunStmt(ctx, expr.LHS)
	if err != nil {
		return nil, ast.Invalid, err
	}

	rhs, rhsT, err := RunStmt(ctx, expr.RHS)
	if err != nil {
		return nil, ast.Invalid, err
	}

	switch rhsT {
	case ast.String:
		if lhsT != ast.String {
			return false, ast.Bool, NewRunError(ctx, fmt.Sprintf(
				"unsupported lhs data type: %s", lhsT), expr.OpPos)
		}
		if s, ok := lhs.(string); ok {
			if v, ok := rhs.(string); ok {
				return strings.Contains(v, s), ast.Bool, nil
			}
		}

		return false, ast.Bool, nil
	case ast.Map:
		if lhsT != ast.String {
			return false, ast.Bool, NewRunError(ctx, fmt.Sprintf(
				"unsupported lhs data type: %s", lhsT), expr.OpPos)
		}
		if s, ok := lhs.(string); ok {
			if v, ok := rhs.(map[string]any); ok {
				if _, ok := v[s]; ok {
					return true, ast.Bool, nil
				}
			}
		}
		return false, ast.Bool, nil
	case ast.List:
		if v, ok := rhs.([]any); ok {
			for _, elem := range v {
				if reflect.DeepEqual(lhs, elem) {
					return true, ast.Bool, nil
				}
			}
		}
		return false, ast.Bool, nil

	default:
		return false, ast.Bool, NewRunError(ctx, fmt.Sprintf(
			"unsupported rhs data type: %s", rhsT), expr.OpPos)
	}
}

func RunConditionExpr(ctx *Task, expr *ast.ConditionalExpr) (any, ast.DType, *errchain.PlError) {
	switch expr.Op { //nolint:exhaustive
	case ast.EQEQ, ast.NEQ, ast.LT, ast.LTE, ast.GT, ast.GTE:
		if lhs, ok := runIntLikeNode(ctx, expr.LHS); ok {
			if rhs, ok := runIntLikeNode(ctx, expr.RHS); ok {
				switch expr.Op { //nolint:exhaustive
				case ast.EQEQ:
					return lhs == rhs, ast.Bool, nil
				case ast.NEQ:
					return lhs != rhs, ast.Bool, nil
				case ast.LT:
					return lhs < rhs, ast.Bool, nil
				case ast.LTE:
					return lhs <= rhs, ast.Bool, nil
				case ast.GT:
					return lhs > rhs, ast.Bool, nil
				case ast.GTE:
					return lhs >= rhs, ast.Bool, nil
				}
			}
		}
	}

	lhs, lhsT, err := RunStmt(ctx, expr.LHS)
	if err != nil {
		return nil, ast.Invalid, err
	}

	if lhsT == ast.Bool {
		switch expr.Op { //nolint:exhaustive
		case ast.OR:
			if fastBool(lhs) {
				return true, ast.Bool, nil
			}
		case ast.AND:
			if !fastBool(lhs) {
				return false, ast.Bool, nil
			}
		}
	}

	rhs, rhsT, err := RunStmt(ctx, expr.RHS)
	if err != nil {
		return nil, ast.Invalid, err
	}

	if val, dtype, err := condOp(lhs, rhs, lhsT, rhsT, expr.Op); err != nil {
		return nil, ast.Invalid, NewRunError(ctx, err.Error(), expr.OpPos)
	} else {
		return val, dtype, nil
	}
}

func RunArithmeticExpr(ctx *Task, expr *ast.ArithmeticExpr) (any, ast.DType, *errchain.PlError) {
	// 允许字符串通过操作符 '+' 进行拼接
	if lhs, ok := runIntLikeNode(ctx, expr.LHS); ok {
		if rhs, ok := runIntLikeNode(ctx, expr.RHS); ok {
			v, dtype, errOp := arithOpInt(lhs, rhs, expr.Op)
			if errOp != nil {
				return nil, ast.Invalid, NewRunError(ctx, errOp.Error(), expr.OpPos)
			}
			return v, dtype, nil
		}
	}

	lhsVal, lhsValType, errOpInt := RunStmt(ctx, expr.LHS)
	if errOpInt != nil {
		return nil, ast.Invalid, errOpInt
	}

	rhsVal, rhsValType, errOpInt := RunStmt(ctx, expr.RHS)
	if errOpInt != nil {
		return nil, ast.Invalid, errOpInt
	}

	if !arithType(lhsValType) {
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"unsupported lhs data type: %s", lhsValType), expr.OpPos)
	}

	if !arithType(rhsValType) {
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"unsupported rhs data type: %s", rhsValType), expr.OpPos)
	}

	// string
	if lhsValType == ast.String || rhsValType == ast.String {
		if expr.Op != ast.ADD {
			return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
				"unsupported operand type(s) for %s: %s and %s",
				expr.Op, lhsValType, rhsValType), expr.OpPos)
		}
		if lhsValType == ast.String && rhsValType == ast.String {
			return fastString(lhsVal) + fastString(rhsVal), ast.String, nil
		} else {
			return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
				"unsupported operand type(s) for %s: %s and %s",
				expr.Op, lhsValType, rhsValType), expr.OpPos)
		}
	}

	// float
	if lhsValType == ast.Float || rhsValType == ast.Float {
		v, dtype, err := arithOpFloat(fastFloat64(lhsVal), fastFloat64(rhsVal), expr.Op)
		if err != nil {
			return nil, ast.Invalid, NewRunError(ctx, err.Error(), expr.OpPos)
		}
		return v, dtype, nil
	}

	// bool or int

	v, dtype, errOp := arithOpInt(fastInt64(lhsVal), fastInt64(rhsVal), expr.Op)

	if errOp != nil {
		return nil, ast.Invalid, NewRunError(ctx, errOp.Error(), expr.OpPos)
	}
	return v, dtype, nil
}

func runAssignArith(ctx *Task, l, r *Varb, op ast.Op, pos token.LnColPos) (
	any, ast.DType, *errchain.PlError) {

	arithOp, ok := assign2arithOp(op)
	if !ok {
		return nil, ast.Invalid, NewRunError(ctx,
			"unsupported op", pos)
	}

	if !arithType(l.DType) {
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"unsupported lhs data type: %s", l.DType), pos)
	}

	if !arithType(r.DType) {
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"unsupported rhs data type: %s", r.DType), pos)
	}

	// string
	if l.DType == ast.String || r.DType == ast.String {
		if arithOp != ast.ADD {
			return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
				"unsupported operand type(s) for %s: %s and %s",
				op, l.DType, r.DType), pos)
		}
		if l.DType == ast.String && r.DType == ast.String {
			return fastString(l.Value) + fastString(r.Value), ast.String, nil
		} else {
			return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
				"unsupported operand type(s) for %s: %s and %s",
				op, l.DType, r.DType), pos)
		}
	}

	// float
	if l.DType == ast.Float || r.DType == ast.Float {
		v, dtype, err := arithOpFloat(fastFloat64(l.Value), fastFloat64(r.Value), arithOp)
		if err != nil {
			return nil, ast.Invalid, NewRunError(ctx, err.Error(), pos)
		}
		return v, dtype, nil
	}

	// bool or int

	v, dtype, errOp := arithOpInt(fastInt64(l.Value), fastInt64(r.Value), arithOp)

	if errOp != nil {
		return nil, ast.Invalid, NewRunError(ctx, errOp.Error(), pos)
	}
	return v, dtype, nil
}

// RunAssignmentExpr runs assignment expression, but actually it is a stmt
func RunAssignmentExpr(ctx *Task, expr *ast.AssignmentExpr) (any, ast.DType, *errchain.PlError) {
	if !(len(expr.RHS) == 1 && len(expr.LHS) == 1) {
		return nil, ast.Void, NewRunError(ctx,
			"it does not support assigning values to multiple variables at the same time", expr.OpPos)
	}

	RHS := expr.RHS[0]
	LHS := expr.LHS[0]
	if LHS.NodeType == ast.TypeIdentifier {
		switch expr.Op { //nolint:exhaustive
		case ast.EQ:
			if RHS.NodeType == ast.TypeArithmeticExpr {
				if v, ok, err := runIntArithmeticNode(ctx, RHS, expr.OpPos); err != nil {
					return nil, ast.Invalid, err
				} else if ok {
					_ = ctx.SetVarb(LHS.Identifier().Name, v, ast.Int)
					return v, ast.Int, nil
				}
			}
		case ast.SUBEQ,
			ast.ADDEQ,
			ast.MULEQ,
			ast.DIVEQ,
			ast.MODEQ:
			if v, dtype, ok, err := runAssignmentExprFast(ctx, expr, LHS, RHS); ok || err != nil {
				if err != nil {
					return nil, ast.Invalid, err
				}
				return v, dtype, nil
			}
		}
	}

	rhsVal, rhsType, err := RunStmt(ctx, RHS)
	if err != nil {
		return nil, ast.Invalid, err
	}

	switch LHS.NodeType { //nolint:exhaustive
	case ast.TypeIdentifier:
		switch expr.Op {
		case ast.EQ:
			_ = ctx.SetVarb(LHS.Identifier().Name, rhsVal, rhsType)
			return rhsVal, rhsType, nil

		case ast.SUBEQ,
			ast.ADDEQ,
			ast.MULEQ,
			ast.DIVEQ,
			ast.MODEQ:
			lVarb, err := ctx.GetKey(LHS.Identifier().Name)
			if err != nil {
				return nil, ast.Nil, nil
			}
			rVarb := Varb{Value: rhsVal, DType: rhsType}
			if v, dt, errR := runAssignArith(ctx, lVarb, &rVarb, expr.Op, expr.OpPos); errR != nil {
				return nil, ast.Void, errR
			} else {
				lVarb.Value = v
				lVarb.DType = dt
				return v, dt, nil
			}

		default:
			return nil, ast.Invalid, NewRunError(ctx,
				"unsupported op", expr.OpPos)
		}
	case ast.TypeIndexExpr:
		switch expr.Op {
		case ast.EQ:
			varb, err := ctx.GetKey(LHS.IndexExpr().Obj.Name)
			if err != nil {
				return nil, ast.Invalid, NewRunError(ctx, err.Error(), LHS.IndexExpr().Obj.Start)
			}
			return changeListOrMapValue(ctx, varb.Value, LHS.IndexExpr().Index,
				rhsVal, rhsType)
		case ast.ADDEQ,
			ast.SUBEQ,
			ast.MULEQ,
			ast.DIVEQ,
			ast.MODEQ:
			varb, err := ctx.GetKey(LHS.IndexExpr().Obj.Name)
			if err != nil {
				return nil, ast.Invalid, NewRunError(ctx, err.Error(), LHS.IndexExpr().Obj.Start)
			}
			if v, dt, errR := searchListAndMap(ctx, varb.Value, LHS.IndexExpr().Index); errR != nil {
				return nil, ast.Invalid, errR
			} else {
				lVarb := Varb{Value: v, DType: dt}
				rVarb := Varb{Value: rhsVal, DType: rhsType}
				v, dt, err := runAssignArith(ctx, &lVarb, &rVarb, expr.Op, expr.OpPos)
				if err != nil {
					return nil, ast.Invalid, err
				}
				return changeListOrMapValue(ctx, varb.Value, LHS.IndexExpr().Index,
					v, dt)
			}
		default:
			return nil, ast.Invalid, NewRunError(ctx,
				"unsupported op", expr.OpPos)
		}

	default:
		return nil, ast.Void, nil
	}
}

func changeListOrMapValue(ctx *Task, obj any, index []*ast.Node, val any, dtype ast.DType) (any, ast.DType, *errchain.PlError) {
	if len(index) == 1 {
		return changeSingleIndexValue(ctx, obj, index[0], val, dtype)
	}

	cur := obj
	lenIdx := len(index)

	for idx, node := range index {
		key, keyType, err := runIndexKey(ctx, node)
		if err != nil {
			return nil, ast.Invalid, err
		}
		switch curVal := cur.(type) {
		case map[string]any:
			if keyType != ast.String {
				return nil, ast.Invalid, NewRunError(ctx,
					"key type is not string", node.StartPos())
			}
			if idx+1 == lenIdx {
				curVal[fastString(key)] = val
				return val, dtype, nil
			}

			var ok bool
			cur, ok = curVal[fastString(key)]
			if !ok {
				return nil, ast.Invalid, NewRunError(ctx,
					"key not found", node.StartPos())
			}
		case []any:
			if keyType != ast.Int {
				return nil, ast.Invalid, NewRunError(ctx,
					"key type is not int", node.StartPos())
			}
			keyInt := fastInt(key)

			// 反转负数
			if keyInt < 0 {
				keyInt = len(curVal) + keyInt
			}

			if keyInt < 0 || keyInt >= len(curVal) {
				return nil, ast.Invalid, NewRunError(ctx,
					"list index out of range", node.StartPos())
			}

			if idx+1 == lenIdx {
				curVal[keyInt] = val
				return val, dtype, nil
			}

			cur = curVal[keyInt]
		default:
			return nil, ast.Invalid, NewRunError(ctx,
				"obj not map or list", node.StartPos())
		}
	}
	return nil, ast.Nil, nil
}

func changeSingleIndexValue(ctx *Task, obj any, node *ast.Node, val any, dtype ast.DType) (any, ast.DType, *errchain.PlError) {
	key, keyType, err := runIndexKey(ctx, node)
	if err != nil {
		return nil, ast.Invalid, err
	}
	switch curVal := obj.(type) {
	case map[string]any:
		if keyType != ast.String {
			return nil, ast.Invalid, NewRunError(ctx,
				"key type is not string", node.StartPos())
		}
		curVal[fastString(key)] = val
		return val, dtype, nil
	case []any:
		if keyType != ast.Int {
			return nil, ast.Invalid, NewRunError(ctx,
				"key type is not int", node.StartPos())
		}
		keyInt := fastInt(key)
		if keyInt < 0 {
			keyInt = len(curVal) + keyInt
		}
		if keyInt < 0 || keyInt >= len(curVal) {
			return nil, ast.Invalid, NewRunError(ctx,
				"list index out of range", node.StartPos())
		}
		curVal[keyInt] = val
		return val, dtype, nil
	default:
		return nil, ast.Invalid, NewRunError(ctx,
			"obj not map or list", node.StartPos())
	}
}

func RunCallExpr(ctx *Task, expr *ast.CallExpr) (any, ast.DType, *errchain.PlError) {
	defer ctx.Regs.Reset()
	if funcCall, ok := ctx.GetFuncCall(expr.Name); ok {
		if err := funcCall(ctx, expr); err != nil {
			return nil, ast.Invalid, err
		}
		if ctx.Regs.Count() > 0 {
			if v, dtype, err := ctx.Regs.Get(RegR0); err != nil {
				return v, dtype, NewRunError(ctx, err.Error(), expr.NamePos)
			} else {
				return v, dtype, nil
			}
		}
	}
	return nil, ast.Void, nil
}
func RunSliceExpr(ctx *Task, expr *ast.SliceExpr) (any, ast.DType, *errchain.PlError) {
	obj, objT, err := RunStmt(ctx, expr.Obj)
	if err != nil {
		return nil, ast.Invalid, err
	}
	var start, end, step any
	var startT, endT, stepT ast.DType
	if expr.Start != nil {
		start, startT, err = RunStmt(ctx, expr.Start)
		if err != nil {
			return nil, ast.Invalid, err
		}
	}
	if expr.End != nil {
		end, endT, err = RunStmt(ctx, expr.End)
		if err != nil {
			return nil, ast.Invalid, err
		}
	}
	if expr.Step != nil {
		step, stepT, err = RunStmt(ctx, expr.Step)
		if err != nil {
			return nil, ast.Invalid, err
		}
	}
	var startInt, endInt, stepInt int
	var length int
	switch objT { //nolint:exhaustive
	case ast.String:
		length = len(obj.(string))
	case ast.List, ast.DType(ast.TypeSliceExpr):
		length = len(obj.([]any))
	default:
		return nil, ast.Invalid, NewRunError(ctx, "invalid obj type", expr.Obj.StartPos())
	}

	if step != nil {
		if stepT != ast.Int {
			return nil, ast.Invalid, NewRunError(ctx, "step type must be integer", expr.Step.StartPos())
		}
		stepInt = cast.ToInt(step)
		if stepInt == 0 {
			return nil, ast.Invalid, NewRunError(ctx, "step must be non-zero", expr.Step.StartPos())
		}
	} else {
		stepInt = 1
	}

	if start != nil {
		if startT != ast.Int {
			return nil, ast.Invalid, NewRunError(ctx, "start type must be integer", expr.Start.StartPos())
		}
		startInt = cast.ToInt(start)
		if startInt < 0 {
			startInt = length + startInt
		}
	} else if stepInt > 0 {
		startInt = 0
	} else {
		startInt = length - 1
	}

	if end != nil {
		if endT != ast.Int {
			return nil, ast.Invalid, NewRunError(ctx, "end type must be integer", expr.End.StartPos())
		}
		endInt = cast.ToInt(end)
		if endInt < 0 {
			endInt = length + endInt
		}
	} else if stepInt > 0 {
		endInt = length
	} else {
		endInt = -1
	}

	switch objT {
	case ast.String:
		str := obj.(string)
		if stepInt > 0 {
			var result strings.Builder
			if n := (endInt - startInt + stepInt - 1) / stepInt; n > 0 {
				result.Grow(n)
			}
			if startInt < 0 {
				startInt = 0
			}
			for i := startInt; i < endInt && i < length; i += stepInt {
				result.WriteByte(str[i])
			}
			return result.String(), ast.String, nil
		} else {
			var result strings.Builder
			if startInt > length-1 {
				startInt = length - 1
			}
			if n := (startInt - endInt - stepInt - 1) / (-stepInt); n > 0 {
				result.Grow(n)
			}
			for i := startInt; i > endInt && i >= 0; i += stepInt {
				result.WriteByte(str[i])
			}
			return result.String(), ast.String, nil
		}
	default:
		list := obj.([]any)
		if stepInt > 0 {
			if startInt < 0 {
				startInt = 0
			}
			if endInt > length {
				endInt = length
			}
			result := make([]any, 0, (endInt-startInt+stepInt-1)/stepInt)
			for i := startInt; i < endInt; i += stepInt {
				result = append(result, list[i])
			}
			return result, ast.List, nil
		} else {
			if startInt > length-1 {
				startInt = length - 1
			}
			if endInt < 0 {
				endInt = -1
			}
			result := make([]any, 0, (startInt-endInt-stepInt-1)/(-stepInt))
			for i := startInt; i > endInt; i += stepInt {
				result = append(result, list[i])
			}
			return result, ast.List, nil
		}
	}
}
func typePromotion(l ast.DType, r ast.DType) ast.DType {
	if l == ast.Float || r == ast.Float {
		return ast.Float
	}

	return ast.Int
}

func fastString(v any) string {
	if s, ok := v.(string); ok {
		return s
	}
	return cast.ToString(v)
}

func fastBool(v any) bool {
	if b, ok := v.(bool); ok {
		return b
	}
	return cast.ToBool(v)
}

func fastInt(v any) int {
	switch x := v.(type) {
	case int:
		return x
	case int64:
		return int(x)
	case bool:
		if x {
			return 1
		}
		return 0
	default:
		return cast.ToInt(v)
	}
}

func fastInt64(v any) int64 {
	switch x := v.(type) {
	case int64:
		return x
	case int:
		return int64(x)
	case bool:
		if x {
			return 1
		}
		return 0
	default:
		return cast.ToInt64(v)
	}
}

func runIntLikeNode(ctx *Task, node *ast.Node) (int64, bool) {
	switch node.NodeType { //nolint:exhaustive
	case ast.TypeIntegerLiteral:
		return node.IntegerLiteral().Val, true
	case ast.TypeBoolLiteral:
		if node.BoolLiteral().Val {
			return 1, true
		}
		return 0, true
	case ast.TypeIdentifier:
		v, err := ctx.GetKey(node.Identifier().Name)
		if err != nil {
			return 0, false
		}
		switch v.DType { //nolint:exhaustive
		case ast.Int, ast.Bool:
			return fastInt64(v.Value), true
		default:
			return 0, false
		}
	case ast.TypeParenExpr:
		return runIntLikeNode(ctx, node.ParenExpr().Param)
	default:
		return 0, false
	}
}

func fastFloat64(v any) float64 {
	switch x := v.(type) {
	case float64:
		return x
	case int64:
		return float64(x)
	case int:
		return float64(x)
	case bool:
		if x {
			return 1
		}
		return 0
	default:
		return cast.ToFloat64(v)
	}
}

func condOp(lhs, rhs any, lhsT, rhsT ast.DType, op ast.Op) (any, ast.DType, error) {
	switch op { //nolint:exhaustive
	case ast.EQEQ:
		switch lhsT { //nolint:exhaustive
		case ast.Int, ast.Bool, ast.Float:
			switch rhsT { //nolint:exhaustive
			case ast.Int, ast.Bool, ast.Float:
			default:
				return false, ast.Bool, nil
			}
			dtype := typePromotion(lhsT, rhsT)
			if dtype == ast.Float {
				return fastFloat64(lhs) == fastFloat64(rhs), ast.Bool, nil
			}
			return fastFloat64(lhs) == fastFloat64(rhs), ast.Bool, nil
		case ast.String:
			if rhsT != ast.String {
				return false, ast.Bool, nil
			}
			return fastString(lhs) == fastString(rhs), ast.Bool, nil
		case ast.Nil:
			if rhsT != ast.Nil {
				return false, ast.Bool, nil
			}
			return true, ast.Bool, nil
		default:
			return reflect.DeepEqual(lhs, rhs), ast.Bool, nil
		}

	case ast.NEQ:
		switch lhsT { //nolint:exhaustive
		case ast.Int, ast.Bool, ast.Float:
			switch rhsT { //nolint:exhaustive
			case ast.Int, ast.Bool, ast.Float:
			default:
				return true, ast.Bool, nil
			}
			dtype := typePromotion(lhsT, rhsT)
			if dtype == ast.Float {
				return fastFloat64(lhs) != fastFloat64(rhs), ast.Bool, nil
			}
			return fastFloat64(lhs) != fastFloat64(rhs), ast.Bool, nil
		case ast.String:
			if rhsT != ast.String {
				return true, ast.Bool, nil
			}
			return fastString(lhs) != fastString(rhs), ast.Bool, nil
		case ast.Nil:
			if rhsT != ast.Nil {
				return true, ast.Bool, nil
			}
			return false, ast.Bool, nil
		default:
			return !reflect.DeepEqual(lhs, rhs), ast.Bool, nil
		}
	}

	if !cmpType(lhsT) {
		return nil, ast.Invalid, fmt.Errorf("not compareable")
	}
	if !cmpType(rhsT) {
		return nil, ast.Invalid, fmt.Errorf("not compareable")
	}

	switch op { //nolint:exhaustive
	case ast.AND, ast.OR:
		if lhsT != ast.Bool || rhsT != ast.Bool {
			return nil, ast.Invalid, fmt.Errorf("unsupported operand type(s) for %s: %s and %s",
				op, lhsT, rhsT)
		}
		if op == ast.AND {
			return fastBool(lhs) && fastBool(rhs), ast.Bool, nil
		} else {
			return fastBool(lhs) || fastBool(rhs), ast.Bool, nil
		}

	case ast.LT:
		dtype := typePromotion(lhsT, rhsT)
		if dtype == ast.Float {
			return fastFloat64(lhs) < fastFloat64(rhs), ast.Bool, nil
		}
		return fastInt(lhs) < fastInt(rhs), ast.Bool, nil
	case ast.LTE:
		dtype := typePromotion(lhsT, rhsT)
		if dtype == ast.Float {
			return fastFloat64(lhs) <= fastFloat64(rhs), ast.Bool, nil
		}
		return fastInt(lhs) <= fastInt(rhs), ast.Bool, nil
	case ast.GT:
		dtype := typePromotion(lhsT, rhsT)
		if dtype == ast.Float {
			return fastFloat64(lhs) > fastFloat64(rhs), ast.Bool, nil
		}
		return fastInt(lhs) > fastInt(rhs), ast.Bool, nil
	case ast.GTE:
		dtype := typePromotion(lhsT, rhsT)
		if dtype == ast.Float {
			return fastFloat64(lhs) >= fastFloat64(rhs), ast.Bool, nil
		}
		return fastInt(lhs) >= fastInt(rhs), ast.Bool, nil
	default:
		return nil, ast.Invalid, fmt.Errorf("op error")
	}
}

func cmpType(dtype ast.DType) bool {
	switch dtype { //nolint:exhaustive
	case ast.Int, ast.Float, ast.Bool:
		return true
	}
	return false
}

func assign2arithOp(op ast.Op) (ast.Op, bool) {
	switch op {
	case ast.ADDEQ:
		return ast.ADD, true
	case ast.SUBEQ:
		return ast.SUB, true
	case ast.MULEQ:
		return ast.MUL, true
	case ast.DIVEQ:
		return ast.DIV, true
	case ast.MODEQ:
		return ast.MOD, true
	default:
		return "", false
	}
}

func arithType(dtype ast.DType) bool {
	switch dtype { //nolint:exhaustive
	case ast.Int, ast.Float, ast.Bool, ast.String:
		return true
	default:
		return false
	}
}

func arithOpInt(l int64, r int64, op ast.Op) (int64, ast.DType, error) {
	switch op { //nolint:exhaustive
	case ast.ADD:
		return l + r, ast.Int, nil
	case ast.SUB:
		return l - r, ast.Int, nil
	case ast.MUL:
		return l * r, ast.Int, nil
	case ast.DIV:
		if r == 0 {
			return 0, ast.Invalid, fmt.Errorf("integer division by zero")
		}
		return l / r, ast.Int, nil
	case ast.MOD:
		if r == 0 {
			return 0, ast.Invalid, fmt.Errorf("integer modulo by zero")
		}
		return l % r, ast.Int, nil
	default:
		return 0, ast.Invalid, fmt.Errorf("unsupported op: %s", op)
	}
}

func arithOpFloat(l float64, r float64, op ast.Op) (float64, ast.DType, error) {
	switch op { //nolint:exhaustive
	case ast.ADD:
		return l + r, ast.Float, nil
	case ast.SUB:
		return l - r, ast.Float, nil
	case ast.MUL:
		return l * r, ast.Float, nil
	case ast.DIV:
		if r == 0 {
			return 0, ast.Invalid, fmt.Errorf("float division by zero")
		}
		return l / r, ast.Float, nil
	default:
		return 0, ast.Invalid, fmt.Errorf("float does not support modulo operations")
	}
}
