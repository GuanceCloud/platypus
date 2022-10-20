
.PHONY: lint

GOLINT_BINARY = golangci-lint

lint:
	$(GOLINT_BINARY) run --fix --allow-parallel-runners
