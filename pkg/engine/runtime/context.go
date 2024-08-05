// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtime

import (
	"encoding/json"
	"errors"
	"fmt"
	"reflect"
	"sync"

	"github.com/GuanceCloud/grok"
	"github.com/GuanceCloud/platypus/pkg/ast"
	"github.com/spf13/cast"
)

const (
	ploriginkey    = "message"
	PlRunInfoField = "pl_msg"
)

type Script struct {
	CallRef []*ast.CallExpr

	FuncCall map[string]FuncCall

	Name      string
	Namespace string
	Category  string
	FilePath  string

	Content string

	Ast ast.Stmts
}

type Signal interface {
	ExitSignal() bool
}

type Task struct {
	Regs PlReg

	stackHeader *PlProcStack
	stackCur    *PlProcStack

	funcCall  map[string]FuncCall
	funcCheck map[string]FuncCheck

	inType       InType
	inRMap       InputWithRMap
	inWithoutMap InputWithoutMap

	// for 循环结束后需要清理此标志
	loopBreak    bool
	loopContinue bool

	signal Signal

	procExit bool

	callRCef []*ast.CallExpr

	name    string
	content string

	withValue map[any]any

	// namespace string
	// filepath  string
}

func (ctx *Task) Name() string {
	return ctx.name
}

var (
	ErrNilKey           = errors.New("key is nil")
	ErrKeyNotComparable = errors.New("key is not comparable")
	ErrKeyExists        = errors.New("key exists")
)

func (ctx *Task) WithVal(key, val any, force bool) error {
	if key == nil {
		return ErrNilKey
	}
	if !reflect.TypeOf(key).Comparable() {
		return ErrKeyNotComparable
	}
	if ctx.withValue == nil {
		ctx.withValue = map[any]any{
			key: val,
		}
		return nil
	}

	if _, ok := ctx.withValue[key]; !ok {
		ctx.withValue[key] = val
	} else {
		if force {
			ctx.withValue[key] = val
		} else {
			return ErrKeyExists
		}
	}

	return nil
}

func (ctx *Task) Val(key any) any {
	if ctx.withValue == nil {
		return nil
	}
	return ctx.withValue[key]
}

func (ctx *Task) InData() any {
	switch ctx.inType {
	case InRMap:
		return ctx.inRMap
	default:
		return ctx.inWithoutMap
	}
}

func (ctx *Task) Signal() Signal {
	return ctx.signal
}

func InitCtxWithoutMap(ctx *Task, inWithoutMap InputWithoutMap, funcs map[string]FuncCall,
	callRef []*ast.CallExpr, signal Signal, name, content string,
) *Task {
	ctx.Regs.Reset()

	ctx.inType = InWithoutMap
	ctx.inWithoutMap = inWithoutMap

	ctx.funcCall = funcs
	ctx.funcCheck = nil

	ctx.callRCef = callRef
	ctx.loopBreak = false
	ctx.loopContinue = false

	ctx.signal = signal
	ctx.procExit = false

	ctx.name = name
	ctx.content = content

	return ctx
}

func InitCtxWithRMap(ctx *Task, inWithRMap InputWithRMap, funcs map[string]FuncCall,
	callRef []*ast.CallExpr, signal Signal, name, content string,
) *Task {
	ctx.Regs.Reset()

	ctx.inType = InRMap
	ctx.inRMap = inWithRMap

	ctx.funcCall = funcs
	ctx.funcCheck = nil

	ctx.callRCef = callRef
	ctx.loopBreak = false
	ctx.loopContinue = false

	ctx.signal = signal
	ctx.procExit = false

	ctx.name = name
	ctx.content = content

	return ctx
}

func InitCtxForCheck(ctx *Task, funcs map[string]FuncCall, funcsCheck map[string]FuncCheck,
	name, content string,
) *Task {
	ctx.stackHeader = &PlProcStack{
		data: map[string]*Varb{},
	}
	ctx.stackCur = ctx.stackHeader

	ctx.Regs.Reset()

	ctx.funcCall = funcs
	ctx.funcCheck = funcsCheck

	ctx.callRCef = []*ast.CallExpr{}
	ctx.loopBreak = false
	ctx.loopContinue = false

	ctx.procExit = false

	ctx.name = name
	ctx.content = content

	return ctx
}

func (ctx *Task) SetVarb(key string, value any, dtype ast.DType) error {
	if key == "_" {
		key = ploriginkey
	}

	ctx.stackCur.Set(key, value, dtype)
	return nil
}

func (ctx *Task) SetExit() {
	ctx.procExit = true
}

func (ctx *Task) SetCallRef(expr *ast.CallExpr) {
	if ctx.callRCef == nil {
		ctx.callRCef = []*ast.CallExpr{}
	}
	ctx.callRCef = append(ctx.callRCef, expr)
}

func (ctx *Task) GetKey(key string) (*Varb, error) {
	if key == "_" {
		key = ploriginkey
	}
	if v, err := ctx.stackCur.Get(key); err == nil {
		return v, nil
	}

	switch ctx.inType {
	case InRMap:
		if v, t, err := ctx.inRMap.Get(key); err == nil {
			return &Varb{
				Value: v,
				DType: t,
			}, nil
		}
	}

	return nil, fmt.Errorf("key not found")
}

func (ctx *Task) GetKeyConv2Str(key string) (string, error) {
	if key == "_" {
		key = ploriginkey
	}

	if v, err := ctx.stackCur.Get(key); err == nil {
		return Conv2String(v.Value, v.DType)
	}

	switch ctx.inType {
	case InRMap:
		if v, t, err := ctx.inRMap.Get(key); err == nil {
			return Conv2String(v, t)
		}
	}

	return "", fmt.Errorf("nil")
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
	next := &PlProcStack{
		data:   map[string]*Varb{},
		before: ctx.stackCur,
	}

	ctx.stackCur = next
}

func (ctx *Task) StackExitCur() {
	ctx.stackCur.data = nil
	ctx.stackCur.checkPattern = nil

	ctx.stackCur = ctx.stackCur.before
}

func (ctx *Task) StackClear() {
	ctx.stackCur.Clear()
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

	ctx.stackHeader = &PlProcStack{
		data: map[string]*Varb{},
	}
	ctx.stackCur = ctx.stackHeader
	return ctx
}

func PutContext(ctx *Task) {
	ctx.stackHeader = nil
	ctx.stackCur = nil

	ctx.funcCall = nil
	ctx.funcCheck = nil

	ctx.inRMap = nil
	ctx.inRMap = nil
	ctx.inWithoutMap = nil
	ctx.inType = InNoSet

	ctx.loopBreak = false
	ctx.loopContinue = false

	ctx.procExit = false

	ctx.callRCef = nil

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
