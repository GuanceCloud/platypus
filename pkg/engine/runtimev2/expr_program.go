package runtimev2

import (
	"fmt"
	"reflect"
	"strings"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/token"
	"github.com/spf13/cast"
)

type expr interface {
	run(ctx *Task) *errchain.PlError
}

type valueExpr interface {
	evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError)
}

func (c *compiler) compileExpr(node *ast.Node) expr {
	if node == nil {
		return nil
	}
	switch node.NodeType {
	case ast.TypeBoolLiteral:
		return literalExpr{val: V{node.BoolLiteral().Val, ast.Bool}}
	case ast.TypeIntegerLiteral:
		return literalExpr{val: V{node.IntegerLiteral().Val, ast.Int}}
	case ast.TypeFloatLiteral:
		return literalExpr{val: V{node.FloatLiteral().Val, ast.Float}}
	case ast.TypeStringLiteral:
		return literalExpr{val: V{node.StringLiteral().Val, ast.String}}
	case ast.TypeNilLiteral:
		return literalExpr{val: V{nil, ast.Nil}}
	}
	if e, ok := c.tryCompileBytecode(node); ok {
		return e
	}

	switch node.NodeType {
	case ast.TypeParenExpr:
		return parenExpr{expr: c.compileExpr(node.ParenExpr().Param)}
	case ast.TypeUnaryExpr:
		e := node.UnaryExpr()
		return unaryExpr{
			op:    e.Op,
			rhs:   c.compileExpr(e.RHS),
			rhsN:  e.RHS,
			opPos: e.OpPos,
		}
	case ast.TypeArithmeticExpr:
		e := node.ArithmeticExpr()
		return arithmeticExpr{
			lhs:   c.compileExpr(e.LHS),
			rhs:   c.compileExpr(e.RHS),
			lhsN:  e.LHS,
			rhsN:  e.RHS,
			op:    e.Op,
			opPos: e.OpPos,
		}
	case ast.TypeConditionalExpr:
		e := node.ConditionalExpr()
		return conditionExpr{
			lhs:   c.compileExpr(e.LHS),
			rhs:   c.compileExpr(e.RHS),
			lhsN:  e.LHS,
			rhsN:  e.RHS,
			op:    e.Op,
			opPos: e.OpPos,
		}
	case ast.TypeInExpr:
		e := node.InExpr()
		return inExpr{
			lhs:   c.compileExpr(e.LHS),
			rhs:   c.compileExpr(e.RHS),
			lhsN:  e.LHS,
			rhsN:  e.RHS,
			opPos: e.OpPos,
		}
	case ast.TypeIndexExpr:
		e := node.IndexExpr()
		objSlot := c.slot(e.Obj.Name)
		index := make([]expr, 0, len(e.Index))
		indexV := make([]valueExpr, 0, len(e.Index))
		for _, item := range e.Index {
			compiled := c.compileExpr(item)
			index = append(index, compiled)
			if v, ok := compiled.(valueExpr); ok {
				indexV = append(indexV, v)
			} else {
				indexV = append(indexV, nil)
			}
		}
		return indexExpr{
			obj:     e.Obj,
			objSlot: objSlot,
			index:   index,
			indexV:  indexV,
			indexN:  e.Index,
		}
	case ast.TypeSliceExpr:
		e := node.SliceExpr()
		obj := c.compileExpr(e.Obj)
		if start, end, step, ok := compileConstSliceBounds(e.Start, e.End, e.Step); ok {
			return constSliceExpr{
				obj:    obj,
				objN:   e.Obj,
				start:  start,
				end:    end,
				step:   step,
				startN: e.Start,
				endN:   e.End,
				stepN:  e.Step,
			}
		}
		return sliceExpr{
			obj:    obj,
			start:  c.compileExpr(e.Start),
			end:    c.compileExpr(e.End),
			step:   c.compileExpr(e.Step),
			objN:   e.Obj,
			startN: e.Start,
			endN:   e.End,
			stepN:  e.Step,
		}
	case ast.TypeAssignmentExpr:
		e := node.AssignmentExpr()
		lhs := make([]assignTarget, 0, len(e.LHS))
		for _, node := range e.LHS {
			target := assignTarget{node: node, slot: -1}
			switch node.NodeType {
			case ast.TypeIdentifier:
				target.name = node.Identifier().Name
				target.slot = c.slot(target.name)
			case ast.TypeIndexExpr:
				target.name = node.IndexExpr().Obj.Name
				target.slot = c.slot(target.name)
			}
			lhs = append(lhs, target)
		}
		rhs := make([]expr, 0, len(e.RHS))
		rhsV := make([]valueExpr, 0, len(e.RHS))
		for _, item := range e.RHS {
			compiled := c.compileExpr(item)
			rhs = append(rhs, compiled)
			if v, ok := compiled.(valueExpr); ok {
				rhsV = append(rhsV, v)
			} else {
				rhsV = append(rhsV, nil)
			}
		}
		return assignExpr{
			lhs:   lhs,
			rhs:   rhs,
			rhsV:  rhsV,
			rhsN:  e.RHS,
			op:    e.Op,
			opPos: e.OpPos,
		}
	case ast.TypeCallExpr:
		return c.compileCallExpr(node.CallExpr())
	case ast.TypeListLiteral:
		e := node.ListLiteral()
		items := make([]expr, 0, len(e.List))
		constItems := make([]any, 0, len(e.List))
		allConst := true
		for _, item := range e.List {
			compiled := c.compileExpr(item)
			items = append(items, compiled)
			if lit, ok := compiled.(literalExpr); ok {
				constItems = append(constItems, lit.val.V)
			} else {
				allConst = false
			}
		}
		if allConst {
			return constListExpr{items: constItems}
		}
		return listExpr{items: items, nodes: e.List}
	case ast.TypeMapLiteral:
		e := node.MapLiteral()
		pairs := make([]mapPairExpr, 0, len(e.KeyValeList))
		constPairs := make([]constMapPair, 0, len(e.KeyValeList))
		allConst := true
		for _, pair := range e.KeyValeList {
			key := c.compileExpr(pair[0])
			val := c.compileExpr(pair[1])
			pairs = append(pairs, mapPairExpr{
				key:   key,
				val:   val,
				keyN:  pair[0],
				value: pair[1],
			})
			keyLit, keyOk := key.(literalExpr)
			valLit, valOk := val.(literalExpr)
			if !keyOk || !valOk || keyLit.val.T != ast.String {
				allConst = false
				continue
			}
			switch valLit.val.T {
			case ast.String, ast.Bool, ast.Float, ast.Int, ast.Nil:
				constPairs = append(constPairs, constMapPair{
					key: cast.ToString(keyLit.val.V),
					val: valLit.val.V,
				})
			default:
				allConst = false
			}
		}
		if allConst {
			return constMapExpr{pairs: constPairs}
		}
		return mapExpr{pairs: pairs}
	case ast.TypeIdentifier:
		e := node.Identifier()
		return identifierExpr{name: e.Name, pos: e.Start, slot: c.slot(e.Name)}
	case ast.TypeBoolLiteral:
		return literalExpr{val: V{node.BoolLiteral().Val, ast.Bool}}
	case ast.TypeIntegerLiteral:
		return literalExpr{val: V{node.IntegerLiteral().Val, ast.Int}}
	case ast.TypeFloatLiteral:
		return literalExpr{val: V{node.FloatLiteral().Val, ast.Float}}
	case ast.TypeStringLiteral:
		return literalExpr{val: V{node.StringLiteral().Val, ast.String}}
	case ast.TypeNilLiteral:
		return literalExpr{val: V{nil, ast.Nil}}
	default:
		return fallbackExpr{node: node}
	}
}

