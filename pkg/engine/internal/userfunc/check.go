// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package userfunc provides validation shared by the runtime implementations.
package userfunc

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
)

// CheckDecl validates a script-defined function declaration and its body.
func CheckDecl(fn *ast.FuncDeclStmt, checkBody func(ast.Stmts) *errchain.PlError,
	file string) *errchain.PlError {
	seen := make(map[string]struct{}, len(fn.Params))
	for _, param := range fn.Params {
		if _, ok := seen[param.Name]; ok {
			return errchain.NewErr(file, param.Start, fmt.Sprintf(
				"function `%s` has duplicate parameter `%s`", fn.Name, param.Name))
		}
		seen[param.Name] = struct{}{}
	}

	if fn.Body == nil {
		return nil
	}
	return checkBody(fn.Body.Stmts)
}

// CheckCall validates arguments passed to a script-defined function.
func CheckCall(fn *ast.FuncDeclStmt, call *ast.CallExpr,
	checkParams func(ast.Stmts) *errchain.PlError, file string) *errchain.PlError {
	if err := checkParams(call.Param); err != nil {
		return err.ChainAppend(file, call.NamePos)
	}
	if len(call.Param) != len(fn.Params) {
		return errchain.NewErr(file, call.NamePos, fmt.Sprintf(
			"function `%s` expects %d arguments, got %d", fn.Name, len(fn.Params), len(call.Param)))
	}
	for _, param := range call.Param {
		if param.NodeType == ast.TypeAssignmentExpr {
			return errchain.NewErr(file, param.StartPos(),
				"script-defined functions only accept positional arguments")
		}
	}
	return nil
}
