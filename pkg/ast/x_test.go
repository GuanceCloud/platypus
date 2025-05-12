package ast

import "testing"

func TestXxx(t *testing.T) {
	var b, ax int
	ax, (b) = 1, 1
	t.Log(ax)
	_ = b
	_ = ax
}
