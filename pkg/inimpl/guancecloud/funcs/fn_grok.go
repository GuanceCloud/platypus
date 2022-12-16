// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"fmt"

	"github.com/GuanceCloud/grok"
	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/engine/runtime"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/input"
)

func GrokChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	if funcExpr.Grok != nil {
		return nil
	}

	if len(funcExpr.Param) < 2 || len(funcExpr.Param) > 3 {
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"func %s expected 2 or 3 args", funcExpr.Name), funcExpr.NamePos)
	}

	if len(funcExpr.Param) == 3 {
		switch funcExpr.Param[2].NodeType { //nolint:exhaustive
		case ast.TypeBoolLiteral:
		default:
			return runtime.NewRunError(ctx, fmt.Sprintf(
				"param key expect BoolLiteral, got `%s'",
				funcExpr.Param[2].NodeType), funcExpr.Param[2].StartPos())
		}
	}

	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return runtime.NewRunError(ctx, err.Error(), funcExpr.Param[0].StartPos())
	}

	var pattern string
	switch funcExpr.Param[1].NodeType { //nolint:exhaustive
	case ast.TypeStringLiteral:
		pattern = funcExpr.Param[1].StringLiteral.Val
	default:
		return runtime.NewRunError(ctx, fmt.Sprintf(
			"expect StringLiteral, got %s",
			funcExpr.Param[1].NodeType), funcExpr.Param[1].StartPos())
	}

	gRe, err := grok.CompilePattern(pattern, ctx)
	if err != nil {
		return runtime.NewRunError(ctx, err.Error(), funcExpr.NamePos)
	}
	funcExpr.Grok = gRe
	return nil
}

func Grok(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	grokRe := funcExpr.Grok
	if grokRe == nil {
		ctx.Regs.ReturnAppend(false, ast.Bool)
		return runtime.NewRunError(ctx, "no grok obj", funcExpr.NamePos)
	}
	var err error

	key, err := getKeyName(funcExpr.Param[0])
	if err != nil {
		ctx.Regs.ReturnAppend(false, ast.Bool)
		return runtime.NewRunError(ctx, err.Error(), funcExpr.Param[0].StartPos())
	}

	val, err := ctx.GetKeyConv2Str(key)
	if err != nil {
		ctx.Regs.ReturnAppend(false, ast.Bool)
		return nil
	}

	trimSpace := true
	if len(funcExpr.Param) == 3 {
		switch funcExpr.Param[2].NodeType { //nolint:exhaustive
		case ast.TypeBoolLiteral:
			trimSpace = funcExpr.Param[2].BoolLiteral.Val
		default:
			ctx.Regs.ReturnAppend(false, ast.Bool)
			return runtime.NewRunError(ctx, fmt.Sprintf("param key expect BoolLiteral, got `%s'",
				funcExpr.Param[2].NodeType), funcExpr.Param[2].StartPos())
		}
	}

	m, _, err := grokRe.RunWithTypeInfo(val, trimSpace)
	if err != nil {
		ctx.Regs.ReturnAppend(false, ast.Bool)
		return nil
	}

	for k, v := range m {
		var dtype ast.DType
		if v == nil {
			dtype = ast.Nil
		} else {
			switch v.(type) {
			case int64:
				dtype = ast.Int
			case float64:
				dtype = ast.Float
			case string:
				dtype = ast.String
			case bool:
				dtype = ast.Bool
			default:
				continue
			}
		}
		if err := addKey2PtWithVal(ctx.InData(), k, v, dtype, input.KindPtDefault); err != nil {
			l.Debug(err)
			ctx.Regs.ReturnAppend(false, ast.Bool)
			return nil
		}
	}
	ctx.Regs.ReturnAppend(true, ast.Bool)
	return nil
}
