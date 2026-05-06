// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtime

import (
	"encoding/json"
	"errors"
	"fmt"
	"sync"

	"github.com/GuanceCloud/grok"
	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/spf13/cast"
)

const (
	ploriginkey        = "message"
	PlRunInfoField     = "pl_msg"
	localVarCacheSlots = 8
)

type Task struct {
	private map[string]any

	Regs PlReg

	stackHeader *Stack
	stackCur    *Stack
	varCache    map[string]*Varb
	lastVarKey  string
	lastVarb    *Varb
	prevVarKey  string
	prevVarb    *Varb
	varCacheKey [localVarCacheSlots]string
	varCacheVal [localVarCacheSlots]*Varb

	funcCall  map[string]FuncCall
	funcCheck map[string]FuncCheck

	input Input

	// for 循环结束后需要清理此标志
	loopBreak    bool
	loopContinue bool

	signal Signal

	procExit bool

	callRef []*ast.CallExpr

	name string
}

func (ctx *Task) Name() string {
	return ctx.name
}

var (
	ErrNilKey           = errors.New("key is nil")
	ErrKeyNotComparable = errors.New("key is not comparable")
	ErrKeyExists        = errors.New("key exists")
	errRunKeyNotFound   = errors.New("key not found")
	errRunNil           = errors.New("nil")
)

func (ctx *Task) PValue(k string) (any, bool) {
	v, ok := ctx.private[k]
	return v, ok
}

func (ctx *Task) InData() any {
	return ctx.input
}

func (ctx *Task) Signal() Signal {
	return ctx.signal
}

func InitCtx(ctx *Task, input Input, script *Script, signal Signal) *Task {
	ctx.Regs.Reset()

	ctx.input = input

	ctx.funcCall = script.FuncCall
	ctx.funcCheck = nil

	ctx.callRef = script.CallRef
	ctx.loopBreak = false
	ctx.loopContinue = false

	ctx.signal = signal
	ctx.procExit = false

	ctx.name = script.Name

	return ctx
}

func InitCtxForCheck(ctx *Task, script *Script, checkFn map[string]FuncCheck) *Task {
	if ctx.stackHeader == nil {
		ctx.stackHeader = &Stack{
			Data: map[string]*Varb{},
		}
	} else {
		ctx.stackHeader.ResetChain()
	}
	ctx.stackCur = ctx.stackHeader

	ctx.Regs.Reset()

	ctx.funcCall = script.FuncCall
	ctx.funcCheck = checkFn

	ctx.callRef = []*ast.CallExpr{}
	ctx.loopBreak = false
	ctx.loopContinue = false

	ctx.procExit = false

	ctx.name = script.Name
	return ctx
}

func (ctx *Task) SetVarb(key string, value any, dtype ast.DType) error {
	if key == "_" {
		key = ploriginkey
	}

	if ctx.lastVarb != nil && ctx.lastVarKey == key {
		ctx.lastVarb.Value = value
		ctx.lastVarb.DType = dtype
		return nil
	}
	if ctx.prevVarb != nil && ctx.prevVarKey == key {
		v := ctx.prevVarb
		ctx.prevVarKey, ctx.prevVarb = ctx.lastVarKey, ctx.lastVarb
		ctx.lastVarKey, ctx.lastVarb = key, v
		v.Value = value
		v.DType = dtype
		return nil
	}
	if v := ctx.getCachedVarb(key); v != nil {
		v.Value = value
		v.DType = dtype
		return nil
	}
	if ctx.varCache != nil {
		if v, ok := ctx.varCache[key]; ok {
			v.Value = value
			v.DType = dtype
			ctx.touchVarb(key, v)
			return nil
		}
	}

	if v, err := ctx.stackCur.Get(key); err == nil {
		v.Value = value
		v.DType = dtype
		ctx.cacheVarb(key, v)
		return nil
	}

	ctx.cacheVarb(key, ctx.stackCur.SetLocal(key, value, dtype))
	return nil
}

func (ctx *Task) SetExit() {
	ctx.procExit = true
}

func (ctx *Task) SetCallRef(expr *ast.CallExpr) {
	if ctx.callRef == nil {
		ctx.callRef = []*ast.CallExpr{}
	}
	ctx.callRef = append(ctx.callRef, expr)
}