type fallbackExpr struct {
	node *ast.Node
}

func (e fallbackExpr) run(ctx *Task) *errchain.PlError {
	return RunExpr(ctx, e.node)
}

type literalExpr struct {
	val V
}

func (e literalExpr) run(ctx *Task) *errchain.PlError {
	ctx.Regs.ReturnOne(e.val)
	return nil
}

func (e literalExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	return e.val, nil
}

type identifierExpr struct {
	name string
	pos  token.LnColPos
	slot int
}

func (e identifierExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.pos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e identifierExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	if v, ok := ctx.slotGetIndex(e.slot); ok {
		return v, nil
	}
	if pos == token.InvalidLnColPos {
		pos = e.pos
	}
	v, err := ctx.GetKey(e.name)
	if err != nil {
		return V{}, NewRunError(ctx, fmt.Sprintf("name `%s` is not defined", e.name), pos)
	}
	return V{v.Value, v.DType}, nil
}

type parenExpr struct {
	expr expr
}

func (e parenExpr) run(ctx *Task) *errchain.PlError {
	return e.expr.run(ctx)
}

func (e parenExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	return evalOne(ctx, e.expr, pos)
}

type unaryExpr struct {
	op    ast.Op
	rhs   expr
	rhsN  *ast.Node
	opPos token.LnColPos
}

func (e unaryExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.opPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e unaryExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	v, err := evalNode(ctx, e.rhs, e.rhsN)
	if err != nil {
		return V{}, err
	}
	switch e.op {
	case ast.SUB, ast.ADD:
		return e.evalSign(ctx, v)
	case ast.NOT:
		return V{!condTrue(v), ast.Bool}, nil
	default:
		return V{}, NewRunError(ctx, fmt.Sprintf("unsupported op for unary expr: %s", e.op), e.opPos)
	}
}

