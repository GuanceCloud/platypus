package runtimev2

import (
	"fmt"
	"sync"

	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/GuanceCloud/platypus/pkg/engine/runtime"
	"github.com/GuanceCloud/platypus/pkg/errchain"
	"github.com/GuanceCloud/platypus/pkg/token"
)

type Opt func(ctx *Task)

type FnCall func(ctx *Task, fn *ast.CallExpr) *errchain.PlError

type Script struct {
	Name    string
	Stmts   ast.Stmts
	Fn      map[string]*Fn
	Program *Program
}

func (s *Script) Run(signal Signal, opt ...Opt) *errchain.PlError {
	task := acquireTask(s.Name, s.Fn)
	defer releaseTask(task)

	task.signal = signal
	for _, o := range opt {
		if o != nil {
			o(task)
		}
	}
	if s.Program != nil {
		if err := s.Program.Run(task); err != nil {
			return err
		}
	} else if err := RunStmts(task, s.Stmts); err != nil {
		return err
	}
	return nil
}

var taskPool sync.Pool

func acquireTask(name string, funcs map[string]*Fn) *Task {
	if task, _ := taskPool.Get().(*Task); task != nil {
		return initTask(task, name, funcs)
	}
	return initTask(&Task{}, name, funcs)
}

func releaseTask(task *Task) {
	*task = Task{}
	taskPool.Put(task)
}

func (s *Script) Check() *errchain.PlError {
	task := NewTask(s.Name, s.Fn)
	if err := RunStmtsCheck(task, &ContextCheck{}, s.Stmts); err != nil {
		return err
	}

	s.Program = CompileWithFuncs(s.Stmts, s.Fn)
	return nil
}

type Signal interface {
	ExitSignal() bool
}

func WithPrivate(v map[TaskP]any) Opt {
	return func(ctx *Task) {
		ctx.private = v
	}
}

type TaskP string

type Task struct {
	name      string
	private   map[TaskP]any
	funcs     map[string]*Fn
	call      *compiledCall
	callBuf   [2]compiledCall
	callDepth int
	slots     map[string]int
	slotVal   []slotCell
	slotBuf   [8]slotCell
	frames    []slotFrame
	frameBuf  [5]slotFrame
	values    []V
	valueBuf  [8]V

	Regs      PlReg
	stackCur  *runtime.Stack
	stackFree []*runtime.Stack
	stackBuf  [5]*runtime.Stack
	stackPool [5]runtime.Stack
	stackUsed int

	// for 循环结束后需要清理此标志
	loopBreak    bool
	loopContinue bool

	signal   Signal
	procExit bool
}

type PlReg struct {
	count    int
	in       [6]V
	overflow []V
}

func (reg *PlReg) Reset() {
	for i := 0; i < reg.count && i < len(reg.in); i++ {
		reg.in[i] = V{}
	}
	for i := range reg.overflow {
		reg.overflow[i] = V{}
	}
	reg.count = 0
	reg.overflow = reg.overflow[:0]
}

type V struct {
	V any
	T ast.DType
}

type slotFrame struct {
	locals   []int
	localBuf [4]int
}

type slotCell struct {
	varb runtime.Varb
	set  bool
}

func (reg *PlReg) ReturnAppend(val ...V) {
	reg.Reset()
	reg.count = len(val)
	if len(val) <= len(reg.in) {
		copy(reg.in[:], val)
		return
	}
	reg.overflow = append(reg.overflow, val...)
}

func (reg *PlReg) ReturnOne(val V) {
	reg.Reset()
	reg.count = 1
	reg.in[0] = val
}

func (reg *PlReg) Count() int {
	return reg.count
}

func (reg *PlReg) GetRet() (V, error) {
	switch {
	case reg.count == 1:
		return reg.valueAt(0), nil
	case reg.count == 0:
		return V{}, fmt.Errorf("no return value")
	default:
		return V{}, fmt.Errorf("there are multiple return values")
	}
}

func (reg *PlReg) GetMultiRet() ([]V, error) {
	switch {
	case reg.count > 1:
		if reg.count <= len(reg.in) {
			return reg.in[:reg.count], nil
		}
		return reg.overflow, nil
	case reg.count == 0:
		return nil, fmt.Errorf("no return value")
	default:
		return nil, fmt.Errorf("only one return value")
	}
}

func (reg *PlReg) valueAt(i int) V {
	if reg.count <= len(reg.in) {
		return reg.in[i]
	}
	return reg.overflow[i]
}

