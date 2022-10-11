// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"github.com/GuanceCloud/ppl/pkg/ast"
	"github.com/GuanceCloud/ppl/pkg/engine/runtime"
)

func ExitChecking(ctx *runtime.Context, node *ast.CallExpr) error {
	return nil
}

func Exit(ctx *runtime.Context, node *ast.CallExpr) runtime.PlPanic {
	ctx.SetExit()
	return nil
}