func (e unaryExpr) evalSign(ctx *Task, v V) (V, *errchain.PlError) {
	switch v.T {
	case ast.Bool:
		val := int64(0)
		if cast.ToBool(v.V) {
			val = 1
		}
		if e.op == ast.SUB {
			val = -val
		}
		return V{val, ast.Int}, nil
	case ast.Float:
		val := cast.ToFloat64(v.V)
		if e.op == ast.SUB {
			val = -val
		}
		return V{val, ast.Float}, nil
	case ast.Int:
		val := cast.ToInt64(v.V)
		if e.op == ast.SUB {
			val = -val
		}
		return V{val, ast.Int}, nil
	default:
		return V{}, NewRunError(ctx,
			fmt.Sprintf("unsuppored operand type for unary op %s: %s",
				e.op, v.T), e.opPos)
	}
}

type arithmeticExpr struct {
	lhs   expr
	rhs   expr
	lhsN  *ast.Node
	rhsN  *ast.Node
	op    ast.Op
	opPos token.LnColPos
}

func (e arithmeticExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.opPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e arithmeticExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	lhsVal, err := evalNode(ctx, e.lhs, e.lhsN)
	if err != nil {
		return V{}, err
	}

	rhsVal, err := evalNode(ctx, e.rhs, e.rhsN)
	if err != nil {
		return V{}, err
	}

	if !arithType(lhsVal.T) {
		return V{}, NewRunError(ctx, fmt.Sprintf(
			"unsupported lhs data type: %s", lhsVal.T), e.opPos)
	}

	if !arithType(rhsVal.T) {
		return V{}, NewRunError(ctx, fmt.Sprintf(
			"unsupported rhs data type: %s", rhsVal.T), e.opPos)
	}

	if lhsVal.T == ast.String || rhsVal.T == ast.String {
		if e.op != ast.ADD || lhsVal.T != ast.String || rhsVal.T != ast.String {
			return V{}, NewRunError(ctx, fmt.Sprintf(
				"unsupported operand type(s) for %s: %s and %s",
				e.op, lhsVal.T, rhsVal.T), e.opPos)
		}
		return V{cast.ToString(lhsVal.V) + cast.ToString(rhsVal.V), ast.String}, nil
	}

	if lhsVal.T == ast.Float || rhsVal.T == ast.Float {
		v, dtype, err := arithOpFloat(cast.ToFloat64(lhsVal.V), cast.ToFloat64(rhsVal.V), e.op)
		if err != nil {
			return V{}, NewRunError(ctx, err.Error(), e.opPos)
		}
		return V{v, dtype}, nil
	}

	v, dtype, errOp := arithOpInt(cast.ToInt64(lhsVal.V), cast.ToInt64(rhsVal.V), e.op)
	if errOp != nil {
		return V{}, NewRunError(ctx, errOp.Error(), e.opPos)
	}
	return V{v, dtype}, nil
}

type conditionExpr struct {
	lhs   expr
	rhs   expr
	lhsN  *ast.Node
	rhsN  *ast.Node
	op    ast.Op
	opPos token.LnColPos
}

func (e conditionExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.opPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e conditionExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	lhs, err := evalNode(ctx, e.lhs, e.lhsN)
	if err != nil {
		return V{}, err
	}

	if lhs.T == ast.Bool {
		switch e.op {
		case ast.OR:
			if cast.ToBool(lhs.V) {
				return V{true, ast.Bool}, nil
			}
		case ast.AND:
			if !cast.ToBool(lhs.V) {
				return V{false, ast.Bool}, nil
			}
		}
	}

	rhs, err := evalNode(ctx, e.rhs, e.rhsN)
	if err != nil {
		return V{}, err
	}

	if val, dtype, err := condOp(lhs, rhs, e.op); err != nil {
		return V{}, NewRunError(ctx, err.Error(), e.opPos)
	} else {
		return V{val, dtype}, nil
	}
}

type inExpr struct {
	lhs   expr
	rhs   expr
	lhsN  *ast.Node
	rhsN  *ast.Node
	opPos token.LnColPos
}

type assignExpr struct {
	lhs   []assignTarget
	rhs   []expr
	rhsV  []valueExpr
	rhsN  []*ast.Node
	op    ast.Op
	opPos token.LnColPos
}

type assignTarget struct {
	node *ast.Node
	slot int
	name string
}

