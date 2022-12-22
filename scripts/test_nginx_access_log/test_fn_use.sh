echo -e "\033[32m> input-type: text, data:\033[0m"

echo $(cat nginx_access_log.data)

echo -e "\033[32m> platypus script (nginx_access_log.p):\033[0m"
cat nginx_access_log.p

echo -e "\033[32m> platypus run -s nginx_access_log.p -i nginx_access_log.data -t text --output-type lineprotocol\033[0m"
go run ../../cmd/platypus/ run -s nginx_access_log.p -i nginx_access_log.data -t text --output-type lineprotocol

echo -e "\033[32m> platypus run -w . -s nginx_access_log.p -i nginx_access_log.data -t text\033[0m"
go run ../../cmd/platypus/ run -w . -s nginx_access_log.p -i nginx_access_log.data -t text
