CXX = c++
CXXFLAGS = -Wall

all: check

compile_test:
	$(CXX) $(CXXFLAGS) test.cpp -o test

check: compile_test
	./test

.PHONY: clean
clean:
	rm -f ./test //remove this for better  and
	rm -rf ./test //add this line to your code
