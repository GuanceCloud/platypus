// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package errchain

import (
	"fmt"
	"strings"

	"github.com/GuanceCloud/platypus/pkg/token"
)

type FilePos struct {
	FilePath string
	Ln       int
	Col      int
}

type PlError struct {
	pos []FilePos
	err string
}

type PlErrors []PlError

func (e PlErrors) Error() string {
	errs := []string{}
	for _, v := range e {
		errs = append(errs, v.Error())
	}
	return strings.Join(errs, "\n")
}

func (e *PlError) Error() string {
	if len(e.pos) == 0 {
		return ""
	}

	var errr string

	for i := 0; i < len(e.pos); i++ {
		pos := e.pos[i]
		if i == 0 {
			errr += fmt.Sprintf("%s:%d:%d: %s", pos.FilePath, pos.Ln, pos.Col, e.err)
		} else {
			errr += fmt.Sprintf(
				"\n%s:%d:%d:", e.pos[i].FilePath,
				e.pos[i].Ln, e.pos[i].Col)
		}
	}
	return errr
}

func (e *PlError) ChainAppend(filepath string, pos token.LnColPos) *PlError {
	e.pos = append(e.pos, FilePos{
		Ln:       pos.Ln,
		Col:      pos.Col,
		FilePath: filepath,
	})
	return e
}

func (e *PlError) Copy() *PlError {
	return &PlError{
		err: e.err,
		pos: append([]FilePos{}, e.pos...),
	}
}

func NewErr(filepath string, pos token.LnColPos, err string) *PlError {
	return &PlError{
		pos: []FilePos{
			{
				FilePath: filepath,
				Col:      pos.Col,
				Ln:       pos.Ln,
			},
		},
		err: err,
	}
}
