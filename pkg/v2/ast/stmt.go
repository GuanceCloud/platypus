// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package ast

import (
	"strings"

	"github.com/GuanceCloud/platypus/pkg/token"
)

type IfelseStmt struct {
	IfList IfList
	Else   *BlockStmt

	Label int

	ElsePos token.LnColPos
}

func (e *IfelseStmt) IsExpr() bool {
	return false
}

func (e *IfelseStmt) String() string {
	arr := []string{e.IfList.String()}
	if e.Else != nil && len(e.Else.Stmts) != 0 {
		arr = append(arr, "else", "{", e.Else.String(), "}")
	}
	return strings.Join(arr, " ")
}

// IfList index [0] is IF, [1..end] is ELIF.
type IfList []*IfStmtElem

func (e IfList) String() string {
	if len(e) == 0 {
		return ""
	}
	arr := []string{"if", e[0].String()}
	for i := 1; i < len(e); i++ {
		arr = append(arr, "elif", e[i].String())
	}
	return strings.Join(arr, " ")
}

type IfStmtElem struct {
	Condition Node
	Block     *BlockStmt

	Start token.LnColPos
}

func (e *IfStmtElem) String() string {
	arr := []string{e.Condition.String(), "{", e.Block.String(), "}"}
	return strings.Join(arr, " ")
}

type BreakStmt struct {
	Start token.LnColPos
}

func (e *BreakStmt) String() string {
	return "break"
}

type ContinueStmt struct {
	Start token.LnColPos
}

func (e *ContinueStmt) String() string {
	return "continue"
}

type ForInStmt struct {
	InExpr Node
	Body   *BlockStmt

	Label int
	SymTb int

	ForPos token.LnColPos
}

func (e *ForInStmt) String() string {
	return "for in stmt"
}

type ForStmt struct {
	// init
	Init Node

	// step1: -> step2 or break
	Cond Node

	// step3: -> step1
	Loop Node

	// step2: -> step3
	Body *BlockStmt

	Label int
	SymTb int

	ForPos token.LnColPos
}

func (e *ForStmt) String() string {
	return "for stmt"
}

type BlockStmt struct {
	LBracePos token.LnColPos
	RBracePos token.LnColPos

	Label int
	Table int

	Stmts Stmts
}

func (block *BlockStmt) String() string {
	var arr []string
	for _, x := range block.Stmts {
		arr = append(arr, x.String())
	}
	return strings.Join(arr, "\n")
}

type ReturnStmt struct {
	ReturnPos token.LnColPos
	Exprs     []Node
}

func (r *ReturnStmt) String() string {
	var params []string
	for _, x := range r.Exprs {
		params = append(params, x.String())
	}
	if len(params) > 0 {
		return "return " + strings.Join(params, ", ")
	}
	return "return"
}

type FnDefStmt struct {
	FnPos          token.LnColPos
	LParen, RParen token.LnColPos

	RetPos               token.LnColPos
	RetLParen, RetRParen token.LnColPos

	Name Node

	Label int
	Table int

	FnType *TypeFn

	Block *BlockStmt
}

func (f *FnDefStmt) String() string {
	s := f.Block.String()
	if len(s) > 0 {
		return "fn " + f.FnType.string() + "{\n" + s + "\n}"
	} else {
		return "fn " + f.FnType.string() + "{\n}"
	}
}

type LetStmt struct {
	LetPos token.LnColPos
	Name   *Identifier
	Type   Node
	Value  Node
}

func (v *LetStmt) String() string {
	s := "let " + v.Name.String()
	if v.Type != nil {
		s += ": " + v.Type.String() + " "
	}
	if v.Value != nil {
		s += "= " + v.Value.String()
	}
	return s
}

type ConstDefStmt struct {
	ConstPos token.LnColPos
	Name     Node
	Value    Node
}

func (c *ConstDefStmt) String() string {
	return "const " + c.Name.String() + " = " + c.Value.String()
}

type ImportStmt struct {
	ImportPos token.LnColPos
	AsPos     token.LnColPos

	Name   []*Identifier
	AsName *Identifier
}

func (i *ImportStmt) String() string {
	var pkgNames []string
	for _, x := range i.Name {
		pkgNames = append(pkgNames, x.String())
	}

	s := "import " + strings.Join(pkgNames, ", ")
	if i.AsName != nil {
		s += " as " + i.AsName.String()
	}

	return s
}
