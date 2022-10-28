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

func RenameChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) error {
	if len(funcExpr.Param) != 2 {
		return fmt.Errorf("func %s expected 2 args", funcExpr.Name)
	}

	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return err
	}

	switch funcExpr.Param[1].NodeType { //nolint:exhaustive
	case ast.TypeAttrExpr, ast.TypeIdentifier:
	default:
		return fmt.Errorf("param key expect Identifier or AttrExpr, got `%s'",
			funcExpr.Param[1].NodeType)
	}
	return nil
}

func Rename(ctx *runtime.Context, funcExpr *ast.CallExpr) runtime.PlPanic {
	if len(funcExpr.Param) != 2 {
		return fmt.Errorf("func %s expected 2 args", funcExpr.Name)
	}

	to, err := getKeyName(funcExpr.Param[0])
	if err != nil {
		return err
	}

	from, err := getKeyName(funcExpr.Param[1])
	if err != nil {
		return err
	}

	_ = renamePtKey(ctx.InData(), to, from)

	return nil
}
