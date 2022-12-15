echo -e "\033[32m> input-type: lineprotocol, data:\033[0m"

echo $(cat test_fn_use.data)

echo -e "\033[32m> platypus script (test_fn_use.p):\033[0m"
cat test_fn_use.p

echo -e "\033[32m> platypus script (s.p):\033[0m"
cat s.p

echo -e "\033[32m> platypus run -s test_fn_use.p -i test_fn_use.data -t lineprotocol --output-type lineprotocol\033[0m"
go run ../../cmd/platypus/platypus.go run -s test_fn_use.p -i test_fn_use.data -t lineprotocol --output-type lineprotocol

echo -e "\033[32m> platypus run -w . -s test_fn_use.p -i test_fn_use.data -t lineprotocol\033[0m"
go run ../../cmd/platypus/platypus.go run -w . -s test_fn_use.p -i test_fn_use.data -t lineprotocol
