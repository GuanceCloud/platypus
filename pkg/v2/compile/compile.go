package compile

import (
	"github.com/GuanceCloud/platypus/pkg/v2/ast"
	"github.com/GuanceCloud/platypus/pkg/v2/ir"
)

type Insns struct {
	Insns []*ir.Insn
}

func NewInsns() *Insns {
	return &Insns{
		Insns: make([]*ir.Insn, 0),
	}
}

func Compile(stmts []ast.Node) *Insns {
	ins := NewInsns()

	for _, node := range stmts {
		switch n := node.(type) {
		case *ast.LetStmt:

		}

	}

	return ins
}

func (insns *Insns) CompileIfStmt(stmt *ast.IfelseStmt) {

}
