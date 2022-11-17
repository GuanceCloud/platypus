
.PHONY: lint test tools

GOLINT_BINARY := golangci-lint

DATE := $(shell date -u +'%Y-%m-%d %H:%M:%S')

VERSION := $(shell git describe --always --tags)

lint:
	$(GOLINT_BINARY) run --fix --allow-parallel-runners

test:
	@truncate -s 0 test.output
	@echo "#####################" | tee -a test.output
	@echo "#" $(DATE) | tee -a test.output
	@echo "#" $(VERSION) | tee -a test.output
	@echo "#####################" | tee -a test.output
	i=0; \
	for pkg in `go list ./...`; do \
		echo "# testing $$pkg..." | tee -a test.output; \
		CGO_ENABLED=1 LOGGER_PATH=nul go test -timeout 1m -cover $$pkg; \
		if [ $$? != 0 ]; then \
			printf "\033[31m [FAIL] %s\n\033[0m" $$pkg; \
			i=`expr $$i + 1`; \
		else \
			echo "######################"; \
			fi \
	done; \
	if [ $$i -gt 0 ]; then \
		printf "\033[31m %d case failed.\n\033[0m" $$i; \
		exit 1; \
	else \
		printf "\033[32m all testinig passed.\n\033[0m"; \
	fi

tools:
	mkdir -p ./dist
	rm -r ./dist/
	go build -o ./dist/ cmd/ppl/ppl.go 
