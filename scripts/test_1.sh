echo "> input-type: lineprotocol, data:"

echo $(cat test_1.data)

echo ""

echo "> output-type: lineprotocol:"
go run ../cmd/ppl/ppl.go -s test_1.p -i test_1.data -t lineprotocol --output-type lineprotocol

echo ""
echo "> output-type: json:"

go run ../cmd/ppl/ppl.go -s test_1.p -i test_1.data -t lineprotocol
