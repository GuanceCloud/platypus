package runtimev2

import (
	"testing"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/parser"
)

type testSignal struct {
	limit int
	count int
}

func (s *testSignal) ExitSignal() bool {
	s.count++
	return s.count >= s.limit
}

func parseTestScript(t testing.TB, name, script string, funcs map[string]*Fn) *Script {
	t.Helper()

	stmts, err := parser.ParsePipeline(name, script)
	if err != nil {
		t.Fatal(err)
	}

	s := &Script{
		Name:  name,
		Stmts: stmts,
		Fn:    funcs,
	}
	if err := s.Check(); err != nil {
		t.Fatal(err)
	}
	return s
}

func TestScriptRunHonorsSignal(t *testing.T) {
	signal := &testSignal{limit: 4}
	ticks := 0
	funcs := map[string]*Fn{
		"tick": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, nil)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				ticks++
				return nil
			},
		},
	}

	s := parseTestScript(t, "signal", `for ;; { tick() }`, funcs)
	if err := s.Run(signal); err != nil {
		t.Fatal(err)
	}

	if ticks == 0 || ticks > signal.limit {
		t.Fatalf("expected bounded loop iterations before signal exit, got %d", ticks)
	}
}

func TestCheckCompilesProgram(t *testing.T) {
	s := parseTestScript(t, "program", `
a = 0
for x in [1, 2, 3] {
	if x == 2 {
		continue
	}
	a = a + x
}
`, nil)

	if s.Program == nil {
		t.Fatal("expected Check to compile a program")
	}
	if len(s.Program.ops) == 0 {
		t.Fatal("expected compiled program ops")
	}
	if err := s.Run(nil); err != nil {
		t.Fatal(err)
	}
}

func TestProgramRunsCompiledExpressions(t *testing.T) {
	hits := 0
	funcs := map[string]*Fn{
		"hit": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, nil)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				hits++
				return nil
			},
		},
	}

	s := parseTestScript(t, "compiled-expr", `
if (1 + 2 * 3 == 7) && ("at" in "cat") {
	hit()
}
`, funcs)
	if err := s.Run(nil); err != nil {
		t.Fatal(err)
	}
	if hits != 1 {
		t.Fatalf("expected compiled expression branch to run once, got %d", hits)
	}
}

func TestProgramRunsCompiledAssignmentAndCall(t *testing.T) {
	funcs := map[string]*Fn{
		"pair": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, nil)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				ctx.Regs.ReturnAppend(
					V{V: int64(2), T: ast.Int},
					V{V: int64(5), T: ast.Int},
				)
				return nil
			},
		},
	}

	s := parseTestScript(t, "compiled-assignment", `
a, b = pair()
a += 3
m = {"x": [1]}
m["x"][0] += b
`, funcs)

	for _, op := range s.Program.ops {
		if op.kind != stmtExpr {
			t.Fatalf("expected top-level op to be stmtExpr, got %v", op.kind)
		}
		if _, ok := op.expr.(assignExpr); !ok {
			t.Fatalf("expected assignment to compile as assignExpr, got %T", op.expr)
		}
	}

	task := NewTask(s.Name, s.Fn)
	if err := s.Program.Run(task); err != nil {
		t.Fatal(err)
	}

	a, err := task.GetKey("a")
	if err != nil {
		t.Fatal(err)
	}
	if a.Value != int64(5) {
		t.Fatalf("expected a=5, got %v", a.Value)
	}
	m, err := task.GetKey("m")
	if err != nil {
		t.Fatal(err)
	}
	x := m.Value.(map[string]any)["x"].([]any)[0]
	if x != int64(6) {
		t.Fatalf("expected m.x[0]=6, got %v", x)
	}
}

func TestProgramRunsCompiledIndexAndSlice(t *testing.T) {
	s := parseTestScript(t, "compiled-index-slice", `
m = {"x": [10, 20, 30], "s": "abcdef"}
a = m["x"][-1]
s = m["s"]
x = m["x"]
b = s[1:5:2]
c = x[0:2]
`, nil)

	task := NewTask(s.Name, s.Fn)
	if err := s.Program.Run(task); err != nil {
		t.Fatal(err)
	}

	a, err := task.GetKey("a")
	if err != nil {
		t.Fatal(err)
	}
	if a.Value != int64(30) {
		t.Fatalf("expected a=30, got %v", a.Value)
	}

	b, err := task.GetKey("b")
	if err != nil {
		t.Fatal(err)
	}
	if b.Value != "bd" {
		t.Fatalf("expected b=bd, got %v", b.Value)
	}

	c, err := task.GetKey("c")
	if err != nil {
		t.Fatal(err)
	}
	list := c.Value.([]any)
	if len(list) != 2 || list[0] != int64(10) || list[1] != int64(20) {
		t.Fatalf("expected c=[10 20], got %#v", c.Value)
	}
}

