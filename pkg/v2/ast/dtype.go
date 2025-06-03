// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package ast

import (
	"bytes"

	"github.com/GuanceCloud/platypus/pkg/token"
)

type DType uint

func (t DType) String() string {
	switch t {
	case Invalid:
		return "invalid"
	case Bool:
		return "bool"
	case Int:
		return "int"
	case Float:
		return "float"
	case String:
		return "str"
	case List:
		return "list"
	case Map:
		return "map"
	case Func:
		return "func"
	case Class:
		return "class"
	}
	return ""
}

const (
	Invalid DType = iota

	Any // any

	Bool
	Int    // int64
	Float  // float64
	String // string

	List
	Map

	Class

	Func
)

func AllTyp() []DType {
	return []DType{Bool, Int, Float, String, List, Map, Class, Func}
}

type TypeNode interface {
	IsType()
	String() string
}

type TypeID struct {
	Name Node
}

func (*TypeID) IsType() {}
func (t *TypeID) String() string {
	return t.Name.String()
}

type FnParam struct {
	Name       Node
	DType      Node
	Varb       bool
	DefaultVal Node
}

func (p *FnParam) String() string {
	s := p.Name.String()
	if p.DType != nil {
		if p.Varb {
			s += ": ..." + p.DType.String()
		} else {
			s += ": " + p.DType.String()
		}
	} else if p.Varb {
		s += ": ..."
	}
	if p.DefaultVal != nil {
		s += " = " + p.DefaultVal.String()
	}
	return s
}

type TypeFn struct {
	Params  []FnParam
	Results []Node
}

func (*TypeFn) IsType() {}

func (t *TypeFn) String() string {
	return "fn " + t.string()
}

func (t *TypeFn) string() string {
	b := bytes.NewBuffer([]byte{})
	b.WriteString("(")
	for i, p := range t.Params {
		b.WriteString(p.String())
		if i < len(t.Params)-1 {
			b.WriteString(", ")
		}
	}
	b.WriteString(")")
	if len(t.Results) > 0 {
		b.WriteString(" -> ")
	}

	if len(t.Results) > 1 {
		b.WriteString("(")
	}
	for i, r := range t.Results {
		b.WriteString(r.String())
		if i < len(t.Results)-1 {
			b.WriteString(", ")
		}
	}
	if len(t.Results) > 1 {
		b.WriteString(")")
	}

	return b.String()
}

type TypeClass struct {
	Fields  []Node
	Methods []Node
}

func (*TypeClass) IsType() {}

type TypeMap struct {
	KeyType   Node
	ValueType Node
}

func (t *TypeMap) String() string {
	return "map"
}
func (*TypeMap) IsType() {}

type TypeList struct {
	VType Node
}

func (t *TypeList) String() string {
	return "list"
}

func (*TypeList) IsType() {}

type TypeArray struct {
	LBracketPos token.LnColPos
	RBracketPos token.LnColPos

	VType Node
	Len   Node
}

type TypeBasic struct {
	Pos   token.LnColPos
	DType DType
}

func (*TypeBasic) IsType() {}

func (t *TypeBasic) String() string {
	return t.DType.String()
}
