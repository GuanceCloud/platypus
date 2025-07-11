package compile

import (
	"github.com/GuanceCloud/platypus/pkg/v2/ast"
	"github.com/GuanceCloud/platypus/pkg/v2/sym"
)

func getNode(node ast.Node) ast.Node {
	if v, ok := node.(*ast.ParenExpr); ok {
		return getNode(v.Param)
	}
	return node
}

type CContext struct {
	SymTb *sym.SymTable
	Lb    *Labels
}

type Labels struct {
	Pos int
	Lb  map[int]any
}

func (lb *Labels) Insert() int {
	lb.Pos++
	return lb.Pos
}

func NewLBs() *Labels {
	return &Labels{
		Lb: map[int]any{},
	}
}

func NewContext() *CContext {
	return &CContext{
		SymTb: sym.NewSymTable(nil),
		Lb:    NewLBs(),
	}
}

func NewChildContext(ctx *CContext) *CContext {
	sym := sym.NewSymTable(ctx.SymTb)
	return &CContext{
		SymTb: sym,
		Lb:    ctx.Lb,
	}
}
