// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtimev2

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/ast"
	plruntime "github.com/GuanceCloud/platypus/pkg/engine/runtime"
	"github.com/GuanceCloud/platypus/pkg/errchain"
)

const maxUserFuncCallDepth = 64
const maxUserFuncErrorFrames = 16

func (s *Script) indexUserFuncs() *errchain.PlError {
	funcs := make(map[string]*ast.FuncDeclStmt)
	for _, node := range s.Stmts {
		if node == nil || node.NodeType != ast.TypeFuncDeclStmt {
			continue
		}
		fn := node.FuncDeclStmt()
		if _, ok := funcs[fn.Name]; ok {
			return errchain.NewErr(s.Name, fn.NamePos,
				fmt.Sprintf("function `%s` is already declared", fn.Name))
		}
		if _, ok := s.Fn[fn.Name]; ok {
			return errchain.NewErr(s.Name, fn.NamePos,
				fmt.Sprintf("function `%s` conflicts with a built-in function", fn.Name))
		}
		funcs[fn.Name] = fn
	}
	s.userFuncs = funcs
	return nil
}

func (s *Script) ensureUserFuncs() *errchain.PlError {
	s.userFuncsOnce.Do(func() {
		s.userFuncsErr = s.indexUserFuncs()
	})
	return s.userFuncsErr
}

func RunFuncDeclStmtCheck(ctx *Task, fn *ast.FuncDeclStmt) *errchain.PlError {
	seen := make(map[string]struct{}, len(fn.Params))
	for _, param := range fn.Params {
		if _, ok := seen[param.Name]; ok {
			return NewRunError(ctx, fmt.Sprintf(
				"function `%s` has duplicate parameter `%s`", fn.Name, param.Name), param.Start)
		}
		seen[param.Name] = struct{}{}
	}
	if fn.Body == nil {
		return nil
	}
	return RunStmtsCheck(ctx, &ContextCheck{inFunction: true}, fn.Body.Stmts)
}

func RunReturnStmtCheck(ctx *Task, check *ContextCheck, stmt *ast.ReturnStmt) *errchain.PlError {
	if !check.inFunction {
		return NewRunError(ctx, "return is only allowed inside a function", stmt.Start)
	}
	if stmt.Value != nil {
		return RunStmtCheck(ctx, check, stmt.Value)
	}
	return nil
}

func RunReturnStmt(ctx *Task, stmt *ast.ReturnStmt) *errchain.PlError {
	if !ctx.inFunction {
		return NewRunError(ctx, "return is only allowed inside a function", stmt.Start)
	}

	value := V{V: nil, T: ast.Void}
	if stmt.Value != nil {
		if err := RunExpr(ctx, stmt.Value); err != nil {
			return err
		}
		var err error
		value, err = ctx.Regs.GetRet()
		if err != nil {
			return NewRunError(ctx, err.Error(), stmt.Value.StartPos())
		}
	}
	ctx.returnVal = value
	ctx.returning = true
	return nil
}

func RunUserFunc(ctx *Task, fn *ast.FuncDeclStmt, call *ast.CallExpr) *errchain.PlError {
	if len(call.Param) != len(fn.Params) {
		return NewRunError(ctx, fmt.Sprintf(
			"function `%s` expects %d arguments, got %d", fn.Name, len(fn.Params), len(call.Param)), call.NamePos)
	}
	if ctx.callDepth >= maxUserFuncCallDepth {
		return NewRunError(ctx, fmt.Sprintf(
			"function call depth exceeds %d", maxUserFuncCallDepth), call.NamePos)
	}

	values := make([]V, len(call.Param))
	for i, param := range call.Param {
		if param.NodeType == ast.TypeAssignmentExpr {
			return NewRunError(ctx,
				"script-defined functions only accept positional arguments", param.StartPos())
		}
		if err := RunExpr(ctx, param); err != nil {
			return err
		}
		value, err := ctx.Regs.GetRet()
		if err != nil {
			return NewRunError(ctx, err.Error(), param.StartPos())
		}
		values[i] = value
	}

	child := NewTask(ctx.name, ctx.funcs)
	child.private = ctx.private
	child.userFuncs = ctx.userFuncs
	child.signal = ctx.signal
	child.inFunction = true
	child.callDepth = ctx.callDepth + 1
	for i, param := range fn.Params {
		child.stackCur.Data[param.Name] = &plruntime.Varb{Value: values[i].V, DType: values[i].T}
	}

	if fn.Body != nil {
		if err := RunStmts(child, fn.Body.Stmts); err != nil {
			return appendUserFuncErrorFrame(err, ctx.name, call)
		}
	}
	if child.procExit {
		ctx.procExit = true
	}
	ctx.Regs.Reset()
	if child.returning {
		ctx.Regs.ReturnAppend(child.returnVal)
	}
	return nil
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
