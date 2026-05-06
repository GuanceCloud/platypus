// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtime

import (
	"errors"

	"github.com/GuanceCloud/grok"
	"github.com/GuanceCloud/platypus/pkg/ast"
)

var errStackKeyNotFound = errors.New("not found")

const maxRetainedStackVars = 64

type Varb struct {
	Value any
	DType ast.DType
}

type Stack struct {
	Data   map[string]*Varb
	Before *Stack
	Next   *Stack
	free   []*Varb
	keys   []string

	CheckPattern map[string]*grok.GrokPattern
}

func NewStack() *Stack {
	return &Stack{
		Data: map[string]*Varb{},
	}
}

func (stack *Stack) SetPattern(patternAlias string, grokPattern *grok.GrokPattern) {
	if stack.CheckPattern == nil {
		stack.CheckPattern = make(map[string]*grok.GrokPattern)
	}
	stack.CheckPattern[patternAlias] = grokPattern
}

func (stack *Stack) GetPattern(pattern string) (*grok.GrokPattern, bool) {
	cur := stack

	for {
		// 在 cur stack
		if v, ok := cur.CheckPattern[pattern]; ok {
			return v, ok
		}
		// 尝试在上一级查找
		if cur.Before != nil {
			cur = cur.Before
		} else {
			break
		}
	}

	return nil, false
}

func (stack *Stack) Set(key string, value any, dType ast.DType) {
	cur := stack

	for {
		// 在 cur stack
		if v, ok := cur.Data[key]; ok {
			v.DType = dType
			v.Value = value
			return
		}
		// 尝试在上一级查找
		if cur.Before != nil {
			cur = cur.Before
		} else {
			break
		}
	}

	// new
	stack.SetLocal(key, value, dType)
}

func (stack *Stack) SetLocal(key string, value any, dType ast.DType) *Varb {
	if stack.Data == nil {
		stack.Data = map[string]*Varb{}
	}
	var v *Varb
	last := len(stack.free) - 1
	if last >= 0 {
		v = stack.free[last]
		stack.free[last] = nil
		stack.free = stack.free[:last]
	} else {
		v = &Varb{}
	}
	v.Value = value
	v.DType = dType
	stack.Data[key] = v
	stack.keys = append(stack.keys, key)
	return v
}

// func (stack *PlProcStack) SetLocal(key string, value any, dType DType) {
// 	stack.data[key] = &Varb{
// 		Name:  key,
// 		Value: value,
// 		DType: dType,
// 	}
// }

func (stack *Stack) Get(key string) (*Varb, error) {
	cur := stack

	for {
		// 在 cur stack
		if v, ok := cur.Data[key]; ok {
			return v, nil
		}
		// 尝试在上一级查找
		if cur.Before != nil {
			cur = cur.Before
		} else {
			break
		}
	}

	return nil, errStackKeyNotFound
}

func (stack *Stack) Clear() {
	stack.clearRetainingStorage()
}

func (stack *Stack) clearRetainingStorage() {
	stack.CheckPattern = nil
	if len(stack.Data) > maxRetainedStackVars {
		stack.Data = nil
		stack.free = nil
		stack.keys = nil
		return
	}
	for _, k := range stack.keys {
		v := stack.Data[k]
		if v == nil {
			continue
		}
		if len(stack.free) < maxRetainedStackVars {
			v.Value = nil
			v.DType = ast.Void
			stack.free = append(stack.free, v)
		}
		delete(stack.Data, k)
	}
	if cap(stack.keys) > maxRetainedStackVars {
		stack.keys = nil
	} else {
		stack.keys = stack.keys[:0]
	}
}

func (stack *Stack) ResetChain() {
	for stack != nil {
		next := stack.Next
		stack.Before = nil
		stack.clearRetainingStorage()
		stack = next
	}
}
