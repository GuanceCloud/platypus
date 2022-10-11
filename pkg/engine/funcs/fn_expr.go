// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"github.com/GuanceCloud/ppl/pkg/ast"
	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
)

func ExprChecking(ctx *runtime.Context, funcExpr *ast.CallExpr) error {
	l.Debugf("warning: expr() is disabled")
	return nil
}

func Expr(ctx *runtime.Context, funcExpr *ast.CallExpr) runtime.PlPanic {
	l.Debugf("warning: expr() is disabled")
	return nil
}
