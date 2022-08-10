all:test

test:course.o main.o
	g++ -o test course.o main.o -g

main.o:main.cpp
	g++ -c main.cpp -g

course.o:course.cpp
	g++ -c course.cpp -g

clean:
	rm -f *.o test