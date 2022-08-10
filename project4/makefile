all:compress

compress:huffmanTree.o compress.o binaryTree.o 
	g++ -g -o compress huffmanTree.o compress.o binaryTree.o

huffmanTree.o:huffmanTree.cpp
	g++ -c -g huffmanTree.cpp

compress.o:compress.cpp
	g++ -c -g compress.cpp

binaryTree.o:binaryTree.cpp
	g++ -c -g binaryTree.cpp

clean:
	rm -f *.o compress.exe
