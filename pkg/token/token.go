// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

// Package token used
package token

import "fmt"

type Pos int32

func LnCol(query string, pos Pos) (int, int, error) {
	lastLineBrk := -1
	ln := 1

	if pos < 0 || int(pos) > len(query) {
		return 0, 0, fmt.Errorf("invalid position")
	}
	for i, c := range query[:pos] {
		if c == '\n' {
			lastLineBrk = i
			ln++
		}
	}

	return ln, int(pos) - lastLineBrk, nil
}
