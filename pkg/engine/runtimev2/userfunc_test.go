// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtimev2

import (
	"sync"
	"testing"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/parser"
	"github.com/stretchr/testify/require"
)

func TestUserDefinedFunction(t *testing.T) {
	stmts, err := parser.ParsePipeline("test.p", `
result = add(2, 3)
fn add(left, right) {
    temporary = left + right
    return temporary
}
`)
	require.NoError(t, err)

	script := &Script{Name: "test.p", Stmts: stmts}
	require.Nil(t, script.Check())

	task := NewTask(script.Name, nil)
	task.userFuncs = script.userFuncs
	require.Nil(t, RunScriptStmts(task, script.Stmts))

	result, err := task.GetKey("result")
	require.NoError(t, err)
	require.Equal(t, int64(5), result.Value)
	require.Equal(t, ast.Int, result.DType)
	_, err = task.GetKey("temporary")
	require.Error(t, err)
}

func TestUserDefinedFunctionConcurrentRuns(t *testing.T) {
	stmts, err := parser.ParsePipeline("test.p", `
fn increment(value) { return value + 1 }
result = increment(1)
`)
	require.NoError(t, err)
	script := &Script{Name: "test.p", Stmts: stmts}
	require.Nil(t, script.Check())

	var wg sync.WaitGroup
	errCh := make(chan error, 32)
	for i := 0; i < 32; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			for j := 0; j < 100; j++ {
				if err := script.Run(nil); err != nil {
					errCh <- err
					return
				}
			}
		}()
	}
	wg.Wait()
	close(errCh)
	for err := range errCh {
		require.NoError(t, err)
	}
}
