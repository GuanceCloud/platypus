package main

import (
	"fmt"

	"github.com/spf13/cobra"
)

var (
	// version is the version of the build.
	// It will be overwritten automatically by the build system.
	// See .goreleaser.yml for more information.
	version = "0.0.0-devel"

	// commit is the commit hash from the git information.
	commit = "none"

	// date is the date of the build.
	date = "unknown"
)

func newVersionCmd() *cobra.Command {
	return &cobra.Command{
		Use:   "version",
		Short: "Print the version number of Platypus",
		Long:  `All software has versions. This is Platypus's`,
		Run: func(cmd *cobra.Command, args []string) {
			fmt.Printf("Platypus v%s, commit %s, built at %s", version, commit, date)
		},
	}
}
