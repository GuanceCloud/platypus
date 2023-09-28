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
)

func TestTrim(t *testing.T) {
	cases := []struct {
		name, pl, in string
		outkey       string
		expect       interface{}
		fail         bool
	}{
		{
			name: "trim space",
			in:   `trim space`,
			pl: `
			item = " not_space "
			trim(item)
	`,
			outkey: "item",
			expect: "not_space",
			fail:   false,
		},
		{
			name: "trim ABC_-",
			in:   `trim ABC_-`,
			pl: `
			item = "BC_-AAACAnot_spaceABACC"
			trim(item, "ABC_-")
	`,
			outkey: "item",
			expect: "not_space",
			fail:   false,
		},
		{
			name: "trim ABC_",
			in:   `trim ABC_`,
			pl: `
			add_key(test_data, "ACCAA_test_DataA_ACBA")
			trim(test_data, "ABC_")
	`,
			outkey: "test_data",
			expect: "test_Data",
			fail:   false,
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
			tu.Equals(t, tc.expect, v)
			t.Logf("[%d] PASS", idx)
		})
	}
}
