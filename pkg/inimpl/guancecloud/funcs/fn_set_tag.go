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

func SetTagChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) error {
	if len(funcExpr.Param) != 2 && len(funcExpr.Param) != 1 {
		return fmt.Errorf("func `%s' expected 1 or 2 args", funcExpr.Name)
	}
	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return err
	}
	if len(funcExpr.Param) == 2 {
		switch funcExpr.Param[1].NodeType { //nolint:exhaustive
		case ast.TypeStringLiteral, ast.TypeIdentifier, ast.TypeAttrExpr:
		default:
			return fmt.Errorf("param type expect StringLiteral, got `%s'",
				funcExpr.Param[1].NodeType)
		}
	}

	return nil
}

func SetTag(ctx *runtime.Context, funcExpr *ast.CallExpr) runtime.PlPanic {
	if len(funcExpr.Param) != 2 && len(funcExpr.Param) != 1 {
		return fmt.Errorf("func `%s' expected 1 or 2 args", funcExpr.Name)
	}

	key, err := getKeyName(funcExpr.Param[0])
	if err != nil {
		return err
	}
	var val any
	var dtype ast.DType
	if len(funcExpr.Param) == 2 {
		// 不限制值的数据类型，如果不是 string 类将在设置为 tag 时自动转换为 string
		val, dtype, err = runtime.RunStmt(ctx, funcExpr.Param[1])
		if err != nil {
			return nil
		}
	} else {
		v, err := ctx.GetKey(key)
		if err != nil {
			l.Debug(err)
			_ = addKey2PtWithVal(ctx.InData(), key, "", ast.String, input.KindPtTag)

			return nil
		}
		val = v.Value
		dtype = v.DType
	}

	_ = addKey2PtWithVal(ctx.InData(), key, val, dtype, input.KindPtTag)

	return nil
}
