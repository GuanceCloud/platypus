package runtimev2

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/token"
	"github.com/spf13/cast"
)

type bcOp uint8

const (
	bcPush bcOp = iota
	bcLoad
	bcUnary
	bcBinary
)

type bcInstr struct {
	op    bcOp
	val   V
	slot  int
	name  string
	pos   token.LnColPos
	astOp ast.Op
}

type bytecodeExpr struct {
	code []bcInstr
}

func (c *compiler) tryCompileBytecode(node *ast.Node) (expr, bool) {
	if node == nil {
		return nil, false
	}
	b := &bytecodeExpr{}
	if !c.compileBytecodeNode(b, node) {
		return nil, false
	}
	return b, true
}

func (c *compiler) compileBytecodeNode(b *bytecodeExpr, node *ast.Node) bool {
	switch node.NodeType {
	case ast.TypeParenExpr:
		return c.compileBytecodeNode(b, node.ParenExpr().Param)
	case ast.TypeIdentifier:
		ident := node.Identifier()
		b.code = append(b.code, bcInstr{
			op:   bcLoad,
			slot: c.slot(ident.Name),
			name: ident.Name,
			pos:  ident.Start,
		})
		return true
	case ast.TypeBoolLiteral:
		b.code = append(b.code, bcInstr{op: bcPush, val: V{node.BoolLiteral().Val, ast.Bool}})
		return true
	case ast.TypeIntegerLiteral:
		b.code = append(b.code, bcInstr{op: bcPush, val: V{node.IntegerLiteral().Val, ast.Int}})
		return true
	case ast.TypeFloatLiteral:
		b.code = append(b.code, bcInstr{op: bcPush, val: V{node.FloatLiteral().Val, ast.Float}})
		return true
	case ast.TypeStringLiteral:
		b.code = append(b.code, bcInstr{op: bcPush, val: V{node.StringLiteral().Val, ast.String}})
		return true
	case ast.TypeNilLiteral:
		b.code = append(b.code, bcInstr{op: bcPush, val: V{nil, ast.Nil}})
		return true
	case ast.TypeUnaryExpr:
		e := node.UnaryExpr()
		if !c.compileBytecodeNode(b, e.RHS) {
			return false
		}
		switch e.Op {
		case ast.ADD, ast.SUB, ast.NOT:
			b.code = append(b.code, bcInstr{op: bcUnary, astOp: e.Op, pos: e.OpPos})
			return true
		default:
			return false
		}
	case ast.TypeArithmeticExpr:
		e := node.ArithmeticExpr()
		if !c.compileBytecodeNode(b, e.LHS) || !c.compileBytecodeNode(b, e.RHS) {
			return false
		}
		b.code = append(b.code, bcInstr{op: bcBinary, astOp: e.Op, pos: e.OpPos})
		return true
	case ast.TypeConditionalExpr:
		e := node.ConditionalExpr()
		if e.Op == ast.AND || e.Op == ast.OR {
			return false
		}
		if !c.compileBytecodeNode(b, e.LHS) || !c.compileBytecodeNode(b, e.RHS) {
			return false
		}
		b.code = append(b.code, bcInstr{op: bcBinary, astOp: e.Op, pos: e.OpPos})
		return true
	default:
		return false
	}
}

func (e *bytecodeExpr) run(ctx *Task) (err *errchain.PlError) {
	v, err := e.evalValue(ctx, token.InvalidLnColPos)
	if err != nil {
		return err
	}
	ctx.Regs.ReturnAppend(v)
	return nil
}