func TestProgramUsesCompiledCallParams(t *testing.T) {
	sumParams := []*Param{
		{Name: "a", Typs: []ast.DType{ast.Int}},
		{Name: "b", Typs: []ast.DType{ast.Int}},
	}
	joinParams := []*Param{
		{Name: "parts", Typs: []ast.DType{ast.String}, Variable: true},
	}
	funcs := map[string]*Fn{
		"sum": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, sumParams)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				a, err := GetParamInt(ctx, fn, sumParams, 0)
				if err != nil {
					return err
				}
				b, err := GetParamInt(ctx, fn, sumParams, 1)
				if err != nil {
					return err
				}
				ctx.Regs.ReturnAppend(V{V: a + b, T: ast.Int})
				return nil
			},
		},
		"join": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, joinParams)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				parts, err := GetParamList(ctx, fn, joinParams, 0)
				if err != nil {
					return err
				}
				ret := ""
				for _, part := range parts {
					ret += part.(string)
				}
				ctx.Regs.ReturnAppend(V{V: ret, T: ast.String})
				return nil
			},
		},
	}

	s := parseTestScript(t, "compiled-call-params", `
a = 1
b = sum(a + 2, sum(3, 4))
c = join("a", "b" + "c")
`, funcs)

	task := NewTask(s.Name, s.Fn)
	if err := s.Program.Run(task); err != nil {
		t.Fatal(err)
	}

	b, err := task.GetKey("b")
	if err != nil {
		t.Fatal(err)
	}
	if b.Value != int64(10) {
		t.Fatalf("expected b=10, got %v", b.Value)
	}

	c, err := task.GetKey("c")
	if err != nil {
		t.Fatal(err)
	}
	if c.Value != "abc" {
		t.Fatalf("expected c=abc, got %v", c.Value)
	}
}

func TestProgramUsesSlotFrames(t *testing.T) {
	s := parseTestScript(t, "slot-frames", `
a = 1
if true {
	a = a + 1
	local_only = 9
}
`, nil)

	if len(s.Program.slots) == 0 {
		t.Fatal("expected compiled slots")
	}

	task := NewTask(s.Name, s.Fn)
	if err := s.Program.Run(task); err != nil {
		t.Fatal(err)
	}

	a, err := task.GetKey("a")
	if err != nil {
		t.Fatal(err)
	}
	if a.Value != int64(2) {
		t.Fatalf("expected a=2, got %v", a.Value)
	}
	if _, err := task.GetKey("local_only"); err == nil {
		t.Fatal("expected block-local variable to be out of scope")
	}
}

func TestProgramCompilesTopLevelVM(t *testing.T) {
	s := parseTestScript(t, "top-level-vm", `
total = 0
if total == 0 {
	total = 3
} else {
	total = 4
}
`, nil)

	if len(s.Program.code) == 0 {
		t.Fatal("expected top-level program to compile to VM code")
	}

	task := NewTask(s.Name, s.Fn)
	if err := s.Program.Run(task); err != nil {
		t.Fatal(err)
	}
	total, err := task.GetKey("total")
	if err != nil {
		t.Fatal(err)
	}
	if total.Value != int64(3) {
		t.Fatalf("expected total=3, got %v", total.Value)
	}
}

func TestProgramSkipsVMInLoopBody(t *testing.T) {
	s := parseTestScript(t, "loop-body-no-vm", `
for i in [1] {
	if i == 1 {
		i += 1
	}
}
`, nil)

	body := s.Program.ops[0].forInOp.body
	if body == nil {
		t.Fatal("expected for-in body")
	}
	if len(body.code) != 0 {
		t.Fatal("expected loop body to keep compiled-op execution")
	}
}

func TestScriptRunFallsBackToInterpreterWithoutProgram(t *testing.T) {
	stmts, err := parser.ParsePipeline("fallback", `a = 1`)
	if err != nil {
		t.Fatal(err)
	}

	s := &Script{
		Name:  "fallback",
		Stmts: stmts,
	}
	if err := s.Run(nil); err != nil {
		t.Fatal(err)
	}
}

