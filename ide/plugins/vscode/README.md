# Platypus extension for Visual Studio Code

The Language Server of [Platypus Programming Language](https://platypus.guance.io/).

See [Platypus proposal A001](https://github.com/GuanceCloud/ppl/blob/13e6f48d3c87861a697c668ca83827f11ecbb89f/proposals/A001-add-developer-toolchain.md) for details.

## Features

* Support for **syntax highlighting**
* Support for **code completion**
* Support for **code linting**
* Support for **code formatting**

## Structure

```
.
├── client // Language Client
│   ├── src
│   │   ├── test // End to End tests for Language Client / Server
│   │   └── extension.ts // Language Client entry point
├── package.json // The extension manifest.
└── server // Language Server
    └── src
        └── server.ts // Language Server entry point
```
