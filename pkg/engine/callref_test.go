// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package engine

import (
	"testing"

	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/funcs"
	"github.com/stretchr/testify/assert"
)

type testcase struct {
	desc   string
	script map[string]string
	err    map[string]string
}

func TestCallRefCheck(t *testing.T) {
	cases := []testcase{
		{
			desc: "0",
			script: map[string]string{
				"a.p": "use(\"b.p\")",
				"b.p": "a b",
			},
			err: map[string]string{
				"a.p": "b.p:1:3: unexpected: id \"b\"\na.p:1:1:",
				"b.p": "b.p:1:3: unexpected: id \"b\"",
			},
		},
		{
			desc: "1",
			script: map[string]string{
				"a.p": "use(\"b.p\")",
				"b.p": "use(\"c.p\")",
				"c.p": "use(\"x.p\")",
			},
			err: map[string]string{
				"a.p": "c.p:1:1: script x.p not found\nb.p:1:1:\na.p:1:1:",
				"b.p": "c.p:1:1: script x.p not found\nb.p:1:1:",
				"c.p": "c.p:1:1: script x.p not found",
			},
		},
		{
			desc: "2",
			script: map[string]string{
				"a.p": "use(\"b.p\")",
				"b.p": "use(\"c.p\")",
				"c.p": "use(\"b.p\")",
			},
			err: map[string]string{
				"a.p": "a.p:1:1: circular dependency: a.p -> b.p -> c.p -> b.p\nc.p:1:1:\nb.p:1:1:\na.p:1:1:",
				"b.p": "b.p:1:1: circular dependency: b.p -> c.p -> b.p\nc.p:1:1:\nb.p:1:1:",
				"c.p": "c.p:1:1: circular dependency: c.p -> b.p -> c.p\nb.p:1:1:\nc.p:1:1:",
			},
		},
		{
			desc: "3",
			script: map[string]string{
				"c.p": "a = 1; {1:2}",
			},
			err: map[string]string{"c.p": "c.p:1:9: map key expect string"},
		},
	}

	for _, c := range cases {
		_, retE := ParseScript(c.script, funcs.FuncsMap, funcs.FuncsCheckMap)
		actE := map[string]string{}
		for k, v := range retE {
			actE[k] = v.Error()
		}
		assert.Equal(t, c.err, actE)
	}
}
