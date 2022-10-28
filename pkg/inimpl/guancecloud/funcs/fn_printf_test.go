// Unless explicitly stated otherwise all files in this repository are licensed
// under the MIT License.
// This product includes software developed at Guance Cloud (https://www.guance.com/).
// Copyright 2021-present Guance, Inc.

package funcs

import (
	"testing"
	"time"
)

func TestPrintf(t *testing.T) {
	cases := []struct {
		name, pl, in string
		expected     interface{}
		fail         bool
		outkey       string
	}{
		{
			name: "normal",
			pl: `
			count = 10
			a= "count %d\n"
			printf(a, count)
	`,
			expected: nil,
			outkey:   "",
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
			_, _, _, _, _, err = runScript(runner, "test", nil, map[string]interface{}{
				"message": tc.in,
			}, time.Now())

			if err != nil {
				t.Error(err)
			}
		})
	}
}
