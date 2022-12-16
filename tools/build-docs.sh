#!/bin/bash

set -ex

# This script is used to generate the CLI docs for the website.
# It is run from the root of the repo.

# It will create man/ and md/ folder under doc path
CLI_DOC_PATH=docs/src/references/cli
go run tools/build-cli-docs/main.go $CLI_DOC_PATH

# Temporary copy the proposal to explanation until the real doc is ready
DESIGN_DOC_PATH=docs/src/explanations/
mkdir -p $DESIGN_DOC_PATH
cp -f ./proposals/A*.md $DESIGN_DOC_PATH
