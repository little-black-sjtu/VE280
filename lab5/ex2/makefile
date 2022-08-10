all:test

test:ex2.o standardForm.o
		g++ -o test ex2.o standardForm.o -g


ex2.o:ex2.cpp
		g++ -c ex2.cpp -g 

standardForm.o:standardForm.cpp
		g++ -c standardForm.cpp
		
clean:
		rm -f *.o test