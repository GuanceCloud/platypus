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

func TestSetTag(t *testing.T) {
	cases := []struct {
		name, pl, in string
		outtag       string
		expect       string
		fail         bool
	}{
		{
			name: "set_tag 0",
			in:   `162.62.81.1 - - [29/Nov/2021:07:30:50 +0000] "123 /?signature=b8d8ea&timestamp=1638171049 HTTP/1.1" 200 413 "-" "Mozilla/4.0"`,
			pl: `
		set_tag(client_ip)
		grok(_, "%{IPORHOST:client_ip} %{NOTSPACE} %{NOTSPACE} \\[%{HTTPDATE:time}\\] \"%{DATA:data} %{GREEDYDATA} HTTP/%{NUMBER}\" %{INT:status_code} %{INT:bytes}")
		cast(data, "int")

		`,
			outtag: "client_ip",
			expect: "162.62.81.1",
			fail:   false,
		},
		{
			name: "set_tag 2",
			in:   `162.62.81.1 - - [29/Nov/2021:07:30:50 +0000] "123 /?signature=b8d8ea&timestamp=1638171049 HTTP/1.1" 200 413 "-" "Mozilla/4.0"`,
			pl: `
		grok(_, "%{IPORHOST:client_ip} %{NOTSPACE} %{NOTSPACE} \\[%{HTTPDATE:time}\\] \"%{DATA:data} %{GREEDYDATA} HTTP/%{NUMBER}\" %{INT:status_code} %{INT:bytes}")
		set_tag(client_ip)
		cast(data, "int")

		`,
			outtag: "client_ip",
			expect: "162.62.81.1",
			fail:   false,
		},
		{
			name: "set_tag 1",
			in:   `162.62.81.1 - - [29/Nov/2021:07:30:50 +0000] "123 /?signature=b8d8ea&timestamp=1638171049 HTTP/1.1" 200 413 "-" "Mozilla/4.0"`,
			pl: `
		grok(_, "%{IPORHOST:client_ip} %{NOTSPACE} %{NOTSPACE} \\[%{HTTPDATE:time}\\] \"%{DATA:data} %{GREEDYDATA} HTTP/%{NUMBER}\" %{INT:status_code} %{INT:bytes}")
		set_tag(client_ip, "1")
		cast(data, "int")

		`,
			outtag: "client_ip",
			expect: "1",
			fail:   false,
		},
		{
			name: "set_tag 3",
			in:   `{"str_a": "2", "str_b": "3"}`,
			pl: `
			json(_, str_a)
			json(_, str_b)
			set_tag(str_a, str_b)
	`,
			outtag: "str_a",
			expect: "3",
			fail:   false,
		},
		{
			name: "set_tag 3 int",
			in:   `{"str_a": "2", "str_b": 3}`,
			pl: `
			json(_, str_a)
			json(_, str_b)
			set_tag(str_a, str_b)
	`,
			outtag: "str_a",
			expect: "3",
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
			_, tags, _, _, _, err := runScript(runner, "test", nil, map[string]interface{}{
				"message": tc.in,
			}, time.Now())
			if err != nil {
				t.Error(err)
				return
			}
			t.Log(tags)
			v := tags[tc.outtag]
			assert.Equal(t, tc.expect, v)
			t.Logf("[%d] PASS", idx)
		})
	}
}
