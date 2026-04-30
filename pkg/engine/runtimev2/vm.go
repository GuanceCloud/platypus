package runtimev2

import (
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/token"
)

type vmOp uint8

const (
	vmExpr vmOp = iota
	vmJump
	vmJumpIfFalse
	vmScopeEnter
	vmScopeExit
)

type vmInstr struct {
	op     vmOp
	expr   expr
	exprV  valueExpr
	condN  token.LnColPos
	target int
}

func compileVM(ops []stmtOp) ([]vmInstr, bool) {
	code := make([]vmInstr, 0, len(ops))
	for i := range ops {
		if !appendVMOp(&code, &ops[i]) {
			return nil, false
		}
	}
	return code, true
}

func appendVMOp(code *[]vmInstr, op *stmtOp) bool {
	switch op.kind {
	case stmtExpr:
		var exprV valueExpr
		if v, ok := op.expr.(valueExpr); ok {
			exprV = v
		}
		*code = append(*code, vmInstr{op: vmExpr, expr: op.expr, exprV: exprV})
		return true
	case stmtIfElse:
		return appendVMIfElse(code, op.ifOp)
	default:
		return false
	}
}

func appendVMIfElse(code *[]vmInstr, op ifElseOp) bool {
	if op.condScope {
		return false
	}

	endJumps := make([]int, 0, len(op.ifList))
	for _, elem := range op.ifList {
		jumpIfFalse := len(*code)
		condPos := token.InvalidLnColPos
		if elem.condN != nil {
			condPos = elem.condN.StartPos()
		}
		*code = append(*code, vmInstr{
			op:    vmJumpIfFalse,
			expr:  elem.cond,
			exprV: elem.condV,
			condN: condPos,
		})

		if elem.body != nil && elem.body.needsScope {
			*code = append(*code, vmInstr{op: vmScopeEnter})
		}
		if elem.body != nil {
			for i := range elem.body.ops {
				if !appendVMOp(code, &elem.body.ops[i]) {
					return false
				}
			}
		}
		if elem.body != nil && elem.body.needsScope {
			*code = append(*code, vmInstr{op: vmScopeExit})
		}

		endJumps = append(endJumps, len(*code))
		*code = append(*code, vmInstr{op: vmJump})
		(*code)[jumpIfFalse].target = len(*code)
	}

	if op.elseP != nil {
		if op.elseP.needsScope {
			*code = append(*code, vmInstr{op: vmScopeEnter})
		}
		for i := range op.elseP.ops {
			if !appendVMOp(code, &op.elseP.ops[i]) {
				return false
			}
		}
		if op.elseP.needsScope {
			*code = append(*code, vmInstr{op: vmScopeExit})
		}
	}

	end := len(*code)
	for _, idx := range endJumps {
		(*code)[idx].target = end
	}
	return true
}

func (p *Program) runVM(ctx *Task) *errchain.PlError {
	scopeDepth := 0
	for pc := 0; pc < len(p.code); pc++ {
		instr := &p.code[pc]
		var err *errchain.PlError
		switch instr.op {
		case vmExpr:
			err = instr.expr.run(ctx)
		case vmJump:
			pc = instr.target - 1
		case vmJumpIfFalse:
			var val V
			if instr.exprV != nil {
				val, err = instr.exprV.evalValue(ctx, token.InvalidLnColPos)
			} else {
				err = instr.expr.run(ctx)
				if err == nil {
					var errReg error
					val, errReg = ctx.Regs.GetRet()
					if errReg != nil {
						err = NewRunError(ctx, errReg.Error(), instr.condN)
					}
				}
			}
			if err == nil && !condTrue(val) {
				pc = instr.target - 1
			}
		case vmScopeEnter:
			ctx.StackEnterNew()
			scopeDepth++
		case vmScopeExit:
			ctx.StackExitCur()
			scopeDepth--
		}
		if err != nil {
			for ; scopeDepth > 0; scopeDepth-- {
				ctx.StackExitCur()
			}
			ctx.procExit = true
			return err
		}
		if ctx.stmtReturnFast() {
			for ; scopeDepth > 0; scopeDepth-- {
				ctx.StackExitCur()
			}
			return nil
		}
	}
	return nil
}