func (e *bytecodeExpr) evalValue(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	if len(e.code) <= 16 {
		return e.evalValueLocal(ctx, pos)
	}

	base := len(ctx.values)

	for i := range e.code {
		instr := &e.code[i]
		switch instr.op {
		case bcPush:
			ctx.values = append(ctx.values, instr.val)
		case bcLoad:
			v, ok := ctx.slotGetIndex(instr.slot)
			if !ok {
				varb, err := ctx.GetKey(instr.name)
				if err != nil {
					ctx.valueResetFrom(base)
					return V{}, NewRunError(ctx, fmt.Sprintf("name `%s` is not defined", instr.name), instr.pos)
				}
				v = V{varb.Value, varb.DType}
			}
			ctx.values = append(ctx.values, v)
		case bcUnary:
			if len(ctx.values) == base {
				ctx.valueResetFrom(base)
				return V{}, NewRunError(ctx, "no return value", instr.pos)
			}
			v := ctx.values[len(ctx.values)-1]
			ret, err := runBCUnary(v, instr.astOp)
			if err != nil {
				ctx.valueResetFrom(base)
				return V{}, NewRunError(ctx, err.Error(), instr.pos)
			}
			ctx.values[len(ctx.values)-1] = ret
		case bcBinary:
			if len(ctx.values)-base < 2 {
				ctx.valueResetFrom(base)
				return V{}, NewRunError(ctx, "no return value", instr.pos)
			}
			r := ctx.values[len(ctx.values)-1]
			l := ctx.values[len(ctx.values)-2]
			ctx.values[len(ctx.values)-1] = V{}
			ctx.values = ctx.values[:len(ctx.values)-1]
			ret, err := runBCBinary(l, r, instr.astOp)
			if err != nil {
				ctx.valueResetFrom(base)
				return V{}, NewRunError(ctx, err.Error(), instr.pos)
			}
			ctx.values[len(ctx.values)-1] = ret
		}
	}

	if len(ctx.values)-base != 1 {
		ctx.valueResetFrom(base)
		return V{}, NewRunError(ctx, "no return value", pos)
	}
	ret := ctx.values[base]
	ctx.valueResetFrom(base)
	return ret, nil
}

func (e *bytecodeExpr) evalValueLocal(ctx *Task, pos token.LnColPos) (V, *errchain.PlError) {
	var stack [16]V
	sp := 0

	for i := range e.code {
		instr := &e.code[i]
		switch instr.op {
		case bcPush:
			stack[sp] = instr.val
			sp++
		case bcLoad:
			v, ok := ctx.slotGetIndex(instr.slot)
			if !ok {
				varb, err := ctx.GetKey(instr.name)
				if err != nil {
					return V{}, NewRunError(ctx, fmt.Sprintf("name `%s` is not defined", instr.name), instr.pos)
				}
				v = V{varb.Value, varb.DType}
			}
			stack[sp] = v
			sp++
		case bcUnary:
			if sp == 0 {
				return V{}, NewRunError(ctx, "no return value", instr.pos)
			}
			ret, err := runBCUnary(stack[sp-1], instr.astOp)
			if err != nil {
				return V{}, NewRunError(ctx, err.Error(), instr.pos)
			}
			stack[sp-1] = ret
		case bcBinary:
			if sp < 2 {
				return V{}, NewRunError(ctx, "no return value", instr.pos)
			}
			r := stack[sp-1]
			l := stack[sp-2]
			stack[sp-1] = V{}
			sp--
			ret, err := runBCBinary(l, r, instr.astOp)
			if err != nil {
				return V{}, NewRunError(ctx, err.Error(), instr.pos)
			}
			stack[sp-1] = ret
		}
	}

	if sp != 1 {
		return V{}, NewRunError(ctx, "no return value", pos)
	}
	return stack[0], nil
}

func runBCUnary(v V, op ast.Op) (V, error) {
	switch op {
	case ast.NOT:
		return V{!condTrue(v), ast.Bool}, nil
	case ast.ADD, ast.SUB:
		switch v.T {
		case ast.Bool:
			val := int64(0)
			if cast.ToBool(v.V) {
				val = 1
			}
			if op == ast.SUB {
				val = -val
			}
			return V{val, ast.Int}, nil
		case ast.Float:
			val := cast.ToFloat64(v.V)
			if op == ast.SUB {
				val = -val
			}
			return V{val, ast.Float}, nil
		case ast.Int:
			val := cast.ToInt64(v.V)
			if op == ast.SUB {
				val = -val
			}
			return V{val, ast.Int}, nil
		default:
			return V{}, fmt.Errorf("unsuppored operand type for unary op %s: %s", op, v.T)
		}
	default:
		return V{}, fmt.Errorf("unsupported op for unary expr: %s", op)
	}
}