func (ctx *Task) SetExit() {
	ctx.procExit = true
}

func (ctx *Task) StackEnterNew() {
	var next *runtime.Stack
	if n := len(ctx.stackFree); n > 0 {
		next = ctx.stackFree[n-1]
		ctx.stackFree[n-1] = nil
		ctx.stackFree = ctx.stackFree[:n-1]
	} else if ctx.stackUsed < len(ctx.stackPool) {
		next = &ctx.stackPool[ctx.stackUsed]
		ctx.stackUsed++
	} else {
		next = &runtime.Stack{}
	}
	next.Before = ctx.stackCur

	ctx.stackCur = next
	ctx.slotEnter()
}

func (ctx *Task) PValue(k TaskP) (any, bool) {
	v, ok := ctx.private[k]
	return v, ok
}

func (ctx *Task) StackExitCur() {
	cur := ctx.stackCur
	cur.Clear()

	ctx.stackCur = cur.Before
	cur.Before = nil
	ctx.stackFree = append(ctx.stackFree, cur)
	ctx.slotExit()
}

func (ctx *Task) stackClearCur() {
	if ctx.stackCur.Data == nil && ctx.stackCur.CheckPattern == nil {
		return
	}
	ctx.stackCur.Clear()
}

func (ctx *Task) ProcExit() bool {
	if !ctx.procExit && ctx.signal != nil {
		if ctx.signal.ExitSignal() {
			ctx.procExit = true
		}
	}
	return ctx.procExit
}

func (ctx *Task) SetVarb(key string, v V) {
	if ctx.slotSet(key, v) {
		return
	}
	ctx.stackCur.Set(key, v.V, v.T)
}

func (ctx *Task) GetKey(key string) (*runtime.Varb, error) {
	if v, ok := ctx.slotVarb(key); ok {
		return v, nil
	}
	if v, err := ctx.stackCur.Get(key); err == nil {
		return v, nil
	}

	return nil, fmt.Errorf("key not found")
}

func (ctx *Task) useSlots(slots map[string]int) {
	ctx.stackClearCur()
	ctx.slots = slots
	if len(slots) <= len(ctx.slotBuf) {
		ctx.slotVal = ctx.slotBuf[:len(slots)]
		for i := range ctx.slotVal {
			ctx.slotVal[i] = slotCell{}
		}
	} else {
		ctx.slotVal = make([]slotCell, len(slots))
	}
	ctx.frames = ctx.frameBuf[:0]
	if ctx.stackCur != nil {
		ctx.slotEnter()
	}
}

func (ctx *Task) slotEnter() {
	if len(ctx.slots) == 0 {
		return
	}
	ctx.frames = append(ctx.frames, slotFrame{})
	top := &ctx.frames[len(ctx.frames)-1]
	top.locals = top.localBuf[:0]
}

func (ctx *Task) slotExit() {
	if len(ctx.frames) == 0 {
		return
	}
	top := &ctx.frames[len(ctx.frames)-1]
	for _, idx := range top.locals {
		ctx.slotVal[idx] = slotCell{}
	}
	ctx.frames = ctx.frames[:len(ctx.frames)-1]
}

func (ctx *Task) slotClearCur() {
	if len(ctx.frames) == 0 {
		return
	}
	top := &ctx.frames[len(ctx.frames)-1]
	for _, idx := range top.locals {
		ctx.slotVal[idx] = slotCell{}
	}
	top.locals = top.locals[:0]
}

func (ctx *Task) slotSet(key string, v V) bool {
	idx, ok := ctx.slots[key]
	if !ok || len(ctx.frames) == 0 {
		return false
	}
	return ctx.slotSetIndex(idx, v)
}

func (ctx *Task) slotSetIndex(idx int, v V) bool {
	if idx < 0 || idx >= len(ctx.slotVal) || len(ctx.frames) == 0 {
		return false
	}
	if ctx.slotVal[idx].set {
		cell := &ctx.slotVal[idx]
		cell.varb.Value = v.V
		cell.varb.DType = v.T
		return true
	}
	ctx.slotVal[idx] = slotCell{
		varb: runtime.Varb{Value: v.V, DType: v.T},
		set:  true,
	}
	frame := &ctx.frames[len(ctx.frames)-1]
	frame.locals = append(frame.locals, idx)
	return true
}