func (e assignExpr) run(ctx *Task) *errchain.PlError {
	if len(e.lhs) == 1 && len(e.rhs) == 1 {
		return e.runSingle(ctx)
	}

	lhsCount := len(e.lhs)
	vals := make([]V, 0, len(e.rhs))

	for i, rhs := range e.rhs {
		if e.rhsV[i] != nil {
			v, err := e.rhsV[i].evalValue(ctx, token.InvalidLnColPos)
			if err != nil {
				return err
			}
			vals = append(vals, v)
			continue
		}

		if err := rhs.run(ctx); err != nil {
			return err
		}
		if ctx.Regs.Count() == 1 {
			v, errReg := ctx.Regs.GetRet()
			if errReg != nil {
				return NewRunError(ctx, errReg.Error(), e.rhsN[i].StartPos())
			}
			vals = append(vals, v)
			continue
		}
		v, errReg := ctx.Regs.GetMultiRet()
		if errReg != nil {
			return NewRunError(ctx, errReg.Error(), e.rhsN[i].StartPos())
		}
		if lhsCount == 1 {
			return NewRunError(ctx, "multiple return values", e.rhsN[i].StartPos())
		}
		vals = append(vals, v...)
	}

	if lhsCount != len(vals) {
		return NewRunError(ctx, "the number of left and right operands is not equal", e.opPos)
	}

	for i, lhs := range e.lhs {
		switch e.op {
		case ast.EQ:
			if err := e.assignValue(ctx, lhs, vals[i]); err != nil {
				return err
			}
		case ast.SUBEQ, ast.ADDEQ, ast.MULEQ, ast.DIVEQ, ast.MODEQ:
			if len(vals) != 1 {
				return NewRunError(ctx, "can be only one right value", e.opPos)
			}
			lval, err := evalLValue(ctx, lhs)
			if err != nil {
				return err
			}
			r, err := runAssignArith(ctx, lval, vals[i], e.op, e.opPos)
			if err != nil {
				return err
			}
			if err := e.assignValue(ctx, lhs, r); err != nil {
				return err
			}
		default:
			return NewRunError(ctx, "unsupported op", e.opPos)
		}
	}

	return nil
}

func (e assignExpr) runSingle(ctx *Task) *errchain.PlError {
	var rhs V
	var err *errchain.PlError
	if e.rhsV[0] != nil {
		rhs, err = e.rhsV[0].evalValue(ctx, token.InvalidLnColPos)
	} else {
		rhs, err = evalOne(ctx, e.rhs[0], e.rhsN[0].StartPos())
	}
	if err != nil {
		return err
	}

	lhs := e.lhs[0]
	switch e.op {
	case ast.EQ:
		if lhs.node.NodeType == ast.TypeIdentifier {
			if ctx.slotSetIndex(lhs.slot, rhs) {
				return nil
			}
			ctx.SetVarb(lhs.name, rhs)
			return nil
		}
		return e.assignValue(ctx, lhs, rhs)
	case ast.SUBEQ, ast.ADDEQ, ast.MULEQ, ast.DIVEQ, ast.MODEQ:
		var lval V
		if lhs.node.NodeType == ast.TypeIdentifier {
			var getErr error
			lval, getErr = getValueBySlotOrName(ctx, lhs.slot, lhs.name)
			if getErr != nil {
				return NewRunError(ctx, getErr.Error(), lhs.node.StartPos())
			}
			if r, ok, fastErr := runAssignIntFast(lval, rhs, e.op); ok || fastErr != nil {
				if fastErr != nil {
					return NewRunError(ctx, fastErr.Error(), e.opPos)
				}
				if ctx.slotSetIndex(lhs.slot, r) {
					return nil
				}
				ctx.SetVarb(lhs.name, r)
				return nil
			}
		} else {
			var err *errchain.PlError
			lval, err = evalLValue(ctx, lhs)
			if err != nil {
				return err
			}
		}
		r, err := runAssignArith(ctx, lval, rhs, e.op, e.opPos)
		if err != nil {
			return err
		}
		if lhs.node.NodeType == ast.TypeIdentifier {
			if ctx.slotSetIndex(lhs.slot, r) {
				return nil
			}
			ctx.SetVarb(lhs.name, r)
			return nil
		}
		return e.assignValue(ctx, lhs, r)
	default:
		return NewRunError(ctx, "unsupported op", e.opPos)
	}
}

func runAssignIntFast(l, r V, op ast.Op) (V, bool, error) {
	if l.T != ast.Int || r.T != ast.Int {
		return V{}, false, nil
	}
	lv, lok := toInt64Fast(l.V)
	rv, rok := toInt64Fast(r.V)
	if !lok || !rok {
		return V{}, false, nil
	}
	switch op {
	case ast.ADDEQ:
		return V{lv + rv, ast.Int}, true, nil
	case ast.SUBEQ:
		return V{lv - rv, ast.Int}, true, nil
	case ast.MULEQ:
		return V{lv * rv, ast.Int}, true, nil
	case ast.DIVEQ:
		if rv == 0 {
			return V{}, true, fmt.Errorf("integer division by zero")
		}
		return V{lv / rv, ast.Int}, true, nil
	case ast.MODEQ:
		if rv == 0 {
			return V{}, true, fmt.Errorf("integer modulo by zero")
		}
		return V{lv % rv, ast.Int}, true, nil
	default:
		return V{}, false, nil
	}
}

