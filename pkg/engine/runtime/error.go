// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package runtime

import (
	"fmt"

	"github.com/GuanceCloud/platypus/pkg/token"
)

type FilePos struct {
	Pos token.Pos

	Name string

	Ln  int
	Col int
}

type RuntimeError struct {
	pos []FilePos
	err string
}

func (e *RuntimeError) ChainError() error {
	if len(e.pos) == 0 {
		return nil
	}

	var errr string

	for i := 0; i < len(e.pos); i++ {
		pos := e.pos[i]
		if i == 0 {
			errr += fmt.Sprintf("%s:%d:%d: %s", pos.Name, pos.Ln, pos.Col, e.err)
		} else {
			errr += fmt.Sprintf(
				"\n%s:%d:%d:", e.pos[i].Name,
				e.pos[i].Ln, e.pos[i].Col)
		}
	}

	return fmt.Errorf(errr)
}

func (e *RuntimeError) LastError() error {
	if len(e.pos) > 0 {
		pos := e.pos[0]
		return fmt.Errorf("%s:%d:%d: %s", pos.Name, pos.Ln, pos.Col, e.err)
	}
	return fmt.Errorf(e.err)
}

// func (e *RuntimeError) callChain() []FilePos {
// 	ret := []FilePos{}

// 	for i := len(e.pos) - 1; i >= 0; i-- {
// 		ret = append(ret, e.pos[i])
// 	}
// 	return ret
// }

func (e *RuntimeError) ChainAppend(ctx *Context, pos token.Pos) *RuntimeError {
	ln, col, _ := token.LnCol(ctx.content, pos)
	e.pos = append(e.pos, FilePos{
		Pos:  pos,
		Ln:   ln,
		Col:  col,
		Name: ctx.name,
	})
	return e
}

func NewRunError(ctx *Context, err string, pos token.Pos) *RuntimeError {
	runErr := &RuntimeError{
		err: err,
	}

	return runErr.ChainAppend(ctx, pos)
}