func (ctx *Task) slotVarb(key string) (*runtime.Varb, bool) {
	idx, ok := ctx.slots[key]
	if !ok || idx < 0 || idx >= len(ctx.slotVal) {
		return nil, false
	}
	cell := &ctx.slotVal[idx]
	if !cell.set {
		return nil, false
	}
	return &cell.varb, true
}

func (ctx *Task) slotGet(key string) (V, bool) {
	idx, ok := ctx.slots[key]
	if !ok {
		return V{}, false
	}
	return ctx.slotGetIndex(idx)
}

func (ctx *Task) slotGetIndex(idx int) (V, bool) {
	if idx < 0 || idx >= len(ctx.slotVal) {
		return V{}, false
	}
	cell := &ctx.slotVal[idx]
	if cell.set {
		return V{V: cell.varb.Value, T: cell.varb.DType}, true
	}
	return V{}, false
}

func (ctx *Task) valueResetFrom(base int) {
	for i := base; i < len(ctx.values); i++ {
		ctx.values[i] = V{}
	}
	ctx.values = ctx.values[:base]
}

func valueFromAny(v any) (V, bool) {
	orig := v
	switch v := v.(type) {
	case nil:
		return V{nil, ast.Nil}, true
	case string:
		return V{orig, ast.String}, true
	case int64:
		return V{orig, ast.Int}, true
	case int:
		return V{int64(v), ast.Int}, true
	case int32:
		return V{int64(v), ast.Int}, true
	case int16:
		return V{int64(v), ast.Int}, true
	case int8:
		return V{int64(v), ast.Int}, true
	case uint:
		return V{int64(v), ast.Int}, true
	case uint64:
		if v <= uint64(^uint64(0)>>1) {
			return V{int64(v), ast.Int}, true
		}
	case uint32:
		return V{int64(v), ast.Int}, true
	case uint16:
		return V{int64(v), ast.Int}, true
	case uint8:
		return V{int64(v), ast.Int}, true
	case float64:
		return V{orig, ast.Float}, true
	case float32:
		return V{float64(v), ast.Float}, true
	case bool:
		return V{orig, ast.Bool}, true
	case []any:
		return V{orig, ast.List}, true
	case map[string]any:
		return V{orig, ast.Map}, true
	default:
		return V{}, false
	}
	return V{}, false
}

func (ctx *Task) enterCall(call *ast.CallExpr, args []expr, argsV []valueExpr) *compiledCall {
	if ctx.callDepth < len(ctx.callBuf) {
		frame := &ctx.callBuf[ctx.callDepth]
		frame.call = call
		frame.args = args
		frame.argsV = argsV
		ctx.callDepth++
		return frame
	}
	ctx.callDepth++
	return &compiledCall{call: call, args: args, argsV: argsV}
}

func (ctx *Task) exitCall(frame *compiledCall) {
	if ctx.callDepth > 0 {
		ctx.callDepth--
	}
	if frame != nil {
		frame.call = nil
		frame.args = nil
		frame.argsV = nil
	}
}

func (ctx *Task) GetFn(name string) (FnCall, bool) {
	if v, ok := ctx.funcs[name]; ok && v != nil && v.Call != nil {
		return v.Call, true
	}
	return nil, false
}

func (ctx *Task) GetFnCheck(name string) (FnCall, bool) {
	if v, ok := ctx.funcs[name]; ok && v != nil && v.CallCheck != nil {
		return v.CallCheck, true
	}
	return nil, false
}

func (ctx *Task) StmtRetrun() bool {
	if ctx.ProcExit() || ctx.loopBreak || ctx.loopContinue {
		return true
	}
	return false
}

func (ctx *Task) stmtReturnFast() bool {
	if ctx.signal == nil {
		return ctx.procExit || ctx.loopBreak || ctx.loopContinue
	}
	return ctx.StmtRetrun()
}

func NewTask(name string, funcs map[string]*Fn) *Task {
	return initTask(&Task{}, name, funcs)
}

func initTask(task *Task, name string, funcs map[string]*Fn) *Task {
	*task = Task{
		funcs: funcs,
		name:  name,
	}
	task.values = task.valueBuf[:0]
	task.stackFree = task.stackBuf[:0]
	task.StackEnterNew()
	return task
}

func NewRunError(ctx *Task, err string, pos token.LnColPos) *errchain.PlError {
	return errchain.NewErr(ctx.name, pos, err)
}