func (ctx *Task) GetKey(key string) (*Varb, error) {
	if key == "_" {
		key = ploriginkey
	}
	if ctx.lastVarb != nil && ctx.lastVarKey == key {
		return ctx.lastVarb, nil
	}
	if ctx.prevVarb != nil && ctx.prevVarKey == key {
		v := ctx.prevVarb
		ctx.prevVarKey, ctx.prevVarb = ctx.lastVarKey, ctx.lastVarb
		ctx.lastVarKey, ctx.lastVarb = key, v
		return v, nil
	}
	if v := ctx.getCachedVarb(key); v != nil {
		return v, nil
	}
	if ctx.varCache != nil {
		if v, ok := ctx.varCache[key]; ok {
			ctx.touchVarb(key, v)
			return v, nil
		}
	}
	if v, err := ctx.stackCur.Get(key); err == nil {
		ctx.cacheVarb(key, v)
		return v, nil
	}

	if v, t, err := ctx.input.Get(key); err == nil {
		return &Varb{
			Value: v,
			DType: t,
		}, nil
	}

	return nil, errRunKeyNotFound
}

func (ctx *Task) GetKeyConv2Str(key string) (string, error) {
	if key == "_" {
		key = ploriginkey
	}

	if ctx.lastVarb != nil && ctx.lastVarKey == key {
		return Conv2String(ctx.lastVarb.Value, ctx.lastVarb.DType)
	}
	if ctx.prevVarb != nil && ctx.prevVarKey == key {
		v := ctx.prevVarb
		ctx.prevVarKey, ctx.prevVarb = ctx.lastVarKey, ctx.lastVarb
		ctx.lastVarKey, ctx.lastVarb = key, v
		return Conv2String(v.Value, v.DType)
	}
	if v := ctx.getCachedVarb(key); v != nil {
		return Conv2String(v.Value, v.DType)
	}
	if ctx.varCache != nil {
		if v, ok := ctx.varCache[key]; ok {
			ctx.touchVarb(key, v)
			return Conv2String(v.Value, v.DType)
		}
	}
	if v, err := ctx.stackCur.Get(key); err == nil {
		ctx.cacheVarb(key, v)
		return Conv2String(v.Value, v.DType)
	}

	if v, t, err := ctx.input.Get(key); err == nil {
		return Conv2String(v, t)
	}

	return "", errRunNil
}

func (ctx *Task) GetFuncCall(key string) (FuncCall, bool) {
	if ctx.funcCall == nil {
		return nil, false
	}
	v, ok := ctx.funcCall[key]
	return v, ok
}

func (ctx *Task) GetFuncCheck(key string) (FuncCheck, bool) {
	if ctx.funcCheck == nil {
		return nil, false
	}
	v, ok := ctx.funcCheck[key]
	return v, ok
}

func (ctx *Task) StackEnterNew() {
	next := ctx.stackCur.Next
	if next == nil {
		next = &Stack{}
		ctx.stackCur.Next = next
	}
	next.Before = ctx.stackCur

	ctx.stackCur = next
}

func (ctx *Task) StackExitCur() {
	cur := ctx.stackCur
	if len(cur.keys) != 0 || cur.CheckPattern != nil {
		ctx.invalidateStackVars(cur)
		cur.Clear()
	}

	ctx.stackCur = cur.Before
	cur.Before = nil
}

func (ctx *Task) StackClear() {
	ctx.invalidateStackVars(ctx.stackCur)
	ctx.stackCur.Clear()
}

func (ctx *Task) cacheVarb(key string, v *Varb) {
	ctx.touchVarb(key, v)

	for i := range ctx.varCacheVal {
		if ctx.varCacheVal[i] == nil || ctx.varCacheKey[i] == key {
			ctx.varCacheKey[i] = key
			ctx.varCacheVal[i] = v
			return
		}
	}
	if ctx.varCache == nil {
		ctx.varCache = make(map[string]*Varb, 8)
		for i, cached := range ctx.varCacheVal {
			if cached != nil {
				ctx.varCache[ctx.varCacheKey[i]] = cached
			}
		}
	}
	ctx.varCache[key] = v
}

