package compile

import "github.com/GuanceCloud/platypus/pkg/v2/ast"

func LoopStmts(stmts ast.Stmts) {
	for _, v := range stmts {
		switch v.(type) {
		case *ast.AssignmentExpr:
		case *ast.VarbDefStmt:
		case *ast.FnDefStmt:
		case *ast.IfelseStmt:
		case *ast.ForInStmt:
		case *ast.Identifier:
		case *ast.ArithmeticExpr:
		case *ast.CallExpr:
		case *ast.ContinueStmt:
		case *ast.BreakStmt:
		case *ast.ReturnStmt:
		}

	}
}

func BuildSyms(stmts ast.Stmts) error {

}
