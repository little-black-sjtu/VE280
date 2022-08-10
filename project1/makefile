all:p1

p1:p1.o
	g++ -o p1 p1.o

p1.o:p1.cpp
	g++ -Wall -c -g p1.cpp

clean:
	rm -f p1 *.o