func (ctx *Task) touchVarb(key string, v *Varb) {
	if ctx.lastVarb == v && ctx.lastVarKey == key {
		return
	}
	ctx.prevVarKey = ctx.lastVarKey
	ctx.prevVarb = ctx.lastVarb
	ctx.lastVarKey = key
	ctx.lastVarb = v
}

func (ctx *Task) getCachedVarb(key string) *Varb {
	for i, v := range ctx.varCacheVal {
		if v != nil && ctx.varCacheKey[i] == key {
			ctx.touchVarb(key, v)
			return v
		}
	}
	return nil
}

func (ctx *Task) clearVarCache() {
	ctx.lastVarKey = ""
	ctx.lastVarb = nil
	ctx.prevVarKey = ""
	ctx.prevVarb = nil
	for i := range ctx.varCacheVal {
		ctx.varCacheKey[i] = ""
		ctx.varCacheVal[i] = nil
	}
	if len(ctx.varCache) > maxRetainedStackVars {
		ctx.varCache = nil
		return
	}
	for k := range ctx.varCache {
		delete(ctx.varCache, k)
	}
}

func (ctx *Task) invalidateStackVars(stack *Stack) {
	if stack == nil {
		return
	}
	for _, k := range stack.keys {
		v := stack.Data[k]
		if v == nil {
			continue
		}
		if ctx.varCache != nil && ctx.varCache[k] == v {
			delete(ctx.varCache, k)
		}
		if ctx.lastVarb == v {
			ctx.lastVarKey = ""
			ctx.lastVarb = nil
		}
		if ctx.prevVarb == v {
			ctx.prevVarKey = ""
			ctx.prevVarb = nil
		}
		for i, cached := range ctx.varCacheVal {
			if cached == v {
				ctx.varCacheKey[i] = ""
				ctx.varCacheVal[i] = nil
			}
		}
	}
}

func (ctx *Task) GetPattern(pattern string) (*grok.GrokPattern, bool) {
	v, ok := ctx.stackCur.GetPattern(pattern)
	if ok {
		return v, ok
	}

	v, ok = DenormalizedGlobalPatterns[pattern]
	if ok {
		return v, ok
	}

	return nil, false
}

func (ctx *Task) SetPattern(patternAlias string, gPattern *grok.GrokPattern) {
	ctx.stackCur.SetPattern(patternAlias, gPattern)
}

func (ctx *Task) StmtRetrun() bool {
	if ctx.ProcExit() || ctx.loopBreak || ctx.loopContinue {
		return true
	}
	return false
}

func (ctx *Task) ProcExit() bool {
	if !ctx.procExit && ctx.signal != nil {
		if ctx.signal.ExitSignal() {
			ctx.procExit = true
		}
	}
	return ctx.procExit
}

var ctxPool sync.Pool = sync.Pool{
	New: func() any {
		return &Task{}
	},
}

func GetContext() *Task {
	ctx, _ := ctxPool.Get().(*Task)

	if ctx.stackHeader == nil {
		ctx.stackHeader = &Stack{
			Data: map[string]*Varb{},
		}
	} else {
		ctx.stackHeader.ResetChain()
	}
	ctx.clearVarCache()
	ctx.stackCur = ctx.stackHeader
	return ctx
}

func PutContext(ctx *Task) {
	ctx.private = nil
	ctx.Regs.Reset()
	ctx.stackCur = ctx.stackHeader
	if ctx.stackHeader != nil {
		ctx.stackHeader.ResetChain()
	}
	ctx.funcCall = nil
	ctx.funcCheck = nil
	ctx.clearVarCache()
	ctx.input = nil
	ctx.loopBreak = false
	ctx.loopContinue = false
	ctx.signal = nil
	ctx.procExit = false
	ctx.callRef = nil
	ctx.name = ""
	ctxPool.Put(ctx)
}

func Conv2String(v any, dtype ast.DType) (string, error) {
	switch dtype { //nolint:exhaustive
	case ast.Int, ast.Float, ast.Bool, ast.String:
		return cast.ToString(v), nil
	case ast.List, ast.Map:
		res, err := json.Marshal(v)
		return string(res), err
	case ast.Nil:
		return "", nil
	default:
		return "", fmt.Errorf("unsupported data type %d", dtype)
	}
}
