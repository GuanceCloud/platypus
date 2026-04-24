package runtimev2

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/token"
)

type Program struct {
	ops   []stmtOp
	slots map[string]int
}

func Compile(stmts ast.Stmts) *Program {
	c := &compiler{
		slots: map[string]int{},
	}
	return c.compileProgram(stmts)
}

type compiler struct {
	slots map[string]int
}

func (c *compiler) compileProgram(stmts ast.Stmts) *Program {
	return &Program{
		ops:   c.compileOps(stmts),
		slots: c.slots,
	}
}

func (c *compiler) compileOps(stmts ast.Stmts) []stmtOp {
	ops := make([]stmtOp, 0, len(stmts))
	for _, node := range stmts {
		if node == nil {
			continue
		}
		ops = append(ops, c.compileOp(node))
	}
	return ops
}

func (c *compiler) slot(name string) int {
	if name == "" {
		return -1
	}
	if idx, ok := c.slots[name]; ok {
		return idx
	}
	idx := len(c.slots)
	c.slots[name] = idx
	return idx
}

func (c *compiler) compileOp(node *ast.Node) stmtOp {
	switch node.NodeType {
	case ast.TypeIfelseStmt:
		return c.compileIfElse(node.IfelseStmt())
	case ast.TypeForStmt:
		return c.compileFor(node.ForStmt())
	case ast.TypeForInStmt:
		return c.compileForIn(node.ForInStmt())
	default:
		return stmtOp{kind: stmtExpr, expr: c.compileExpr(node)}
	}
}

func (p *Program) Run(ctx *Task) *errchain.PlError {
	if p == nil {
		return nil
	}
	if ctx.slots == nil && len(p.slots) > 0 {
		ctx.useSlots(p.slots)
	}
	return p.run(ctx)
}

func (p *Program) run(ctx *Task) *errchain.PlError {
	for i := range p.ops {
		op := &p.ops[i]
		var err *errchain.PlError
		switch op.kind {
		case stmtExpr:
			err = op.expr.run(ctx)
		case stmtIfElse:
			err = op.ifOp.run(ctx)
		case stmtFor:
			err = op.forOp.run(ctx)
		case stmtForIn:
			err = op.forInOp.run(ctx)
		}
		if err != nil {
			ctx.procExit = true
			return err
		}

		if ctx.stmtReturnFast() {
			return nil
		}
	}
	return nil
}

func runProgramScoped(ctx *Task, p *Program) *errchain.PlError {
	ctx.StackEnterNew()
	if p == nil {
		ctx.StackExitCur()
		return nil
	}
	err := p.run(ctx)
	ctx.StackExitCur()
	return err
}

type stmtKind uint8

const (
	stmtExpr stmtKind = iota
	stmtIfElse
	stmtFor
	stmtForIn
)

type stmtOp struct {
	kind    stmtKind
	expr    expr
	ifOp    ifElseOp
	forOp   forOp
	forInOp forInOp
}

func (op *stmtOp) run(ctx *Task) *errchain.PlError {
	switch op.kind {
	case stmtExpr:
		return op.expr.run(ctx)
	case stmtIfElse:
		return op.ifOp.run(ctx)
	case stmtFor:
		return op.forOp.run(ctx)
	case stmtForIn:
		return op.forInOp.run(ctx)
	default:
		return nil
	}
}

type ifBlock struct {
	cond  expr
	condV valueExpr
	condN *ast.Node
	body  *Program
}

type ifElseOp struct {
	ifList    []ifBlock
	elseP     *Program
	condScope bool
}

func (c *compiler) compileIfElse(stmt *ast.IfelseStmt) stmtOp {
	ifList := make([]ifBlock, 0, len(stmt.IfList))
	condScope := false
	for _, elem := range stmt.IfList {
		var body *Program
		if elem.Block != nil {
			body = c.compileProgram(elem.Block.Stmts)
		}
		if exprContainsAssignment(elem.Condition) {
			condScope = true
		}
		cond := c.compileExpr(elem.Condition)
		var condV valueExpr
		if v, ok := cond.(valueExpr); ok {
			condV = v
		}
		ifList = append(ifList, ifBlock{
			cond:  cond,
			condV: condV,
			condN: elem.Condition,
			body:  body,
		})
	}

	var elseP *Program
	if stmt.Else != nil {
		elseP = c.compileProgram(stmt.Else.Stmts)
	}

	op := ifElseOp{
		ifList:    ifList,
		elseP:     elseP,
		condScope: condScope,
	}

	return stmtOp{
		kind: stmtIfElse,
		ifOp: op,
	}
}