func (e assignExpr) assignValue(ctx *Task, target assignTarget, val V) *errchain.PlError {
	lhs := target.node
	switch lhs.NodeType {
	case ast.TypeIdentifier:
		if ctx.slotSetIndex(target.slot, val) {
			return nil
		}
		ctx.SetVarb(target.name, val)
		return nil
	case ast.TypeIndexExpr:
		varb, err := getValueBySlotOrName(ctx, target.slot, target.name)
		if err != nil {
			return NewRunError(ctx, err.Error(), lhs.IndexExpr().Obj.Start)
		}
		return changeListOrMapValue(ctx, varb.V, lhs.IndexExpr().Index, val)
	default:
		return NewRunError(ctx, fmt.Sprintf(
			"unsupported lhs type: %s", lhs.NodeType), lhs.StartPos())
	}
}

func evalLValue(ctx *Task, target assignTarget) (V, *errchain.PlError) {
	node := target.node
	switch node.NodeType {
	case ast.TypeIdentifier:
		v, err := getValueBySlotOrName(ctx, target.slot, target.name)
		if err != nil {
			return V{}, NewRunError(ctx, err.Error(), node.StartPos())
		}
		return v, nil
	case ast.TypeIndexExpr:
		if err := RunIndexExprGet(ctx, node.IndexExpr()); err != nil {
			return V{}, err
		}
		v, errReg := ctx.Regs.GetRet()
		if errReg != nil {
			return V{}, NewRunError(ctx, errReg.Error(), node.StartPos())
		}
		return v, nil
	default:
		return V{}, NewRunError(ctx, fmt.Sprintf(
			"unsupported lhs type: %s", node.NodeType), node.StartPos())
	}
}

type compiledCall struct {
	call  *ast.CallExpr
	args  []expr
	argsV []valueExpr
}

type callExpr struct {
	call  *ast.CallExpr
	fn    FnCall
	args  []expr
	argsV []valueExpr
}

func (c *compiler) compileCallExpr(call *ast.CallExpr) callExpr {
	argsSrc := call.ParamNormalized
	if argsSrc == nil {
		argsSrc = call.Param
	}
	args := make([]expr, len(argsSrc))
	argsV := make([]valueExpr, len(argsSrc))
	for i, arg := range argsSrc {
		if arg != nil {
			args[i] = c.compileExpr(arg)
			if v, ok := args[i].(valueExpr); ok {
				argsV[i] = v
			}
		}
	}
	e := callExpr{
		call:  call,
		args:  args,
		argsV: argsV,
	}
	if c.funcs != nil {
		if fn := c.funcs[call.Name]; fn != nil {
			e.fn = fn.Call
		}
	}
	return e
}

func (e callExpr) run(ctx *Task) *errchain.PlError {
	fn := e.fn
	if fn == nil {
		var ok bool
		fn, ok = ctx.GetFn(e.call.Name)
		if !ok {
			return nil
		}
	}

	prev := ctx.call
	frame := ctx.enterCall(e.call, e.args, e.argsV)
	ctx.call = frame
	err := fn(ctx, e.call)
	ctx.call = prev
	ctx.exitCall(frame)
	return err
}

type indexExpr struct {
	obj     *ast.Identifier
	objSlot int
	index   []expr
	indexV  []valueExpr
	indexN  []*ast.Node
}

func (e indexExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.obj.Start)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e indexExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	varb, err := getValueBySlotOrName(ctx, e.objSlot, e.obj.Name)
	if err != nil {
		return V{}, NewRunError(ctx, err.Error(), e.obj.Start)
	}

	switch varb.T {
	case ast.List:
		if _, ok := varb.V.([]any); !ok {
			return V{}, NewRunError(ctx, fmt.Sprintf(
				"unsupported type: %v", reflect.TypeOf(varb.V)), e.obj.Start)
		}
	case ast.Map:
		if _, ok := varb.V.(map[string]any); !ok {
			return V{}, NewRunError(ctx, fmt.Sprintf(
				"unsupported type: %v", reflect.TypeOf(varb.V)), e.obj.Start)
		}
	default:
		return V{}, NewRunError(ctx, fmt.Sprintf(
			"unindexable type: %s", varb.T), e.obj.Start)
	}

	return e.search(ctx, varb.V)
}

