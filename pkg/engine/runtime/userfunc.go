// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtime

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
)

const maxUserFuncCallDepth = 64
const maxUserFuncErrorFrames = 16

func RunReturnStmtCheck(ctx *Task, check *ContextCheck, stmt *ast.ReturnStmt) *errchain.PlError {
	if !check.inFunction {
		return NewRunError(ctx, "return is only allowed inside a function", stmt.Start)
	}
	if stmt.Value != nil {
		return RunStmtCheck(ctx, check, stmt.Value)
	}
	return nil
}

func RunReturnStmt(ctx *Task, stmt *ast.ReturnStmt) (any, ast.DType, *errchain.PlError) {
	if !ctx.inFunction {
		return nil, ast.Invalid, NewRunError(ctx,
			"return is only allowed inside a function", stmt.Start)
	}

	value, dtype := any(nil), ast.Void
	if stmt.Value != nil {
		var err *errchain.PlError
		value, dtype, err = RunStmt(ctx, stmt.Value)
		if err != nil {
			return nil, ast.Invalid, err
		}
	}
	ctx.returnVal = value
	ctx.returnType = dtype
	ctx.returning = true
	return value, dtype, nil
}

func RunUserFunc(ctx *Task, fn *ast.FuncDeclStmt, call *ast.CallExpr) (any, ast.DType, *errchain.PlError) {
	if len(call.Param) != len(fn.Params) {
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"function `%s` expects %d arguments, got %d", fn.Name, len(fn.Params), len(call.Param)), call.NamePos)
	}
	if ctx.callDepth >= maxUserFuncCallDepth {
		return nil, ast.Invalid, NewRunError(ctx, fmt.Sprintf(
			"function call depth exceeds %d", maxUserFuncCallDepth), call.NamePos)
	}

	values := make([]Varb, len(call.Param))
	for i, param := range call.Param {
		if param.NodeType == ast.TypeAssignmentExpr {
			return nil, ast.Invalid, NewRunError(ctx,
				"script-defined functions only accept positional arguments", param.StartPos())
		}
		value, dtype, err := RunStmt(ctx, param)
		if err != nil {
			return nil, ast.Invalid, err
		}
		values[i] = Varb{Value: value, DType: dtype}
	}

	child := GetContext()
	defer PutContext(child)
	child.private = ctx.private
	child.input = ctx.input
	child.funcCall = ctx.funcCall
	child.funcCheck = ctx.funcCheck
	child.userFuncs = ctx.userFuncs
	child.signal = ctx.signal
	child.name = ctx.name
	child.inFunction = true
	child.callDepth = ctx.callDepth + 1

	for i, param := range fn.Params {
		child.stackCur.Data[param.Name] = &Varb{Value: values[i].Value, DType: values[i].DType}
	}

	if fn.Body != nil {
		if err := RunStmts(child, fn.Body.Stmts); err != nil {
			return nil, ast.Invalid, appendUserFuncErrorFrame(err, ctx.name, call)
		}
	}
	if child.procExit {
		ctx.procExit = true
	}
	if child.returning {
		return child.returnVal, child.returnType, nil
	}
	return nil, ast.Void, nil
}

func appendUserFuncErrorFrame(err *errchain.PlError, file string, call *ast.CallExpr) *errchain.PlError {
	if len(err.PosChain) >= maxUserFuncErrorFrames {
		return err
	}
	if len(err.PosChain) > 0 {
		last := err.PosChain[len(err.PosChain)-1]
		if last.File == file && last.Pos == int(call.NamePos.Pos) {
			return err
		}
	}
	return err.ChainAppend(file, call.NamePos)
}
