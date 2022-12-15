package main

import (
	"log"
	"os"
	"path"

	"github.com/GuanceCloud/platypus/internal/cmd/platypus"
	"github.com/spf13/cobra"
	"github.com/spf13/cobra/doc"
)

func main() {
	cmd := &cobra.Command{
		Use:   "gen <path>",
		Short: "Generate documentation",
		Args:  cobra.MinimumNArgs(1),
		RunE: func(cmd *cobra.Command, args []string) error {
			rootCmd := platypus.NewRootCmd()

			// create folder if it is not exist
			if err := os.MkdirAll(args[0], 0755); err != nil {
				return err
			}

			// generate man page
			header := &doc.GenManHeader{
				Title:   "MINE",
				Section: "3",
			}
			err := doc.GenManTree(rootCmd, header, path.Join(args[0], "man"))
			if err != nil {
				return err
			}

			// generate markdown
			err = doc.GenMarkdownTree(rootCmd, args[0])
			if err != nil {
				return err
			}
			return nil
		},
	}
	if err := cmd.Execute(); err != nil {
		log.Fatal(err)
	}
}
