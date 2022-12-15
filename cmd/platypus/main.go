package main

import (
	"fmt"
	"os"

	"github.com/GuanceCloud/platypus/internal/cmd/platypus"
)

func main() {
	rootCmd := platypus.NewRootCmd()
	rootCmd.AddCommand(newVersionCmd())

	if err := rootCmd.Execute(); err != nil {
		fmt.Println(err)
		os.Exit(1)
	}
}
