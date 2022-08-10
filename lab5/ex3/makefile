all:test

test:ex3.o factoredForm.o
		g++ -o test ex3.o factoredForm.o -g


ex3.o:ex3.cpp
		g++ -c ex3.cpp -g 

factoredForm.o:factoredForm.cpp
		g++ -c factoredForm.cpp
		
clean:
		rm -f *.o test