package compile

import (
	"testing"

	"github.com/GuanceCloud/platypus/pkg/v2/parser"
)

const (
	sp = `
let a = 2
fn abc(a: int, b: float, c: ...) -> (bool, str) {
	return 1, ""
}
let abcd: any = 2

abc(a, x)

`
)

func TestCompile(t *testing.T) {
	stmts, err := parser.ParsePipeline("main.p", sp)
	if err != nil {
		t.Error(err)
	}
	ctx := NewContext()
	err = BuildSyms(ctx, stmts)
	if err != nil {
		t.Error(err)
	}

	t.Log(ctx)
}
