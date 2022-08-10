all:blackjack

blackjack:blackjack.o hand.o card.o player.o rand.o deck.o
	g++ -Wall -o blackjack blackjack.o hand.o card.o player.o rand.o deck.o

blackjack.o:blackjack.cpp
	g++ -Wall -c blackjack.cpp

hand.o:hand.cpp
	g++ -Wall -c hand.cpp

card.o:card.cpp
	g++ -Wall -c card.cpp

player.o:player.cpp
	g++ -Wall -c player.cpp

rand.o:rand.cpp
	g++ -Wall -c rand.cpp

deck.o:deck.cpp
	g++ -Wall -c deck.cpp
	
clean: 
	rm -f *.o blackjack