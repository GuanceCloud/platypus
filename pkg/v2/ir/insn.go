package ir

import "github.com/GuanceCloud/platypus/pkg/ast"

type DebugInfo struct{}

type OP uint8

func (op OP) String() string {
	return ""
}

const (
	OP_NOP    OP = iota
	OP_ADD       // +
	OP_SUB       // -
	OP_MUL       // *
	OP_DIV       // /
	OP_MOD       // %
	OP_EQEQ      // ==
	OP_NE        // !=
	OP_LT        // <
	OP_LE        // <=
	OP_GT        // >
	OP_GE        // >=
	OP_AND       // &&
	OP_OR        // ||
	OP_NOT       // !
	OP_NEG       // -
	OP_ASSIGN    // =
	OP_APPEND    // append
	OP_LEN       // len
	OP_IGET      // index_get
	OP_ISET      // index_set
	OP_CALL      // call
	OP_RET       // ret
	OP_JMP       // jmp

	OP_LOAD  // load
	OP_STORE // store

	OP_LOADG  // load global
	OP_STOREG // store global
)

type Insn struct {
	Op   OP
	Args Args
}

type Args struct {
	Arg1 *Value
	Arg2 *Value
	Arg3 *Value
}

type Value struct {
	Val   any
	DType ast.DType
}

func (v *Value) Value() any {
	return v.Val
}

func (v *Value) Set(val any, typ ast.DType) {
	v.Val = val
	v.DType = typ
}

func (v *Value) Type() ast.DType {
	return v.DType
}
