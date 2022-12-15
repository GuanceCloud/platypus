// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/engine/runtime"
	"github.com/spf13/cast"
)

func PrintfChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	if len(funcExpr.Param) < 1 {
		return runtime.NewRunError(ctx, "function `%s' requires at least one argument", funcExpr.NamePos)
	}
	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return runtime.NewRunError(ctx, err.Error(), funcExpr.Param[0].StartPos())
	}
	return nil
}

func Printf(ctx *runtime.Context, funcExpr *ast.CallExpr) *runtime.RuntimeError {
	outdata := make([]interface{}, 0)

	if len(funcExpr.Param) < 1 {
		return runtime.NewRunError(ctx,
			"function `%s' requires at least one argument", funcExpr.NamePos)
	}

	fmtStr := getArgStr(ctx, funcExpr.Param[0])

	if fmtStr == "" {
		return nil
	}

	for i := 1; i < len(funcExpr.Param); i++ {
		if v, _, err := runtime.RunStmt(ctx, funcExpr.Param[i]); err != nil {
			return err
		} else {
			outdata = append(outdata, v)
		}
	}

	if _, err := fmt.Printf(fmtStr, outdata...); err != nil {
		l.Debug(err)
	}
	return nil
}

func getArgStr(ctx *runtime.Context, node *ast.Node) string {
	if node == nil {
		return ""
	}

	if v, dtype, err := runtime.RunStmt(ctx, node); err == nil {
		if dtype == ast.String {
			return cast.ToString(v)
		}
	}
	return ""
}
