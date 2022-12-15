package platypus

import (
	"os"

	"github.com/spf13/cobra"

	"github.com/GuanceCloud/platypus/internal/cmd/platypus/run"
)

func newRunCmd() *cobra.Command {
	options := run.Options{}

	var cmd = &cobra.Command{
		Use:   "run",
		Short: "Run Platypus script",
		Long:  "Execute a Platypus script by interpreter runtime",
		RunE: func(cmd *cobra.Command, args []string) error {
			return run.Run(cmd.Context(), &options)
		},
	}

	wd, _ := os.Getwd()
	cmd.Flags().StringVarP(&options.Workspace, "workspace", "w", wd, "platypus workspace directory")
	cmd.Flags().StringVarP(&options.Script, "script", "s", "", "script name")
	cmd.Flags().StringVarP(&options.Input, "input", "i", "", "input data file path")
	cmd.Flags().StringVarP(&options.Type, "type", "t", "text", "data source type: text, lineprotocol")
	cmd.Flags().StringVarP(&options.OutputType, "output-type", "", "json", "result output type: json, lineprotocol")
	_ = cmd.MarkFlagRequired("script")
	_ = cmd.MarkFlagRequired("file")
	return cmd
}
