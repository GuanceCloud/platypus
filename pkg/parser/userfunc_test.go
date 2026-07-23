// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package parser

import (
	"testing"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/stretchr/testify/require"
)

func TestParseUserDefinedFunction(t *testing.T) {
	stmts, err := ParsePipeline("test.p", `
fn classify(code, fallback) {
    if code >= 500 {
        return "error"
    }
    return fallback
}
level = classify(status, "info")
`)
	require.NoError(t, err)
	require.Len(t, stmts, 2)
	require.Equal(t, ast.TypeFuncDeclStmt, stmts[0].NodeType)

	fn := stmts[0].FuncDeclStmt()
	require.Equal(t, "classify", fn.Name)
	require.Len(t, fn.Params, 2)
	require.Equal(t, "code", fn.Params[0].Name)
	require.Equal(t, "fallback", fn.Params[1].Name)
	require.Len(t, fn.Body.Stmts, 2)
	require.Equal(t, ast.TypeReturnStmt, fn.Body.Stmts[1].NodeType)
}

func TestParseEmptyReturnInFunctionWithoutParameters(t *testing.T) {
	stmts, err := ParsePipeline("test.p", `
fn stop() {
    return
}
stop()
`)
	require.NoError(t, err)
	require.Len(t, stmts, 2)
	require.Empty(t, stmts[0].FuncDeclStmt().Params)
	require.Nil(t, stmts[0].FuncDeclStmt().Body.Stmts[0].ReturnStmt().Value)
}
