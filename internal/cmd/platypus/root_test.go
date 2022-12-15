package platypus

import (
	"bytes"
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestNewRootCmd(t *testing.T) {
	cmd := NewRootCmd()

	b := bytes.NewBufferString("")
	cmd.SetOut(b)
	cmd.SetArgs([]string{"--help"})

	err := cmd.Execute()
	if !assert.NoError(t, err) {
		t.FailNow()
	}
}
