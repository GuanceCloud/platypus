package run

const (
	TypeLineProtocol = "lineprotocol"
	TypeText         = "text"

	OutTypeJSON         = "json"
	OutTypeLineProtocol = "lineprotocol"

	defaultJSONIndent = "  "
)

type Options struct {
	Workspace  string
	Script     string
	Input      string
	Type       string
	OutputType string
}
