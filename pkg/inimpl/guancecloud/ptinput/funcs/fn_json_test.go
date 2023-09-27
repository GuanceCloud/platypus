// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"testing"
	"time"

	"github.com/GuanceCloud/cliutils/point"
	tu "github.com/GuanceCloud/cliutils/testutil"
	"github.com/GuanceCloud/platypus/pkg/inimpl/guancecloud/ptinput"
	"github.com/stretchr/testify/assert"
)

func TestJSON(t *testing.T) {
	testCase := []*funcCase{
		{
			in: `{
			  "name": {"first": "Tom", "last": "Anderson"},
			  "age":37,
			  "children": ["Sara","Alex","Jack"],
			  "fav.movie": "Deer Hunter",
			  "friends": [
			    {"first": "Dale", "last": "Murphy", "age": 44, "nets": ["ig", "fb", "tw"]},
			    {"first": "Roger", "last": "Craig", "age": 68, "nets": ["fb", "tw"]},
			    {"first": "Jane", "last": "Murphy", "age": 47, "nets": ["ig", "tw"]}
			  ]
			}`,
			script: `json(_, name)
			json(name, first)`,
			expected: "Tom",
			key:      "first",
		},
		{
			in: `{
			  "name": {"first": "Tom", "last": "Anderson"},
			  "age":37,
			  "children": ["Sara","Alex","Jack"],
			  "fav.movie": "Deer Hunter",
			  "friends": [
			    {"first": "Dale", "last": "Murphy", "age": 44, "nets": ["ig", "fb", "tw"]},
			    {"first": "Roger", "last": "Craig", "age": 68, "nets": ["fb", "tw"]},
			    {"first": "Jane", "last": "Murphy", "age": 47, "nets": ["ig", "tw"]}
			  ]
			}`,
			script: `json(_, friends)
			json(friends, .[1].first, f_first)`,
			expected: "Roger",
			key:      "f_first",
		},
		{
			in: `[
				    {"first": "Dale", "last": "Murphy", "age": 44, "nets": ["ig", "fb", "tw"]},
				    {"first": "Roger", "last": "Craig", "age": 68, "nets": ["fb", "tw"]},
				    {"first": "Jane", "last": "Murphy", "age": 47, "nets": ["ig", "tw"]}
				]`,
			script:   `json(_, .[0].nets[-1])`,
			expected: "tw",
			key:      "[0].nets[-1]",
		},
		{
			in: `[
				    {"first": "Dale", "last": "Murphy", "age": 44, "nets": ["ig", "fb", "tw"]},
				    {"first": "Roger", "last": "Craig", "age": 68, "nets": ["fb", "tw"]},
				    {"first": "Jane", "last": "Murphy", "age": 47, "nets": ["ig", "tw"]}
				]`,
			script:   `json(_, .[1].age)`,
			expected: float64(68),
			key:      "[1].age",
		},
		{
			name:     "trim_space auto",
			in:       `{"item": " not_space "}`,
			script:   `json(_, item, item)`,
			key:      "item",
			expected: "not_space",
		},
		{
			name:     "trim_space disable",
			in:       `{"item": " not_space "}`,
			script:   `json(_, item, item, false)`,
			key:      "item",
			expected: " not_space ",
		},
		{
			name:     "trim_space enable",
			in:       `{"item": " not_space "}`,
			script:   `json(_, item, item, true)`,
			key:      "item",
			expected: "not_space",
		},
		{
			name:     "map_delete_after",
			in:       `{"item": " not_space "}`,
			script:   `json(_, item, item, true, true)`,
			key:      "message",
			expected: "{}",
			fail:     false,
		},
		{
			name:     "map_delete_after1",
			in:       `{"item": " not_space ", "item2":{"item3": [123]}}`,
			script:   `json(_, item2.item3, item, delete_after_extract = true)`,
			key:      "message",
			expected: `{"item":" not_space ","item2":{}}`,
		},
		{
			name:     "list_delete_after1",
			in:       `{"item": " not_space ", "item2": [[1,2,3,4,5],[6]]}`,
			script:   `json(_, .[0].item2[0][2].a[0], item, true, true)`,
			key:      "item",
			expected: "1",
			fail:     true,
		},
		{
			name:     "list_delete_after2",
			in:       `{"item": " not_space ", "item2": [[1,2,3,4,5],[6]]}`,
			script:   `json(_, .[0], item, true, true)`,
			key:      "item",
			expected: "1",
			fail:     true,
		},
		{
			name:     "list_delete_after3",
			in:       `{"item": " not_space ", "item2": [[1,2,3,4,5],[6]]}`,
			script:   `json(_, a[0][1], item, true, true)`,
			key:      "item",
			expected: "1",
			fail:     true,
		},
	}

	for idx, tc := range testCase {
		t.Run(tc.name, func(t *testing.T) {
			runner, err := NewTestingRunner(tc.script)

			if err != nil && tc.fail {
				return
			} else if err != nil || tc.fail {
				tu.Equals(t, nil, err)
				tu.Equals(t, tc.fail, err != nil)
			}

			pt := ptinput.NewPlPoint(
				point.Logging, "test", nil, map[string]any{"message": tc.in}, time.Now())
			errR := runScript(runner, pt)
			if errR != nil {
				t.Fatal(errR.Error())
			}

			r, _, ok := pt.GetWithIsTag(tc.key)
			tu.Equals(t, true, ok)
			if tc.key == "[2].age" {
				t.Log(1)
			}
			assert.Equal(t, tc.expected, r)

			t.Logf("[%d] PASS", idx)
		})
	}
}
