package compile

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/v2/ast"
	"github.com/GuanceCloud/platypus/pkg/v2/sym"
)

func BuildSyms(ctx *CContext, stmts ast.Stmts) error {
	for _, stmt := range stmts {
		if err := LStmt(ctx, stmt); err != nil {
			return err
		}
	}

	return nil
}

func LStmt(ctx *CContext, node ast.Node) error {
	switch v := node.(type) {
	case *ast.AssignmentStmt:
		return LAssign(ctx, v)
	case *ast.LetStmt:
		return LLetDef(ctx, v)
	case *ast.FnDefStmt:
		return LFuncDefStmt(ctx, v)
	case *ast.IfelseStmt:
		return LIf(ctx, v)
	case *ast.ForInStmt:
	case *ast.ForStmt:
		return LFor(ctx, v)
	case *ast.BlockStmt:
		return LBlock(ctx, v)
	case *ast.ParenExpr:
		return LStmt(ctx, v.Param)
	default:
	}

	return nil
}

func LLetDef(ctx *CContext, stmt *ast.LetStmt) error {
	tb := ctx.SymTb
	name := stmt.Name.Name
	_, ok := tb.Get(name)
	if ok {
		return fmt.Errorf("sym exists")
	}

	var tp sym.Type = &sym.TypAny{}

	if stmt.Type != nil {
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
				tp = sym.Int
			case ast.Float:
				tp = sym.Float
			case ast.Bool:
				tp = sym.Bool
			case ast.String:
				tp = sym.Str
			case ast.Any:
				tp = sym.Any
			}
		case *ast.TypeAny:
			tp = sym.Any
		default:
			return fmt.Errorf("unsuppored type")
		}
	} else {
		tp = sym.Any
	}

	if !tb.Add(name, &sym.Sym{
		Name: name,
		Type: tp,
	}) {
		return fmt.Errorf("sym exists")
	}

	return nil
}

func LBlock(ctx *CContext, stmt *ast.BlockStmt) error {
	ctx = NewChildContext(ctx)
	stmt.Label = ctx.Lb.Insert()
	stmt.SymTb = ctx.SymTb

	return BuildSyms(ctx, stmt.Stmts)
}

func LAssign(ctx *CContext, stmt *ast.AssignmentStmt) error {
	tb := ctx.SymTb
	lhs := stmt.LHS
	rhs := stmt.RHS

	for i := range rhs {
		if err := LStmt(ctx, rhs[i]); err != nil {
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
			if err := LStmt(ctx, rhs[i]); err != nil {
				return err
			}
		case *ast.AttrExpr:
			if err := LStmt(ctx, rhs[i]); err != nil {
				return err
			}
		default:
			return fmt.Errorf("unsuppored lhs type")
		}
	}

	return nil
}

func LIf(ctx *CContext, stmt *ast.IfelseStmt) error {
	for _, v := range stmt.IfList {
		if err := LStmt(ctx, v.Block); err != nil {
			return err
		}
	}

	if stmt.Else != nil {
		if err := LStmt(ctx, stmt.Else); err != nil {
			return err
		}
	}

	return nil
}

func LForIn(ctx *CContext, stmt *ast.ForInStmt) error {

}

func LFor(ctx *CContext, stmt *ast.ForStmt) error {
	ctx = NewChildContext(ctx)
	stmt.SymTb = ctx.SymTb
	stmt.Label = ctx.Lb.Insert()

	if err := LStmt(ctx, stmt.Init); err != nil {
		return err
	}
	if err := LStmt(ctx, stmt.Cond); err != nil {
		return err
	}

	if err := LStmt(ctx, stmt.Body); err != nil {
		return err
	}

	return nil
}

func LFuncDefStmt(ctx *CContext, stmt *ast.FnDefStmt) error {
	nameNode, ok := getNode(stmt.Name).(*ast.Identifier)
	if !ok {
		return fmt.Errorf("unsuppored node type")
	}

	name := nameNode.String()

	fn := sym.TypFunc{}

	newCtx := NewChildContext(ctx)
	stmt.Label = ctx.Lb.Insert()
	stmt.SymTb = newCtx.SymTb
	for _, v := range stmt.FnType.Params {
		p := &sym.Param{}
		if v.DType != nil {
			typ, err := getType(getNode(v.DType))
			if err != nil {
				return err
			}
			p.Type = typ
		} else {
			p.Type = sym.Any
		}
		p.IsVarb = v.Varb
		fn.Params = append(fn.Params, p)
		if name, ok := v.Name.(*ast.Identifier); ok {
			newCtx.SymTb.Add(name.String(), &sym.Sym{
				Name: name.String(),
				Type: p.Type,
			})
		} else {
			return fmt.Errorf("unsupported node type")
		}
	}

	for _, v := range stmt.FnType.Results {
		typ, err := getType(getNode(v))
		if err != nil {
			return err
		}
		fn.Returns = append(fn.Returns, typ)
	}

	ctx.SymTb.Add(name, &sym.Sym{
		Name: name,
		Type: fn,
	})

	return LStmt(newCtx, stmt.Block)
}

func getType(node ast.Node) (sym.Type, error) {
	switch v := node.(type) {
	case *ast.TypeBasic:
		switch v.DType {
		case ast.Any:
			return sym.Any, nil
		case ast.Int:
			return sym.Int, nil
		case ast.Bool:
			return sym.Bool, nil
		case ast.Float:
			return sym.Float, nil
		case ast.String:
			return sym.Str, nil
		default:
			return nil, fmt.Errorf("unsupported type")
		}
	case *ast.TypeList:
		return sym.NewListTyp(sym.Any), nil
	case *ast.TypeMap:
		return sym.NewMapTyp(), nil
	case *ast.TypeAny:
		return sym.Any, nil
	default:
		return nil, fmt.Errorf("unsupported type")
	}
}
