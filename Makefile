.PHONY: check compile clean
check:
	./check.sh

compile: shapes.cpp
	g++ shapes.cpp -o shapes -Wall -Wextra -Wpedantic -std=c++14

clean:
	rm shapes

