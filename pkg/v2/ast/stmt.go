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

	ForPos token.LnColPos
}

func (e *ForStmt) String() string {
	return "for stmt"
}

type BlockStmt struct {
	LBracePos token.LnColPos
	RBracePos token.LnColPos
	Stmts     Stmts
}

func (block *BlockStmt) String() string {
	var arr []string
	for _, x := range block.Stmts {
		arr = append(arr, x.String())
	}
	return strings.Join(arr, "\n")
}

type ImportStmt struct {
	ImportPos token.LnColPos
	AsPos     token.LnColPos

	Name   []*Identifier
	AsName *Identifier
}

type PackageStmt struct {
	PkgPos token.LnColPos

	Name *Identifier
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

	FnType *TypeFn

	Block Node
}

func (f *FnDefStmt) String() string {
	s := f.Block.String()
	if len(s) > 0 {
		return "fn " + f.FnType.string() + "{\n" + s + "\n}"
	} else {
		return "fn " + f.FnType.string() + "{\n}"
	}
}

type TypeDefStmt struct {
	TypePos token.LnColPos

	Name *Identifier

	Type TypeNode
}