func runBCBinary(lhs, rhs V, op ast.Op) (V, error) {
	switch op {
	case ast.ADD, ast.SUB, ast.MUL, ast.DIV, ast.MOD:
		return runBCArithmetic(lhs, rhs, op)
	default:
		if lhs.T == ast.Int && rhs.T == ast.Int {
			if ret, ok, err := runBCIntCompare(lhs.V, rhs.V, op); ok || err != nil {
				return ret, err
			}
		}
		val, dtype, err := condOp(lhs, rhs, op)
		if err != nil {
			return V{}, err
		}
		return V{val, dtype}, nil
	}
}

func runBCArithmetic(lhs, rhs V, op ast.Op) (V, error) {
	if !arithType(lhs.T) {
		return V{}, fmt.Errorf("unsupported lhs data type: %s", lhs.T)
	}
	if !arithType(rhs.T) {
		return V{}, fmt.Errorf("unsupported rhs data type: %s", rhs.T)
	}

	if lhs.T == ast.String || rhs.T == ast.String {
		if op != ast.ADD || lhs.T != ast.String || rhs.T != ast.String {
			return V{}, fmt.Errorf("unsupported operand type(s) for %s: %s and %s", op, lhs.T, rhs.T)
		}
		return V{cast.ToString(lhs.V) + cast.ToString(rhs.V), ast.String}, nil
	}

	if lhs.T == ast.Int && rhs.T == ast.Int {
		l, lok := toInt64Fast(lhs.V)
		r, rok := toInt64Fast(rhs.V)
		if lok && rok {
			v, dtype, err := arithOpInt(l, r, op)
			if err != nil {
				return V{}, err
			}
			return V{v, dtype}, nil
		}
	}

	if lhs.T == ast.Float || rhs.T == ast.Float {
		v, dtype, err := arithOpFloat(cast.ToFloat64(lhs.V), cast.ToFloat64(rhs.V), op)
		if err != nil {
			return V{}, err
		}
		return V{v, dtype}, nil
	}

	v, dtype, err := arithOpInt(cast.ToInt64(lhs.V), cast.ToInt64(rhs.V), op)
	if err != nil {
		return V{}, err
	}
	return V{v, dtype}, nil
}

func runBCIntCompare(lhs, rhs any, op ast.Op) (V, bool, error) {
	l, lok := toInt64Fast(lhs)
	r, rok := toInt64Fast(rhs)
	if !lok || !rok {
		return V{}, false, nil
	}
	switch op {
	case ast.EQEQ:
		return V{l == r, ast.Bool}, true, nil
	case ast.NEQ:
		return V{l != r, ast.Bool}, true, nil
	case ast.LT:
		return V{l < r, ast.Bool}, true, nil
	case ast.LTE:
		return V{l <= r, ast.Bool}, true, nil
	case ast.GT:
		return V{l > r, ast.Bool}, true, nil
	case ast.GTE:
		return V{l >= r, ast.Bool}, true, nil
	default:
		return V{}, false, nil
	}
}

func toInt64Fast(v any) (int64, bool) {
	switch v := v.(type) {
	case int64:
		return v, true
	case int:
		return int64(v), true
	case int32:
		return int64(v), true
	case int16:
		return int64(v), true
	case int8:
		return int64(v), true
	case uint:
		return int64(v), true
	case uint64:
		if v <= uint64(^uint64(0)>>1) {
			return int64(v), true
		}
	case uint32:
		return int64(v), true
	case uint16:
		return int64(v), true
	case uint8:
		return int64(v), true
	}
	return 0, false
}
