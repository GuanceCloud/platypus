// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"fmt"

	"github.com/GuanceCloud/ppl/pkg/ast"
	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
	"github.com/GuanceCloud/ppl/pkg/inimpl/guancecloud/input"
)

func DateTimeChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	if len(funcExpr.Param) != 3 {
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"func %s expected 3 args", funcExpr.Name), funcExpr.NamePos)
	}

	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return runtime.NewRunError(ctx, err.Error(), funcExpr.NamePos)
	}

	switch funcExpr.Param[1].NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
	default:
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"param `precision` expect StringLiteral, got %s",
			funcExpr.Param[1].NodeType), funcExpr.Param[1].StartPos())
	}

	switch funcExpr.Param[2].NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
	default:
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"param `fmt` expect StringLiteral, got %s",
			funcExpr.Param[2].NodeType), funcExpr.Param[2].StartPos())
	}
	return nil
}

func DateTime(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	if len(funcExpr.Param) != 3 {
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"func %s expected 3 args", funcExpr.Name), funcExpr.NamePos)
	}

	key, err := getKeyName(funcExpr.Param[0])
	if err != nil {
		return runtime.NewRunError(ctx, err.Error(), funcExpr.Param[0].StartPos())
	}

	var precision, fmts string

	switch funcExpr.Param[1].NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
		precision = funcExpr.Param[1].StringLiteral.Val
	default:
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"param `precision` expect StringLiteral, got %s",
			funcExpr.Param[1].NodeType), funcExpr.Param[1].StartPos())
	}

	switch funcExpr.Param[2].NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
		fmts = funcExpr.Param[2].StringLiteral.Val
	default:
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"param `fmt` expect StringLiteral, got %s",
			funcExpr.Param[2].NodeType), funcExpr.Param[2].StartPos())
	}

	cont, err := ctx.GetKey(key)
	if err != nil {
		l.Debugf("key `%v' not exist, ignored", key)
		return nil //nolint:nilerr
	}

	if v, err := DateFormatHandle(cont.Value, precision, fmts); err != nil {
		return runtime.NewRunError(ctx, err.Error(), funcExpr.NamePos)
	} else if err := addKey2PtWithVal(ctx.InData(), key, v, ast.String,
		input.KindPtDefault); err != nil {
		l.Debug(err)
		return nil
	}

	return nil
}
