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
	Tb *sym.Tables
	Lb *Labels
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
		Tb: sym.NewTabels(),
		Lb: NewLBs(),
	}
}

func NewChildContext(ctx *CContext) *CContext {
	return &CContext{
		Tb: ctx.Tb.NextScope(),
		Lb: ctx.Lb,
	}
}
