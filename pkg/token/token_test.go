// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package token used
package token

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

type dataPos struct {
	query string
	pos   [][4]int
}

func TestPosCache(t *testing.T) {
	testCases := []dataPos{
		{
			query: `0123

`,
			pos: [][4]int{
				{0, 1, 1, '0'},
				{5, 2, 1, '\n'},
			},
		},
		{
			query: `0123
56
09
abcde
ght
a`,
			pos: [][4]int{
				{0, 1, 1, '0'},
				{5, 2, 1, '5'},
				{17, 5, 1, 'g'},
				{21, 6, 1, 'a'},
			},
		},
		{
			query: `0123
56
09


abcde
ght

`,
			pos: [][4]int{
				{0, 1, 1, '0'},
				{5, 2, 1, '5'},
				{19, 7, 1, 'g'},
				{22, 7, 4, '\n'},
				{23, 8, 1, '\n'},
			},
		},
	}

	for idx, c := range testCases {
		nC := NewPosCache(c.query)
		for ix, v := range c.pos {
			pos := nC.LnCol(Pos(v[0]))
			if pos == InvalidLnColPos {
				t.Fatal(idx, " ", ix, " InvalidPos")
			}
			assert.Equal(t, pos.Ln, v[1], "ln not eq")
			assert.Equal(t, pos.Col, v[2], "col not eq")
			assert.Equal(t, v[3], int(c.query[v[0]]))
		}
	}
}
