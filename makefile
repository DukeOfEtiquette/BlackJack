all: BlackJack

BlackJack: Board.o Deck.o Player.o Hand.o Card.o handTest.o
	g++ Board.o Deck.o Player.o Hand.o Card.o handTest.o -o BlackJack

Board.o: Board.cpp
	g++ -c Board.cpp

Deck.o: Deck.cpp
	g++ -c Deck.cpp

Player.o: Player.cpp
	g++ -c Player.cpp

Hand.o: Hand.cpp
	g++ -c Hand.cpp

Card.o: Card.cpp
	g++ -c Card.cpp

handTest.o: handTest.cpp
		g++ -c handTest.cpp
