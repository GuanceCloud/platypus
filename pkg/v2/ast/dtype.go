// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package ast

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
}

type TypeID struct {
	Name Node
}

func (*TypeID) IsType() {}

type TypeFn struct {
	Params  []Node
	Results []Node
}

func (*TypeFn) IsType() {}

type TypeClass struct {
	Fields  []Node
	Methods []Node
}

func (*TypeClass) IsType() {}

type TypeMap struct {
	KeyType   Node
	ValueType Node
}

func (*TypeMap) IsType() {}

type TypeList struct {
	VType Node
}

func (*TypeList) IsType() {}
