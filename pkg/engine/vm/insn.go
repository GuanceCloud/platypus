package vm

type OPCode int

const (
	OP_NOP OPCode = iota

	OP_ST
	OP_LD

	OP_ADD
	OP_SUB
	OP_MUL
	OP_DIV
	OP_MOD
	OP_UNM // unary minus

	OP_AND
	OP_OR
	OP_NOT

	OP_EQ
	OP_NEQ
	OP_LT
	OP_LTE
	OP_GT
	OP_GTE
	OP_LEN

	OP_GET
	OP_SET
	OP_APPEND

	OP_JMP
	OP_JMP_IF

	OP_CALL
	OP_RET
)
