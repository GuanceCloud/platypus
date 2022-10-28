FROM scratch
# FROM alpine
COPY ppl /usr/local/bin/ppl
ENTRYPOINT ["/usr/local/bin/ppl"]