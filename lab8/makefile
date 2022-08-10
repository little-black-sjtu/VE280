all:lab8

lab8:node.o lab8Test.o 
	g++ -g -o lab8 node.o lab8Test.o

node.o:node.cpp
	g++ -c -g node.cpp

lab8Test.o:lab8Test.cpp
	g++ -c -g lab8Test.cpp

clean:
	rm -f *.o lab8
