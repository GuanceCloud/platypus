echo -e "\033[32m> input-type: lineprotocol, data:\033[0m"

echo $(cat test_fn_use.data)

echo -e "\033[32m> ppl script (test_fn_use.p):\033[0m"
cat test_fn_use.p

echo -e "\033[32m> ppl script (s.p):\033[0m"
cat s.p

echo -e "\033[32m> ppl -s test_fn_use.p -i test_fn_use.data -t lineprotocol --output-type lineprotocol\033[0m"
go run ../../cmd/ppl/ppl.go -s test_fn_use.p -i test_fn_use.data -t lineprotocol --output-type lineprotocol

echo -e "\033[32m> ppl -w . -s test_fn_use.p -i test_fn_use.data -t lineprotocol\033[0m"
go run ../../cmd/ppl/ppl.go -w . -s test_fn_use.p -i test_fn_use.data -t lineprotocol
