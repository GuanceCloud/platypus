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

func PrintfChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) error {
	if len(funcExpr.Param) < 1 {
		return fmt.Errorf("function `%s' requires at least one argument", funcExpr.Name)
	}
	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return err
	}
	return nil
}

func Printf(ctx *runtime.Context, funcExpr *ast.CallExpr) runtime.PlPanic {
	outdata := make([]interface{}, 0)

	if len(funcExpr.Param) < 1 {
		return fmt.Errorf("function `%s' requires at least one argument", funcExpr.Name)
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
