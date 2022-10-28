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

func URLDecodeChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) error {
	if len(funcExpr.Param) != 1 {
		return fmt.Errorf("func `%s' expected 1 args", funcExpr.Name)
	}
	if _, err := getKeyName(funcExpr.Param[0]); err != nil {
		return err
	}
	return nil
}

func URLDecode(ctx *runtime.Context, funcExpr *ast.CallExpr) runtime.PlPanic {
	if len(funcExpr.Param) != 1 {
		return fmt.Errorf("func `%s' expected 1 args", funcExpr.Name)
	}

	key, err := getKeyName(funcExpr.Param[0])
	if err != nil {
		return err
	}

	cont, err := ctx.GetKeyConv2Str(key)
	if err != nil {
		l.Debugf("key `%v' not exist, ignored", key)
		return nil //nolint:nilerr
	}

	if v, err := UrldecodeHandle(cont); err != nil {
		return err
	} else if err := addKey2PtWithVal(ctx.InData(), key, v, ast.String, input.KindPtDefault); err != nil {
		l.Debug(err)
		return nil
	}

	return nil
}
