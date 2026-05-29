package runtimev2

import (
	"testing"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/stretchr/testify/require"
)

type testSignal struct {
	exit bool
}

func (s *testSignal) ExitSignal() bool {
	return s.exit
}

func TestScriptRunSetsSignal(t *testing.T) {
	sig := &testSignal{}
	script := &Script{Name: "test.p"}

	var got Signal
	err := script.Run(sig, func(task *Task) {
		got = task.signal
	})

	require.Nil(t, err)
	require.Same(t, sig, got)
}

func TestRunForStmtStopsWhenSignalSet(t *testing.T) {
	ctx := NewTask("test.p", nil)
	ctx.signal = &testSignal{exit: true}

	err := RunStmts(ctx, ast.Stmts{
		ast.WrapForStmt(&ast.ForStmt{
			Body: &ast.BlockStmt{},
		}),
	})

	require.Nil(t, err)
	require.True(t, ctx.procExit)
}
