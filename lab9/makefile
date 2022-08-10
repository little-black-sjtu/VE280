all:test

test:test.o 
	g++ -Werror -fsanitize=leak -g -o test test.o

test.o:test.cpp
	g++ -c -g -Wall test.cpp

clean:
	rm -f *.o test
