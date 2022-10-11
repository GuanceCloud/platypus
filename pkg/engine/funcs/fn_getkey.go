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

func GetkeyChecking(_ *runtime.Context, funcExpr *ast.CallExpr) error {
	if len(funcExpr.Param) != 1 {
		return fmt.Errorf("func %s expected 1 args", funcExpr.Name)
	}

	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return err
	}

	return nil
}

func Getkey(ctx *runtime.Context, funcExpr *ast.CallExpr) runtime.PlPanic {
	if funcExpr == nil {
		return fmt.Errorf("unreachable")
	}
	if len(funcExpr.Param) != 1 {
		return fmt.Errorf("func %s expected 1 args", funcExpr.Name)
	}

	key, err := getKeyName(funcExpr.Param[0])
	if err != nil {
		return err
	}

	if val, dtype, err := ctx.GetKeyFromPt(key); err != nil {
		ctx.Regs.Append(nil, ast.Nil)
	} else {
		ctx.Regs.Append(val, dtype)
	}

	return nil
}
