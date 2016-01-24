all: BlackJack

BlackJack: Board.o Deck.o Player.o Hand.o Card.o Ace.o aceTest.o
	g++ Board.o Deck.o Player.o Hand.o Card.o Ace.o aceTest.o -o BlackJack

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

Ace.o: Ace.cpp
	g++ -c Ace.cpp

aceTest.o: aceTest.cpp
	g++ -c aceTest.cpp
