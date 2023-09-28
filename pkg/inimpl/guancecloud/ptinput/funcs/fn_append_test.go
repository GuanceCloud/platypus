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

func TestAppend(t *testing.T) {
	cases := []struct {
		name, pl, in string
		expected     interface{}
		fail         bool
		outkey       string
	}{
		{
			name: "append a float number",
			pl: `abc = ["1", "2"]
			abc = append(abc, 5.1)
			add_key(arr, abc)`,
			in:       `test`,
			expected: "[\"1\",\"2\",5.1]",
			outkey:   "arr",
		},
		{
			name: "append a string",
			pl: `abc = ["hello"]
			abc = append(abc, "world")
			add_key(arr, abc)`,
			in:       `test`,
			expected: "[\"hello\",\"world\"]",
			outkey:   "arr",
		},
		{
			name: "append a string",
			pl: `abc = [1, 2]
			abc = append(abc, "3")
			add_key(arr, abc)`,
			in:       `test`,
			expected: "[1,2,\"3\"]",
			outkey:   "arr",
		},
		{
			name: "append by Identifier",
			pl: `a = [1, 2]
			b = append(a, 3)
			add_key(arr, b)`,
			in:       `test`,
			expected: "[1,2,3]",
			outkey:   "arr",
		},
		{
			name: "append an array",
			pl: `a = [1, 2]
			b = [3, 4]
			c = append(a, b)
			add_key(arr, c)`,
			in:       `test`,
			expected: "[1,2,[3,4]]",
			outkey:   "arr",
		},
		{
			name: "append but not assign",
			pl: `a = [1, 2]
			b = 3
			append(a, b)
			add_key(arr, a)`,
			in:       `test`,
			expected: "[1,2]",
			outkey:   "arr",
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
			assert.Equal(t, tc.expected, v)
			assert.Equal(t, false, isTag)
			t.Logf("[%d] PASS", idx)
		})
	}
}
