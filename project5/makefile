all:test

test:test.o 
	g++ --std=c++17 -Werror -fsanitize=leak -g -o test test.o

test.o:test.cpp
	g++ -c -g -Wall test.cpp

clean:
	rm -f *.o test
