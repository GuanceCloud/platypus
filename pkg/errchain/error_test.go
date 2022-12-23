// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package errchain

import (
	"bytes"
	"encoding/json"
	"testing"

	"github.com/GuanceCloud/platypus/pkg/token"
	"github.com/stretchr/testify/assert"
)

func TestConvPlErr2Json(t *testing.T) {
	query := `a = 1
b=2
`

	pcache := token.NewPosCache(query)
	err := NewErr("abc.p", pcache.LnCol(token.Pos(0)), "err")

	err = err.ChainAppend("d.p", pcache.LnCol(token.Pos(7)))

	errJSON := "{\"pos_chain\":[{\"file\":\"abc.p\",\"ln\":1,\"col\":1,\"pos\":0}," +
		"{\"file\":\"d.p\",\"ln\":2,\"col\":2,\"pos\":7}],\"error\":\"err\"}\n"

	w := bytes.NewBuffer([]byte{})
	encoder := json.NewEncoder(w)
	if e := encoder.Encode(err); e != nil {
		t.Fatal(e)
	}

	assert.Equal(t, errJSON, w.String())

	assert.Equal(t, "abc.p:1:1: err\nd.p:2:2:", err.Error())
}