func BenchmarkProgramRun(b *testing.B) {
	params := []*Param{
		{Name: "a", Typs: []ast.DType{ast.Int}},
		{Name: "b", Typs: []ast.DType{ast.Int}},
	}
	funcs := map[string]*Fn{
		"sum": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, params)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				a, err := GetParamInt(ctx, fn, params, 0)
				if err != nil {
					return err
				}
				b, err := GetParamInt(ctx, fn, params, 1)
				if err != nil {
					return err
				}
				ctx.Regs.ReturnAppend(V{V: a + b, T: ast.Int})
				return nil
			},
		},
	}
	s := parseTestScript(b, "bench-program", `
total = 0
items = [1, 2, 3, 4, 5]
labels = {"name": "abcdef"}
for i in items {
	if i % 2 == 0 {
		total += sum(i, 3)
	} else {
		total += i
	}
	label = labels["name"]
	name = label[1:5:2]
}
`, funcs)

	b.ReportAllocs()
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		task := NewTask(s.Name, s.Fn)
		if err := s.Program.Run(task); err != nil {
			b.Fatal(err)
		}
	}
}

func BenchmarkInterpreterRunStmts(b *testing.B) {
	params := []*Param{
		{Name: "a", Typs: []ast.DType{ast.Int}},
		{Name: "b", Typs: []ast.DType{ast.Int}},
	}
	funcs := map[string]*Fn{
		"sum": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, params)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				a, err := GetParamInt(ctx, fn, params, 0)
				if err != nil {
					return err
				}
				b, err := GetParamInt(ctx, fn, params, 1)
				if err != nil {
					return err
				}
				ctx.Regs.ReturnAppend(V{V: a + b, T: ast.Int})
				return nil
			},
		},
	}
	stmts, err := parser.ParsePipeline("bench-interpreter", `
total = 0
items = [1, 2, 3, 4, 5]
labels = {"name": "abcdef"}
for i in items {
	if i % 2 == 0 {
		total += sum(i, 3)
	} else {
		total += i
	}
	label = labels["name"]
	name = label[1:5:2]
}
`)
	if err != nil {
		b.Fatal(err)
	}
	s := &Script{Name: "bench-interpreter", Stmts: stmts, Fn: funcs}
	if err := s.Check(); err != nil {
		b.Fatal(err)
	}
	s.Program = nil

	b.ReportAllocs()
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		task := NewTask(s.Name, s.Fn)
		if err := RunStmts(task, s.Stmts); err != nil {
			b.Fatal(err)
		}
	}
}

func TestRunErrorUnwindsBlockScope(t *testing.T) {
	funcs := map[string]*Fn{
		"fail": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, nil)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return NewRunError(ctx, "fail", fn.NamePos)
			},
		},
	}

	s := parseTestScript(t, "unwind", `if true { fail() }`, funcs)
	task := NewTask(s.Name, s.Fn)
	initialStack := task.stackCur

	if err := RunStmts(task, s.Stmts); err == nil {
		t.Fatal("expected runtime error")
	}
	if task.stackCur != initialStack {
		t.Fatal("expected block scope to be unwound after runtime error")
	}
}

func TestProgramVMUnwindsBlockScopeOnError(t *testing.T) {
	funcs := map[string]*Fn{
		"fail": {
			CallCheck: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return CheckPassParam(ctx, fn, nil)
			},
			Call: func(ctx *Task, fn *ast.CallExpr) *errchain.PlError {
				return NewRunError(ctx, "fail", fn.NamePos)
			},
		},
	}

	s := parseTestScript(t, "vm-unwind", `if true { fail() }`, funcs)
	if len(s.Program.code) == 0 {
		t.Fatal("expected top-level if to compile to VM code")
	}
	task := NewTask(s.Name, s.Fn)
	initialStack := task.stackCur

	if err := s.Program.Run(task); err == nil {
		t.Fatal("expected runtime error")
	}
	if task.stackCur != initialStack {
		t.Fatal("expected VM block scope to be unwound after runtime error")
	}
}

func TestCheckSliceStepWithoutEnd(t *testing.T) {
	s := parseTestScript(t, "slice-step", `a = "abcdef"[::2]`, nil)
	if err := s.Run(nil); err != nil {
		t.Fatal(err)
	}
}
