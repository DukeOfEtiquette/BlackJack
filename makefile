all: BlackJack

BlackJack: Board.o Deck.o Player.o Hand.o Card.o
	g++ Board.o Deck.o Player.o Hand.o Card.o -o BlackJack

Board.o: Board.cpp
	g++ -c Board.cpp

Deck.o: Deck.o
	g++ -c Deck.cpp

Player.o: Player.o
	g++ -c Player.cpp

Hand.o: Hand.o
	g++ -c Hand.cpp

Card.o: Card.o
	g++ -c Card.cpp
