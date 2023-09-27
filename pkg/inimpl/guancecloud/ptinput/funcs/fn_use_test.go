// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"testing"
	"time"

	"github.com/GuanceCloud/cliutils/point"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/ptinput"
	"github.com/stretchr/testify/assert"
)

func TestUse(t *testing.T) {
	case1 := map[string]string{
		"a.p": "if true {use(\"b.p\")}",
		"b.p": "add_key(b,1)",
		"d.p": "use(\"c.p\")",
		"c.p": "use(\"a.p\") use(\"d.p\") use(\"fcName.p\")",
	}

	ret := [2][]string{
		{"a.p", "b.p"},
		{"d.p", "c.p"},
	}

	timenow := time.Now()

	ret1, ret2 := NewTestingRunner2(case1)
	assert.Equal(t, len(ret[0]), len(ret1))
	assert.Equal(t, len(ret[1]), len(ret2))

	for _, v := range ret[0] {
		if _, ok := ret1[v]; !ok {
			t.Error(v)
		}
	}

	for _, v := range ret[1] {
		if _, ok := ret2[v]; !ok {
			t.Error(v)
		}
	}

	for _, name := range ret[0] {
		pt := ptinput.NewPlPoint(
			point.Network, "default", map[string]string{"ax": "1"}, nil, timenow)

		errR := runScript(ret1[name], pt)

		if errR != nil {
			t.Fatal(errR)
		}
		assert.Equal(t, map[string]string{"ax": "1"}, pt.Tags())
		assert.Equal(t, map[string]interface{}{"b": int64(1)}, pt.Fields())
		assert.Equal(t, false, pt.Dropped())
		assert.Equal(t, "default", pt.GetPtName())
	}
}
