echo -e "\033[32m> input-type: lineprotocol, data:\033[0m"

echo $(cat test_fn_use.data)

echo -e "\033[32m> ppl script (test_fn_use.ppl):\033[0m"
cat test_fn_use.ppl

echo -e "\033[32m> ppl script (s.ppl):\033[0m"
cat s.ppl

echo -e "\033[32m> ppl run -s test_fn_use.ppl -i test_fn_use.data -t lineprotocol --output-type lineprotocol\033[0m"
go run ../../cmd/ppl/ppl.go run -s test_fn_use.ppl -i test_fn_use.data -t lineprotocol --output-type lineprotocol

echo -e "\033[32m> ppl run -w . -s test_fn_use.ppl -i test_fn_use.data -t lineprotocol\033[0m"
go run ../../cmd/ppl/ppl.go run -w . -s test_fn_use.ppl -i test_fn_use.data -t lineprotocol
