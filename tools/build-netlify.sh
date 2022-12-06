#!/bin/bash

set -ex

# Build the landing pages
cd site
yarn run build
yarn run export
cd -

# Build the documentation
cd docs
pip install -r requirements.txt
mkdocs build
cd -

mkdir -p .build
cp -r site/out/* .build
cp -r docs/site/* .build/docs