func (op ifElseOp) run(ctx *Task) *errchain.PlError {
	if op.condScope {
		ctx.StackEnterNew()
	}

	for _, elem := range op.ifList {
		var val V
		if elem.condV != nil {
			var err *errchain.PlError
			val, err = elem.condV.evalValue(ctx, token.InvalidLnColPos)
			if err != nil {
				if op.condScope {
					ctx.StackExitCur()
				}
				return err
			}
		} else {
			if err := elem.cond.run(ctx); err != nil {
				if op.condScope {
					ctx.StackExitCur()
				}
				return err
			}
			v, errReg := ctx.Regs.GetRet()
			if errReg != nil {
				if op.condScope {
					ctx.StackExitCur()
				}
				return NewRunError(ctx, errReg.Error(), elem.condN.StartPos())
			}
			val = v
		}
		if !condTrue(val) {
			continue
		}

		err := runProgramScoped(ctx, elem.body)
		if op.condScope {
			ctx.StackExitCur()
		}
		return err
	}

	if op.elseP != nil {
		err := runProgramScoped(ctx, op.elseP)
		if op.condScope {
			ctx.StackExitCur()
		}
		return err
	}

	if op.condScope {
		ctx.StackExitCur()
	}
	return nil
}

type forOp struct {
	init  expr
	cond  expr
	loop  expr
	condN *ast.Node
	body  *Program
}

func (c *compiler) compileFor(stmt *ast.ForStmt) stmtOp {
	var body *Program
	if stmt.Body != nil {
		body = c.compileProgram(stmt.Body.Stmts)
	}
	return stmtOp{
		kind: stmtFor,
		forOp: forOp{
			init:  c.compileExpr(stmt.Init),
			cond:  c.compileExpr(stmt.Cond),
			loop:  c.compileExpr(stmt.Loop),
			condN: stmt.Cond,
			body:  body,
		},
	}
}

func (op forOp) run(ctx *Task) *errchain.PlError {
	ctx.StackEnterNew()
	defer ctx.StackExitCur()

	if op.init != nil {
		if err := op.init.run(ctx); err != nil {
			return err
		}
	}

	for {
		if op.cond != nil {
			if err := op.cond.run(ctx); err != nil {
				return err
			}
			val, errReg := ctx.Regs.GetRet()
			if errReg != nil {
				return NewRunError(ctx, errReg.Error(), op.condN.StartPos())
			}
			if !condTrue(val) {
				break
			}
		}

		if op.body != nil {
			if err := runProgramScoped(ctx, op.body); err != nil {
				return err
			}
		}

		if ctx.loopBreak {
			ctx.loopBreak = false
			break
		}

		if ctx.loopContinue {
			ctx.loopContinue = false
		}

		if ctx.stmtReturnFast() {
			break
		}

		if op.loop != nil {
			if err := op.loop.run(ctx); err != nil {
				return err
			}
		}
	}

	return nil
}

type forInOp struct {
	varb    *ast.Node
	varSlot int
	iter    expr
	iterV   valueExpr
	iterN   *ast.Node
	body    *Program
}

func (c *compiler) compileForIn(stmt *ast.ForInStmt) stmtOp {
	varSlot := -1
	if stmt.Varb != nil && stmt.Varb.NodeType == ast.TypeIdentifier {
		varSlot = c.slot(stmt.Varb.Identifier().Name)
	}
	var body *Program
	if stmt.Body != nil {
		body = c.compileProgram(stmt.Body.Stmts)
	}
	iter := c.compileExpr(stmt.Iter)
	var iterV valueExpr
	if v, ok := iter.(valueExpr); ok {
		iterV = v
	}
	return stmtOp{
		kind: stmtForIn,
		forInOp: forInOp{
			varb:    stmt.Varb,
			varSlot: varSlot,
			iter:    iter,
			iterV:   iterV,
			iterN:   stmt.Iter,
			body:    body,
		},
	}
}

