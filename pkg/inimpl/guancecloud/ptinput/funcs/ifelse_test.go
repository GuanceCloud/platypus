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

func TestIfelse(t *testing.T) {
	cases := []struct {
		name   string
		pl, in string
		expect interface{}
		fail   bool
	}{
		{
			name: "valind-key-is-nil",
			in:   `1.2.3.4 "POST /?signature=b8d8ea&timestamp=1638171049 HTTP/1.1" 200 413`,
			pl: `
grok(_, "%{IPORHOST:client_ip} \"%{DATA} %{GREEDYDATA} HTTP/%{NUMBER}\" %{INT:status_code} %{INT:bytes}")

if invalid_status_code == nil {
  add_key(add_new_key, "OK")
}
`,
			expect: "OK",
		},
		{
			name: "if 1",
			in:   ``,
			pl: `
if 1 {
	add_key(add_new_key, "OK")
}
`,
			expect: "OK",
		},
		{
			name: "if 1.1",
			in:   ``,
			pl: `
if 1.1 {
	add_key(add_new_key, "OK")
}
`,
			expect: "OK",
		},

		{
			name: "if 0",
			in:   ``,
			pl: `
if 0 {
	add_key(add_new_key, "OK")
}
`,
			expect: nil,
		},
		{
			name: "if true",
			in:   ``,
			pl: `
if true {
	add_key(add_new_key, "OK")
}
`,
			expect: "OK",
		},
		{
			name: "if string",
			in:   ``,
			pl: `
if "str" {
	add_key(add_new_key, "OK")
}
`,
			expect: "OK",
		},
		{
			name: "if nil",
			in:   ``,
			pl: `
if nil {
	add_key(add_new_key, "OK")
}
`,
			expect: nil,
		},
		{
			name: "if [123]",
			in:   ``,
			pl: `
if [123] {
	add_key(add_new_key, "OK")
}
`,
			expect: "OK",
		},
		{
			name: "if LEN([123])",
			in:   ``,
			pl: `
if len([123]) {
	add_key(add_new_key, "OK")
}
`,
			expect: "OK",
		},
		{
			name: "invalid-key-is-not-nil",
			in:   `1.2.3.4 "POST /?signature=b8d8ea&timestamp=1638171049 HTTP/1.1" 200 413`,
			pl: `
grok(_, "%{IPORHOST:client_ip} \"%{DATA} %{GREEDYDATA} HTTP/%{NUMBER}\" %{INT:status_code} %{INT:bytes}")

if invalid_status_code != nil {
  add_key(add_new_key, "OK")
}
`,
			fail: true,
		},
		// 		{
		// 			name: "if expr func",
		// 			in:   `pd`,
		// 			pl: `
		// if match(_, "p([a-z]+)ch"){
		//    add_key(add_new_key, "OK")
		// }
		// `,
		// 			fail: true,
		// 		},
		// 		{
		// 			name: "if expr func",
		// 			in:   `pddeech`,
		// 			pl: `
		// if match(_, "p([a-z]+)ch")  {
		//    add_key(add_new_key, "OK")
		// }
		// `,
		// 			expect: "OK",
		// 		},
	}
	for idx, tc := range cases {
		t.Run(tc.name, func(t *testing.T) {
			runner, err := NewTestingRunner(tc.pl)
			if err != nil {
				if tc.fail {
					t.Logf("[%d]expect error: %s", idx, err)
				} else {
					t.Log(tc.pl)
					t.Errorf("[%d] failed: %s", idx, err)
				}
				return
			}

			pt := ptinput.NewPlPoint(
				point.Logging, "test", nil, map[string]any{"message": tc.in}, time.Now())
			errR := runScript(runner, pt)

			if errR != nil {
				t.Fatal(errR)
			}

			v, _, _ := pt.GetWithIsTag("add_new_key")
			tu.Equals(t, tc.expect, v)
			t.Logf("[%d] PASS", idx)
		})
	}
}
