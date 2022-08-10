all:test

test:test1.o ex1.o recursive.o
		g++ -o test test1.o ex1.o recursive.o -g

test1.o:test1.cpp
		g++ -c test1.cpp -g

ex1.o:ex1.cpp
		g++ -c ex1.cpp -g 

recursive.o:recursive.cpp
		g++ -c recursive.cpp -g

clean:
		rm -f *.o test