func (e indexExpr) search(ctx *Task, obj any) (V, *errchain.PlError) {
	cur := obj
	for i, idxExpr := range e.index {
		var key V
		var err *errchain.PlError
		if e.indexV[i] != nil {
			key, err = e.indexV[i].evalValue(ctx, token.InvalidLnColPos)
		} else {
			key, err = evalOne(ctx, idxExpr, e.indexN[i].StartPos())
		}
		if err != nil {
			return V{}, err
		}
		switch curVal := cur.(type) {
		case map[string]any:
			if key.T != ast.String {
				return V{}, NewRunError(ctx, "key type is not string", e.indexN[i].StartPos())
			}
			var ok bool
			cur, ok = curVal[stringFromValue(key.V)]
			if !ok {
				return V{nil, ast.Nil}, nil
			}
		case []any:
			if key.T != ast.Int {
				return V{}, NewRunError(ctx, "key type is not int", e.indexN[i].StartPos())
			}
			keyInt := intFromValue(key.V)
			if keyInt < 0 {
				keyInt = len(curVal) + keyInt
			}
			if keyInt < 0 || keyInt >= len(curVal) {
				return V{}, NewRunError(ctx, "list index out of range", e.indexN[i].StartPos())
			}
			cur = curVal[keyInt]
		default:
			return V{}, NewRunError(ctx, "not found", e.indexN[i].StartPos())
		}
	}

	v, ok := valueFromAny(cur)
	if !ok {
		return V{nil, ast.Invalid}, nil
	}
	return v, nil
}

func getValueBySlotOrName(ctx *Task, slot int, name string) (V, error) {
	if v, ok := ctx.slotGetIndex(slot); ok {
		return v, nil
	}
	varb, err := ctx.GetKey(name)
	if err != nil {
		return V{}, err
	}
	return V{V: varb.Value, T: varb.DType}, nil
}

type sliceExpr struct {
	obj    expr
	start  expr
	end    expr
	step   expr
	objN   *ast.Node
	startN *ast.Node
	endN   *ast.Node
	stepN  *ast.Node
}

type constSliceExpr struct {
	obj    expr
	objN   *ast.Node
	start  int
	end    int
	step   int
	startN *ast.Node
	endN   *ast.Node
	stepN  *ast.Node
}

func compileConstSliceBounds(start, end, step *ast.Node) (startInt, endInt, stepInt int, ok bool) {
	var has bool
	startInt, has = constOptionalInt(start)
	if !has {
		return 0, 0, 0, false
	}
	endInt, has = constOptionalInt(end)
	if !has {
		return 0, 0, 0, false
	}
	stepInt, has = constOptionalInt(step)
	if !has || stepInt == 0 {
		return 0, 0, 0, false
	}
	return startInt, endInt, stepInt, true
}

func constOptionalInt(node *ast.Node) (int, bool) {
	if node == nil {
		return 0, true
	}
	if node.NodeType != ast.TypeIntegerLiteral {
		return 0, false
	}
	return intFromValue(node.IntegerLiteral().Val), true
}

func (e constSliceExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.objN.StartPos())
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e constSliceExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	obj, err := evalNode(ctx, e.obj, e.objN)
	if err != nil {
		return V{}, err
	}

	var length int
	switch obj.T {
	case ast.String:
		length = len(obj.V.(string))
	case ast.List, ast.DType(ast.TypeSliceExpr):
		length = len(obj.V.([]any))
	default:
		return V{}, NewRunError(ctx, "invalid obj type", e.objN.StartPos())
	}

	startInt, endInt, stepInt := e.start, e.end, e.step
	if e.startN == nil {
		if stepInt > 0 {
			startInt = 0
		} else {
			startInt = length - 1
		}
	} else if startInt < 0 {
		startInt = length + startInt
	}
	if e.endN == nil {
		if stepInt > 0 {
			endInt = length
		} else {
			endInt = -1
		}
	} else if endInt < 0 {
		endInt = length + endInt
	}

	switch obj.T {
	case ast.String:
		return sliceExpr{}.evalString(obj.V.(string), startInt, endInt, stepInt, length), nil
	default:
		return sliceExpr{}.evalList(obj.V.([]any), startInt, endInt, stepInt, length), nil
	}
}

func (e sliceExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.objN.StartPos())
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e sliceExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	obj, err := evalNode(ctx, e.obj, e.objN)
	if err != nil {
		return V{}, err
	}

	start, err := evalOptional(ctx, e.start, e.startN)
	if err != nil {
		return V{}, err
	}
	end, err := evalOptional(ctx, e.end, e.endN)
	if err != nil {
		return V{}, err
	}
	step, err := evalOptional(ctx, e.step, e.stepN)
	if err != nil {
		return V{}, err
	}

	startInt, endInt, stepInt, length, errRun := e.bounds(ctx, obj, start, end, step)
	if errRun != nil {
		return V{}, errRun
	}

	switch obj.T {
	case ast.String:
		return e.evalString(obj.V.(string), startInt, endInt, stepInt, length), nil
	default:
		return e.evalList(obj.V.([]any), startInt, endInt, stepInt, length), nil
	}
}

