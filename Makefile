test_string:
	mkdir -pv tests
	gcc ./src/string.c -Og -g -o ./tests/string -DTEST_STRING
	./tests/string

test_array:
	mkdir -pv tests
	gcc ./tests/test_array.c -Og -g -o ./tests/array
	./tests/array
