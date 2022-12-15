package platypus

import (
	"github.com/spf13/cobra"
)

func NewRootCmd() *cobra.Command {
	var rootCmd = &cobra.Command{
		Use:   "platypus",
		Short: "Platypus Programming Language for Observability Data Pipeline",
		Long:  "See https://platypus.guance.io for more information",
	}
	rootCmd.AddCommand(newRunCmd())
	rootCmd.AddCommand(newCompletionCmd(rootCmd))
	return rootCmd
}