func (e sliceExpr) bounds(ctx *Task, obj V, start, end, step V) (
	startInt, endInt, stepInt, length int, err *errchain.PlError,
) {
	switch obj.T {
	case ast.String:
		length = len(obj.V.(string))
	case ast.List, ast.DType(ast.TypeSliceExpr):
		length = len(obj.V.([]any))
	default:
		return 0, 0, 0, 0, NewRunError(ctx, "invalid obj type", e.objN.StartPos())
	}

	switch step.T {
	case ast.Invalid:
		stepInt = 1
	case ast.Int:
		stepInt = intFromValue(step.V)
		if stepInt == 0 {
			return 0, 0, 0, 0, NewRunError(ctx, "step must be non-zero", e.stepN.StartPos())
		}
	default:
		return 0, 0, 0, 0, NewRunError(ctx, "step type must be integer", e.stepN.StartPos())
	}

	switch start.T {
	case ast.Invalid:
		if stepInt > 0 {
			startInt = 0
		} else {
			startInt = length - 1
		}
	case ast.Int:
		startInt = intFromValue(start.V)
		if startInt < 0 {
			startInt = length + startInt
		}
	default:
		return 0, 0, 0, 0, NewRunError(ctx, "start type must be integer", e.startN.StartPos())
	}

	switch end.T {
	case ast.Invalid:
		if stepInt > 0 {
			endInt = length
		} else {
			endInt = -1
		}
	case ast.Int:
		endInt = intFromValue(end.V)
		if endInt < 0 {
			endInt = length + endInt
		}
	default:
		return 0, 0, 0, 0, NewRunError(ctx, "end type must be integer", e.endN.StartPos())
	}

	return startInt, endInt, stepInt, length, nil
}

func intFromValue(v any) int {
	switch v := v.(type) {
	case int:
		return v
	case int64:
		return int(v)
	case int32:
		return int(v)
	case int16:
		return int(v)
	case int8:
		return int(v)
	case uint:
		return int(v)
	case uint64:
		return int(v)
	case uint32:
		return int(v)
	case uint16:
		return int(v)
	case uint8:
		return int(v)
	default:
		return cast.ToInt(v)
	}
}

func stringFromValue(v any) string {
	if s, ok := v.(string); ok {
		return s
	}
	return cast.ToString(v)
}

func (e sliceExpr) evalString(str string, startInt, endInt, stepInt, length int) V {
	if v, ok := e.evalSmallString(str, startInt, endInt, stepInt, length); ok {
		return v
	}

	var result strings.Builder
	if stepInt > 0 {
		if n := (endInt - startInt + stepInt - 1) / stepInt; n > 0 {
			result.Grow(n)
		}
		if startInt < 0 {
			startInt = 0
		}
		for i := startInt; i < endInt && i < length; i += stepInt {
			result.WriteByte(str[i])
		}
	} else {
		if startInt > length-1 {
			startInt = length - 1
		}
		if n := (startInt - endInt - stepInt - 1) / (-stepInt); n > 0 {
			result.Grow(n)
		}
		for i := startInt; i > endInt && i >= 0; i += stepInt {
			result.WriteByte(str[i])
		}
	}
	return V{result.String(), ast.String}
}

func (e sliceExpr) evalSmallString(str string, startInt, endInt, stepInt, length int) (V, bool) {
	var buf [64]byte
	n := 0

	if stepInt > 0 {
		if startInt < 0 {
			startInt = 0
		}
		if endInt > length {
			endInt = length
		}
		if startInt >= endInt {
			return V{"", ast.String}, true
		}
		count := (endInt - startInt + stepInt - 1) / stepInt
		if count > len(buf) {
			return V{}, false
		}
		for i := startInt; i < endInt; i += stepInt {
			buf[n] = str[i]
			n++
		}
		return V{string(buf[:n]), ast.String}, true
	}

	if startInt > length-1 {
		startInt = length - 1
	}
	if endInt < -1 {
		endInt = -1
	}
	if startInt <= endInt {
		return V{"", ast.String}, true
	}
	count := (startInt - endInt - stepInt - 1) / (-stepInt)
	if count > len(buf) {
		return V{}, false
	}
	for i := startInt; i > endInt; i += stepInt {
		buf[n] = str[i]
		n++
	}
	return V{string(buf[:n]), ast.String}, true
}

func (e sliceExpr) evalList(list []any, startInt, endInt, stepInt, length int) V {
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
		return V{result, ast.List}
	}

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
	return V{result, ast.List}
}