func (op forInOp) run(ctx *Task) *errchain.PlError {
	ctx.StackEnterNew()

	if op.varb.NodeType != ast.TypeIdentifier {
		ctx.StackExitCur()
		return NewRunError(ctx, fmt.Sprintf("varb node type expect identifier, but %s",
			op.varb.NodeType), op.varb.StartPos())
	}

	var iter V
	if op.iterV != nil {
		var err *errchain.PlError
		iter, err = op.iterV.evalValue(ctx, token.InvalidLnColPos)
		if err != nil {
			ctx.StackExitCur()
			return err
		}
	} else {
		if err := op.iter.run(ctx); err != nil {
			ctx.StackExitCur()
			return err
		}
		v, errReg := ctx.Regs.GetRet()
		if errReg != nil {
			ctx.StackExitCur()
			return NewRunError(ctx, errReg.Error(), op.iterN.StartPos())
		}
		iter = v
	}

	ctx.StackEnterNew()

	switch iter.T {
	case ast.String:
		iter, ok := iter.V.(string)
		if !ok {
			ctx.StackExitCur()
			ctx.StackExitCur()
			return NewRunError(ctx, "inner type error", op.iterN.StartPos())
		}
		for _, x := range iter {
			op.setIterVar(ctx, V{string(x), ast.String})
			if err := op.runBody(ctx); err != nil {
				ctx.StackExitCur()
				ctx.StackExitCur()
				return err
			}
			ctx.stackCur.Clear()
			ctx.slotClearCur()
			if forbreak(ctx) {
				break
			}
			forcontinue(ctx)
			if ctx.stmtReturnFast() {
				break
			}
		}
	case ast.Map:
		iter, ok := iter.V.(map[string]any)
		if !ok {
			ctx.StackExitCur()
			ctx.StackExitCur()
			return NewRunError(ctx, "inner type error", op.iterN.StartPos())
		}
		for x := range iter {
			ctx.stackCur.Clear()
			ctx.slotClearCur()
			op.setIterVar(ctx, V{x, ast.String})
			if err := op.runBody(ctx); err != nil {
				ctx.StackExitCur()
				ctx.StackExitCur()
				return err
			}
			if forbreak(ctx) {
				break
			}
			forcontinue(ctx)
			if ctx.stmtReturnFast() {
				break
			}
		}
	case ast.List:
		iter, ok := iter.V.([]any)
		if !ok {
			ctx.StackExitCur()
			ctx.StackExitCur()
			return NewRunError(ctx, "inner type error", op.iterN.StartPos())
		}
		for _, x := range iter {
			ctx.stackCur.Clear()
			ctx.slotClearCur()
			v, ok := valueFromAny(x)
			if !ok {
				ctx.StackExitCur()
				ctx.StackExitCur()
				return NewRunError(ctx, "inner type error", op.iterN.StartPos())
			}
			op.setIterVar(ctx, v)
			if err := op.runBody(ctx); err != nil {
				ctx.StackExitCur()
				ctx.StackExitCur()
				return err
			}
			if forbreak(ctx) {
				break
			}
			forcontinue(ctx)
			if ctx.stmtReturnFast() {
				break
			}
		}
	default:
		ctx.StackExitCur()
		ctx.StackExitCur()
		return NewRunError(ctx, fmt.Sprintf(
			"unsupported type: %s, not iter value", iter.T), op.iterN.StartPos())
	}

	ctx.StackExitCur()
	ctx.StackExitCur()
	return nil
}

func (op forInOp) setIterVar(ctx *Task, val V) {
	if ctx.slotSetIndex(op.varSlot, val) {
		return
	}
	ctx.SetVarb(op.varb.Identifier().Name, val)
}

func (op forInOp) runBody(ctx *Task) *errchain.PlError {
	if op.body == nil {
		return nil
	}
	return op.body.run(ctx)
}

func exprContainsAssignment(node *ast.Node) bool {
	if node == nil {
		return false
	}
	switch node.NodeType {
	case ast.TypeAssignmentExpr:
		return true
	case ast.TypeParenExpr:
		return exprContainsAssignment(node.ParenExpr().Param)
	case ast.TypeUnaryExpr:
		return exprContainsAssignment(node.UnaryExpr().RHS)
	case ast.TypeArithmeticExpr:
		e := node.ArithmeticExpr()
		return exprContainsAssignment(e.LHS) || exprContainsAssignment(e.RHS)
	case ast.TypeConditionalExpr:
		e := node.ConditionalExpr()
		return exprContainsAssignment(e.LHS) || exprContainsAssignment(e.RHS)
	case ast.TypeInExpr:
		e := node.InExpr()
		return exprContainsAssignment(e.LHS) || exprContainsAssignment(e.RHS)
	case ast.TypeIndexExpr:
		for _, idx := range node.IndexExpr().Index {
			if exprContainsAssignment(idx) {
				return true
			}
		}
	case ast.TypeSliceExpr:
		e := node.SliceExpr()
		return exprContainsAssignment(e.Obj) ||
			exprContainsAssignment(e.Start) ||
			exprContainsAssignment(e.End) ||
			exprContainsAssignment(e.Step)
	case ast.TypeCallExpr:
		return true
	case ast.TypeListLiteral:
		for _, item := range node.ListLiteral().List {
			if exprContainsAssignment(item) {
				return true
			}
		}
	case ast.TypeMapLiteral:
		for _, pair := range node.MapLiteral().KeyValeList {
			if exprContainsAssignment(pair[0]) || exprContainsAssignment(pair[1]) {
				return true
			}
		}
	}
	return false
}
