// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtime

import (
	"sync"
	"testing"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/parser"
	"github.com/stretchr/testify/require"
)

func TestUserDefinedFunction(t *testing.T) {
	stmts, err := parser.ParsePipeline("test.p", `
level = classify(status)

fn classify(code) {
    local_value = code + 1
    if code >= 500 {
        return "error"
    }
    return "info"
}
`)
	require.NoError(t, err)

	script := &Script{Name: "test.p", Ast: stmts}
	require.Nil(t, script.Check(nil))

	ctx := GetContext()
	defer PutContext(ctx)
	InitCtx(ctx, &inputImpl{data: map[string]any{"status": int64(500)}}, script, nil)
	require.Nil(t, RunScriptStmts(ctx, script.Ast))

	level, err := ctx.GetKey("level")
	require.NoError(t, err)
	require.Equal(t, "error", level.Value)
	require.Equal(t, ast.String, level.DType)
	_, err = ctx.GetKey("local_value")
	require.Error(t, err)
}

func TestUserDefinedFunctionConcurrentRuns(t *testing.T) {
	stmts, err := parser.ParsePipeline("test.p", `
fn increment(value) { return value + 1 }
result = increment(status)
`)
	require.NoError(t, err)
	script := &Script{Name: "test.p", Ast: stmts}
	require.Nil(t, script.Check(nil))
	input := &inputImpl{data: map[string]any{"status": int64(1)}}

	var wg sync.WaitGroup
	errCh := make(chan error, 32)
	for i := 0; i < 32; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			for j := 0; j < 100; j++ {
				if err := script.Run(input, nil); err != nil {
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

func BenchmarkUserDefinedFunction(b *testing.B) {
	cases := map[string]string{
		"inline": `result = status + 1`,
		"function": `
fn increment(value) { return value + 1 }
result = increment(status)
`,
	}
	input := &inputImpl{data: map[string]any{"status": int64(1)}}

	for name, source := range cases {
		b.Run(name, func(b *testing.B) {
			stmts, err := parser.ParsePipeline("bench.p", source)
			require.NoError(b, err)
			script := &Script{Name: "bench.p", Ast: stmts}
			require.Nil(b, script.Check(nil))
			b.ReportAllocs()
			b.ResetTimer()
			for i := 0; i < b.N; i++ {
				if err := script.Run(input, nil); err != nil {
					b.Fatal(err)
				}
			}
		})
	}
}

func TestRecursiveFunctionErrorIsCompact(t *testing.T) {
	stmts, err := parser.ParsePipeline("test.p", `
fn recurse() { return recurse() }
recurse()
`)
	require.NoError(t, err)
	script := &Script{Name: "test.p", Ast: stmts}
	require.Nil(t, script.Check(nil))

	errRun := script.Run(&inputImpl{}, nil)
	require.ErrorContains(t, errRun, "function call depth exceeds 64")
	require.LessOrEqual(t, len(errRun.PosChain), 3)
}

func TestUserDefinedFunctionValidation(t *testing.T) {
	tests := []struct {
		name   string
		script string
		err    string
	}{
		{
			name:   "return outside function",
			script: `return 1`,
			err:    "return is only allowed inside a function",
		},
		{
			name:   "duplicate parameter",
			script: `fn add(value, value) { return value }`,
			err:    "duplicate parameter",
		},
		{
			name: "wrong argument count",
			script: `
fn add(left, right) { return left + right }
value = add(1)
`,
			err: "expects 2 arguments, got 1",
		},
	}

	for _, tt := range tests {
		t.Run(tt.name, func(t *testing.T) {
			stmts, err := parser.ParsePipeline("test.p", tt.script)
			require.NoError(t, err)
			script := &Script{Name: "test.p", Ast: stmts}
			require.ErrorContains(t, script.Check(nil), tt.err)
		})
	}
}
