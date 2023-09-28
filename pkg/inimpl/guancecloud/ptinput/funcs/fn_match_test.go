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

func TestMatch(t *testing.T) {
	cases := []struct {
		name, pl, in string
		expected     interface{}
		fail         bool
		outkey       string
	}{
		{
			name: "normal",
			pl: `abc = "sss"
			add_key(abc, match("\\w+", abc))`,
			in:       `test`,
			expected: true,
			outkey:   "abc",
		},
		{
			name: "normal",
			pl: `abc = "sss"
			add_key(abc, match("sss", abc))`,
			in:       `test`,
			expected: true,
			outkey:   "abc",
		},
		{
			name: "normal",
			pl: `abc = "sss"
			add_key(abc, match(abc, abc))`,
			in:       `test`,
			expected: true,
			outkey:   "abc",
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
				t.Fatal(errR.Error())
			}

			v, _, _ := pt.Get(tc.outkey)
			// tu.Equals(t, nil, err)
			assert.Equal(t, tc.expected, v)

			t.Logf("[%d] PASS", idx)
		})
	}
}
