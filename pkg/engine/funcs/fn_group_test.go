// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"testing"
	"time"

	"github.com/stretchr/testify/assert"
)

func TestGroup(t *testing.T) {
	cases := []struct {
		name, pl, in string
		expected     interface{}
		fail         bool
		outkey       string
	}{
		{
			name: "normal",
			pl: `json(_, status)
			 group_between(status, [200, 400], false, newkey)`,
			in:       `{"status": 200,"age":47}`,
			expected: false,
			outkey:   "newkey",
		},
		{
			name: "normal",
			pl: `json(_, status)
			 group_between(status, [200, 400], 10, newkey)`,
			in:       `{"status": 200,"age":47}`,
			expected: int64(10),
			outkey:   "newkey",
		},
		{
			name: "normal",
			pl: `json(_, status)
			 group_between(status, [200, 400], "ok", newkey)`,
			in:       `{"status": 200,"age":47}`,
			expected: "ok",
			outkey:   "newkey",
		},
		{
			name: "normal",
			pl: `json(_, status)
			 group_between(status, [200, 299], "ok")`,
			in:       `{"status": 200,"age":47}`,
			expected: "ok",
			outkey:   "status",
		},
		{
			name: "normal",
			pl: `json(_, status)
			 group_between(status, [200, 299], "ok", newkey)`,
			in:       `{"status": 200,"age":47}`,
			expected: "ok",
			outkey:   "newkey",
		},
		{
			name: "normal",
			pl: `json(_, status)
			 group_between(status, [300, 400], "ok", newkey)`,
			in:       `{"status": 200,"age":47}`,
			expected: nil,
			outkey:   "newkey",
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
			_, _, f, _, _, err := runScript(runner, "test", nil, map[string]interface{}{
				"message": tc.in,
			}, time.Now())

			assert.Equal(t, nil, err)

			t.Log(f)

			v := f[tc.outkey]
			// assert.Equal(t, nil, err)
			assert.Equal(t, tc.expected, v)

			t.Logf("[%d] PASS", idx)
		})
	}
}
