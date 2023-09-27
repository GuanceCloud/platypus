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

func TestDelete(t *testing.T) {
	cases := []struct {
		name, pl, in string
		expected     interface{}
		fail         bool
		outkey       string
	}{
		{
			name: "delete_map",
			pl: `
			a=load_json(_)
			 delete(a["a"][-1], "b")
			 add_key(a)`,
			in:       `{"a":[1, {"b":2}]}`,
			expected: "{\"a\":[1,{}]}",
			outkey:   "a",
		},
		{
			pl: `j_map = load_json(_)

			delete(j_map["b"][-1], "c")
			
			delete(j_map, "a")
			
			add_key("j_map", j_map)`,
			in:       `{"a": "b", "b":[0, {"c": "d"}], "e": 1}`,
			expected: "{\"b\":[0,{}],\"e\":1}",
			outkey:   "j_map",
		},
		{
			name: "delete_map",
			pl: `
			a=load_json(_)
			 delete(a, "a")
			 add_key(a)`,
			in:       `{"a":[1, {"b":2}]}`,
			expected: "{}",
			outkey:   "a",
		},
		{
			name: "delete_map",
			pl: `
			a=load_json(_)
			 delete(a["a"], "b")
			 add_key(a)`,
			in:       `{"a":[1, {"b":2}]}`,
			expected: "{\"a\":[1,{\"b\":2}]}",
			outkey:   "a",
		},
		{
			name: "delete_map",
			pl: `
			a=load_json(_)
			 delete(b, "b")
			 add_key(a)`,
			in:       `{"a":[1, {"b":2}]}`,
			expected: "{\"a\":[1,{\"b\":2}]}",
			outkey:   "a",
		},
		{
			name: "delete_map",
			pl: `
			a=load_json(_)
			 delete(a["a"][-7], "b")
			 add_key(a)`,
			in:       `{"a":[1, {"b":2}]}`,
			expected: "{\"a\":[1,{\"b\":2}]}",
			outkey:   "a",
		},
		{
			name: "delete_map",
			pl: `
			a=load_json(_)
			 delete(b, x)
			 add_key(a)`,
			in:       `{"a":[1, {"b":2}]}`,
			expected: "{\"a\":[1,{\"b\":2}]}",
			outkey:   "a",
			fail:     true,
		},
	}

	for idx, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			runner, err := NewTestingRunner(tc.pl)
			if err != nil {
				if tc.fail {
					t.Logf("[%d]expect error: %s", idx, err)
				} else {
					t.Errorf("[%d] failed: %s", idx, err)
				}
				return
			}
			pt := ptinput.NewPlPoint(
				point.Logging, "test", nil, map[string]any{"message": tc.in}, time.Now())
			errR := runScript(runner, pt)
			if errR != nil {
				t.Fatal(*errR)
			}

			v, isTag, ok := pt.GetWithIsTag(tc.outkey)

			assert.Equal(t, true, ok)
			assert.Equal(t, false, isTag)
			assert.Equal(t, tc.expected, v)
			t.Logf("[%d] PASS", idx)
		})
	}
}
