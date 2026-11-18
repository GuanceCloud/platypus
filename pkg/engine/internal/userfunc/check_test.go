// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package userfunc

import (
	"strings"
	"testing"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/token"
)

func TestCheckDecl(t *testing.T) {
	paramPos := token.LnColPos{Pos: 12, Ln: 1, Col: 13}
	duplicate := &ast.FuncDeclStmt{
		Name: "add",
		Params: []*ast.Identifier{
			{Name: "value"},
			{Name: "value", Start: paramPos},
		},
	}
	if err := CheckDecl(duplicate, nil, "test.p"); err == nil ||
		!strings.Contains(err.Error(), "duplicate parameter `value`") {
		t.Fatalf("expected duplicate parameter error, got %v", err)
	}

	checked := false
	valid := &ast.FuncDeclStmt{
		Name: "identity",
		Body: &ast.BlockStmt{Stmts: ast.Stmts{ast.WrapNilLiteral(&ast.NilLiteral{})}},
	}
	if err := CheckDecl(valid, func(stmts ast.Stmts) *errchain.PlError {
		checked = len(stmts) == 1
		return nil
	}, "test.p"); err != nil {
		t.Fatalf("unexpected declaration error: %v", err)
	}
	if !checked {
		t.Fatal("function body was not checked")
	}
}

func TestCheckCall(t *testing.T) {
	fn := &ast.FuncDeclStmt{Name: "identity", Params: []*ast.Identifier{{Name: "value"}}}
	callPos := token.LnColPos{Pos: 20, Ln: 2, Col: 3}
	call := &ast.CallExpr{
		Name:    fn.Name,
		NamePos: callPos,
		Param:   ast.Stmts{ast.WrapNilLiteral(&ast.NilLiteral{})},
	}
	if err := CheckCall(fn, call, func(ast.Stmts) *errchain.PlError {
		return nil
	}, "test.p"); err != nil {
		t.Fatalf("unexpected call error: %v", err)
	}

	call.Param = nil
	if err := CheckCall(fn, call, func(ast.Stmts) *errchain.PlError {
		return nil
	}, "test.p"); err == nil || !strings.Contains(err.Error(), "expects 1 arguments, got 0") {
		t.Fatalf("expected argument count error, got %v", err)
	}

	call.Param = ast.Stmts{ast.WrapAssignmentStmt(&ast.AssignmentExpr{
		LHS: ast.Stmts{ast.WrapIdentifier(&ast.Identifier{Name: "value"})},
	})}
	if err := CheckCall(fn, call, func(ast.Stmts) *errchain.PlError {
		return nil
	}, "test.p"); err == nil || !strings.Contains(err.Error(), "only accept positional arguments") {
		t.Fatalf("expected positional argument error, got %v", err)
	}
}

func TestCheckCallAppendsCallPosition(t *testing.T) {
	callPos := token.LnColPos{Pos: 20, Ln: 2, Col: 3}
	call := &ast.CallExpr{Name: "identity", NamePos: callPos}
	fn := &ast.FuncDeclStmt{Name: call.Name}
	err := CheckCall(fn, call, func(ast.Stmts) *errchain.PlError {
		return errchain.NewErr("test.p", token.LnColPos{Ln: 1, Col: 1}, "bad argument")
	}, "test.p")
	if err == nil || len(err.PosChain) != 2 || err.PosChain[1].Pos != int(callPos.Pos) {
		t.Fatalf("expected call position in error chain, got %#v", err)
	}
}
