package compile

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/v2/ast"
	"github.com/GuanceCloud/platypus/pkg/v2/sym"
)

type Context struct {
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

func NewContext() *Context {
	return &Context{
		SymTb: sym.NewSymTable(),
		Lb:    NewLBs(),
	}
}

func NewChildContext(ctx *Context) *Context {
	sym := sym.NewSymTable()
	sym.SetParent(ctx.SymTb)
	return &Context{
		SymTb: sym,
		Lb:    ctx.Lb,
	}
}

func BuildSyms(ctx *Context, stmts ast.Stmts) error {
	for _, stmt := range stmts {
		if err := LoopStmt(ctx, stmt); err != nil {
			return err
		}
	}

	return nil
}

func LoopStmt(ctx *Context, node ast.Node) error {
	switch v := node.(type) {
	case *ast.AssignmentStmt:
		return LAssign(ctx, v)
	case *ast.LetStmt:
	case *ast.FnDefStmt:
	case *ast.IfelseStmt:
		return LIf(ctx, v)
	case *ast.ForInStmt:
	case *ast.Identifier:
	case *ast.ArithmeticExpr:
	case *ast.CallExpr:
	case *ast.ContinueStmt:
	case *ast.BreakStmt:
	case *ast.ReturnStmt:
	case *ast.ParenExpr:
		return LoopStmt(ctx, v.Param)
	default:
		// return fmt.Errorf("unspported node type")
	}

	return nil
}

func LLetDef(ctx *Context, stmt *ast.LetStmt) error {
	tb := ctx.SymTb
	name := stmt.Name.Name
	_, ok := tb.Get(name)
	if ok {
		return fmt.Errorf("sym exists")
	}

	var tp sym.Type = &sym.TypAny{}

	switch v := stmt.Type.(type) {
	case *ast.TypeMap:
		tp = &sym.TypMap{
			Key:   &sym.TypString{},
			Value: &sym.TypAny{},
		}
	case *ast.TypeList:
		tp = &sym.TypList{
			Elem: &sym.TypAny{},
		}
	case *ast.TypeBasic:
		switch v.DType {
		case ast.Int:
			tp = &sym.TypInt{}
		case ast.Float:
			tp = &sym.TypFloat{}
		case ast.Bool:
			tp = &sym.TypBool{}
		case ast.String:
			tp = &sym.TypString{}
		}
	default:
		return fmt.Errorf("unsuppored type")
	}

	if !tb.Add(name, &sym.Sym{
		Name: name,
		Type: tp,
	}) {
		return fmt.Errorf("sym exists")
	}

	return nil
}

func LAssign(ctx *Context, stmt *ast.AssignmentStmt) error {
	tb := ctx.SymTb
	lhs := stmt.LHS
	rhs := stmt.RHS

	for i := range rhs {
		if err := LoopStmt(ctx, rhs[i]); err != nil {
			return err
		}
	}

	for i := range lhs {
		node := getNode(lhs[i])
		switch node := node.(type) {
		case *ast.Identifier:
			name := node.Name
			if _, ok := tb.Get(name); !ok {
				tb.Add(name, &sym.Sym{
					Name: name,
					Type: &sym.TypAny{},
				})
			}
		case *ast.IndexExpr:
			if err := LoopStmt(ctx, rhs[i]); err != nil {
				return err
			}
		case *ast.AttrExpr:
			if err := LoopStmt(ctx, rhs[i]); err != nil {
				return err
			}
		default:
			return fmt.Errorf("unsuppored lhs type")
		}
	}

	return nil
}

func LIf(ctx *Context, stmt *ast.IfelseStmt) error {
	for _, v := range stmt.IfList {
		v.Block.Label = ctx.Lb.Insert()
		ctx := NewChildContext(ctx)
		if err := BuildSyms(ctx, v.Block.Stmts); err != nil {
			return err
		}
	}

	if stmt.Else != nil {
		stmt.Else.Label = ctx.Lb.Insert()
		if err := BuildSyms(ctx, stmt.Else.Stmts); err != nil {
			return err
		}
	}

	return nil
}

func getNode(node ast.Node) ast.Node {
	if v, ok := node.(*ast.ParenExpr); ok {
		return getNode(v.Param)
	}
	return node
}