func (e inExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, e.opPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e inExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	lhs, err := evalNode(ctx, e.lhs, e.lhsN)
	if err != nil {
		return V{}, err
	}

	rhs, err := evalNode(ctx, e.rhs, e.rhsN)
	if err != nil {
		return V{}, err
	}

	switch rhs.T {
	case ast.String:
		if lhs.T != ast.String {
			return V{}, NewRunError(ctx, fmt.Sprintf(
				"unsupported lhs data type: %s", lhs.T), e.opPos)
		}
		return V{strings.Contains(cast.ToString(rhs.V), cast.ToString(lhs.V)), ast.Bool}, nil
	case ast.Map:
		if lhs.T != ast.String {
			return V{}, NewRunError(ctx, fmt.Sprintf(
				"unsupported lhs data type: %s", lhs.T), e.opPos)
		}
		if v, ok := rhs.V.(map[string]any); ok {
			_, ok := v[cast.ToString(lhs.V)]
			return V{ok, ast.Bool}, nil
		}
		return V{false, ast.Bool}, nil
	case ast.List:
		if v, ok := rhs.V.([]any); ok {
			for _, elem := range v {
				if reflect.DeepEqual(lhs.V, elem) {
					return V{true, ast.Bool}, nil
				}
			}
		}
		return V{false, ast.Bool}, nil
	default:
		return V{}, NewRunError(ctx, fmt.Sprintf(
			"unsupported rhs data type: %s", rhs.T), e.opPos)
	}
}

type listExpr struct {
	items []expr
	nodes []*ast.Node
}

type constListExpr struct {
	items []any
}

func (e constListExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, token.InvalidLnColPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e constListExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	ret := make([]any, len(e.items))
	copy(ret, e.items)
	return V{ret, ast.List}, nil
}

func (e listExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, token.InvalidLnColPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e listExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	ret := make([]any, 0, len(e.items))
	for i, item := range e.items {
		val, err := evalNode(ctx, item, e.nodes[i])
		if err != nil {
			return V{}, err
		}
		ret = append(ret, val.V)
	}
	return V{ret, ast.List}, nil
}

type mapPairExpr struct {
	key   expr
	val   expr
	keyN  *ast.Node
	value *ast.Node
}

type mapExpr struct {
	pairs []mapPairExpr
}

type constMapPair struct {
	key string
	val any
}

type constMapExpr struct {
	pairs []constMapPair
}

func (e constMapExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, token.InvalidLnColPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e constMapExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	ret := make(map[string]any, len(e.pairs))
	for _, pair := range e.pairs {
		ret[pair.key] = pair.val
	}
	return V{ret, ast.Map}, nil
}

func (e mapExpr) run(ctx *Task) *errchain.PlError {
	v, err := e.evalValue(ctx, token.InvalidLnColPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnOne(v)
	return nil
}

func (e mapExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	ret := make(map[string]any, len(e.pairs))
	for _, pair := range e.pairs {
		key, err := evalNode(ctx, pair.key, pair.keyN)
		if err != nil {
			return V{}, err
		}
		if key.T != ast.String {
			return V{}, NewRunError(ctx, fmt.Sprintf(
				"unsupported key data type: %s", key.T), pair.keyN.StartPos())
		}

		value, err := evalNode(ctx, pair.val, pair.value)
		if err != nil {
			return V{}, err
		}
		switch value.T {
		case ast.String, ast.Bool, ast.Float, ast.Int,
			ast.Nil, ast.List, ast.Map:
		default:
			return V{}, NewRunError(ctx, fmt.Sprintf(
				"unsupported value data type: %s", value.T), pair.value.StartPos())
		}
		ret[cast.ToString(key.V)] = value.V
	}
	return V{ret, ast.Map}, nil
}

func evalOne(ctx *Task, e expr, pos token.LnColPos) (V, *errchain.PlError) {
	if e, ok := e.(valueExpr); ok {
		return e.evalValue(ctx, pos)
	}
	if err := e.run(ctx); err != nil {
		return V{}, err
	}
	v, errReg := ctx.Regs.GetRet()
	if errReg != nil {
		return V{}, NewRunError(ctx, errReg.Error(), pos)
	}
	return v, nil
}

func evalNode(ctx *Task, e expr, node *ast.Node) (V, *errchain.PlError) {
	if e, ok := e.(valueExpr); ok {
		return e.evalValue(ctx, token.InvalidLnColPos)
	}
	return evalOne(ctx, e, node.StartPos())
}

func evalOptional(ctx *Task, e expr, node *ast.Node) (V, *errchain.PlError) {
	if e == nil {
		return V{T: ast.Invalid}, nil
	}
	return evalNode(ctx, e, node)
}
