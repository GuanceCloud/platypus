FROM alpine:latest
COPY platypus /usr/local/bin/platypus
ENTRYPOINT ["/usr/local/bin/platypus"]
