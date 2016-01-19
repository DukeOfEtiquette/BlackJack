all: BlackJack

BlackJack: Board.o Deck.o Player.o Hand.o Card.o cardTest.o
	g++ Board.o Deck.o Player.o Hand.o Card.o cardTest.o -o BlackJack

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

cardTest.o: cardTest.cpp
	g++ -c cardTest.cpp
