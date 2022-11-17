// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"fmt"

	"github.com/GuanceCloud/ppl/pkg/ast"
	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
)

func UseChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	if len(funcExpr.Param) != 1 {
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"func %s expects 1 args", funcExpr.Name), funcExpr.NamePos)
	}

	switch funcExpr.Param[0].NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
		ctx.SetCallRef(funcExpr.Param[0].StringLiteral.Val)
	default:
		return runtime.NewRunError(ctx, fmt.Sprintf("param key expects AttrExpr or Identifier, got %s",
			funcExpr.Param[0].NodeType), funcExpr.Param[0].StartPos())
	}

	return nil
}

func Use(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	if len(funcExpr.Param) != 1 {
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"func %s expects 1 args", funcExpr.Name), funcExpr.NamePos)
	}

	var refScript *runtime.Script
	switch funcExpr.Param[0].NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
		if ng, ok := ctx.GetCallRef(funcExpr.Param[0].StringLiteral.Val); ok {
			refScript = ng
		} else {
			l.Debugf("script not found: %s", funcExpr.Param[0].StringLiteral.Val)
			return nil
		}
	default:
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"param key expects AttrExpr or Identifier, got %s",
			funcExpr.Param[0].NodeType), funcExpr.Param[0].StartPos())
	}

	return runtime.RefRunScript(ctx, refScript)
}
