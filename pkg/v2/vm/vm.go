package vm

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/v2/ir"
)

type Task struct {
	Insns []*ir.Insn
	Regs  Regs
}

type Regs struct {
	cur int
}

func Run(task *Task) error {
	return nil
}

func Nop(task *Task) error {
	return nil
}

func Add(task *Task, insn *ir.Insn) error {
	l := insn.Args.Arg2
	r := insn.Args.Arg3

	switch l.DType {
	case ast.String:
		if r.DType != ast.String {
			return fmt.Errorf("unsupported operand type(s) for +: %s and %s", l.DType, r.DType)
		}
		if insn.Op != ir.OP_ADD {
			return fmt.Errorf("unsupported op %s for string", insn.Op)
		}
		insn.Args.Arg1.Set(l.Val.(string)+r.Val.(string), ast.String)
	case ast.Int:
		switch r.DType {
		case ast.Int:
			v, err := intOp(insn.Op, l.Val.(int64), r.Val.(int64))
			if err != nil {
				return err
			}
			insn.Args.Arg1.Set(v, ast.Int)
		case ast.Float:
			v, err := floatOp(insn.Op, float64(l.Val.(int64)), r.Val.(float64))
			if err != nil {
				return err
			}
			insn.Args.Arg1.Set(v, ast.Float)
		case ast.Bool:
			var rV int64
			if r.Val.(bool) {
				rV = 1
			}
			if v, err := intOp(insn.Op, l.Val.(int64), rV); err != nil {
				return err
			} else {
				insn.Args.Arg1.Set(v, ast.Int)
			}
		default:
			return fmt.Errorf("unsupported operand type(s) for +: %s and %s", l.DType, r.DType)
		}
	case ast.Float:
		switch r.DType {
		case ast.Int:
			v, err := floatOp(insn.Op, l.Val.(float64), float64(r.Val.(int64)))
			if err != nil {
				return err
			}
			insn.Args.Arg1.Set(v, ast.Float)
		case ast.Float:
			v, err := floatOp(insn.Op, l.Val.(float64), r.Val.(float64))
			if err != nil {
				return err
			}
			insn.Args.Arg1.Set(v, ast.Float)
		case ast.Bool:
			var rV float64
			if r.Val.(bool) {
				rV = 1
			}
			if v, err := floatOp(insn.Op, l.Val.(float64), rV); err != nil {
				return err
			} else {
				insn.Args.Arg1.Set(v, ast.Float)
			}

		default:
			return fmt.Errorf("unsupported operand type(s) for +: %s and %s", l.DType, r.DType)
		}
	case ast.Bool:
		switch r.DType {
		case ast.Int:
			var lv int64
			if l.Val.(bool) {
				lv = 1
			}
			if v, err := intOp(insn.Op, lv, r.Val.(int64)); err != nil {
				return err
			} else {
				insn.Args.Arg1.Set(v, ast.Int)
			}
		case ast.Float:
			var lv float64
			if l.Val.(bool) {
				lv = 1
			}
			if v, err := floatOp(insn.Op, lv, r.Val.(float64)); err != nil {
				return err
			} else {
				insn.Args.Arg1.Set(v, ast.Float)
			}
		case ast.Bool:
			v, err := boolOp(insn.Op, l.Val.(bool), r.Val.(bool))
			if err != nil {
				return err
			}
			insn.Args.Arg1.Set(v, ast.Bool)
		default:
			return fmt.Errorf("unsupported operand type(s) for +: %s and %s", l.DType, r.DType)
		}
	default:
		return fmt.Errorf("unsupported operand type(s) for +: %s and %s", l.DType, r.DType)
	}

	return nil
}
