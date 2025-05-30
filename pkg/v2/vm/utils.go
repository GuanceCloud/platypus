package vm

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/v2/ir"
)

func floatOp(op ir.OP, l, r float64) (float64, error) {
	switch op {
	case ir.OP_ADD:
		return l + r, nil
	case ir.OP_SUB:
		return l - r, nil
	case ir.OP_MUL:
		return l * r, nil
	case ir.OP_DIV:
		if r == 0 {
			return 0, fmt.Errorf("float division by zero")
		}
		return l / r, nil
	}

	return 0, fmt.Errorf("unsupported op %s for float", op)
}

func intOp(op ir.OP, l, r int64) (int64, error) {
	switch op {
	case ir.OP_ADD:
		return l + r, nil
	case ir.OP_SUB:
		return l - r, nil
	case ir.OP_MUL:
		return l * r, nil
	case ir.OP_DIV:
		if r == 0 {
			return 0, fmt.Errorf("integer division by zero")
		}
		return l / r, nil
	}

	return 0, fmt.Errorf("unsupported op %s for integer", op)
}

func boolOp(op ir.OP, l, r bool) (bool, error) {
	switch op {
	case ir.OP_ADD:
		return l && r, nil

	}

	return false, fmt.Errorf("unsupported op %s for bool", op)
}
