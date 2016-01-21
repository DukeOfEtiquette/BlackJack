OBJS = Board.o Deck.o Player.o Hand.o Card.o handTest.o
EXES = BlackJack
FLAGS = -c
CC = g++


all: $(EXES)

clean:
		rm *.o

BlackJack: $(OBJS)
	$(CC) $(OBJS) -o BlackJack

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp

Deck.o: Deck.cpp
	$(CC) $(FLAGS)  Deck.cpp

Player.o: Player.cpp
	$(CC) $(FLAGS)  Player.cpp

Hand.o: Hand.cpp
	$(CC) $(FLAGS)  Hand.cpp

Card.o: Card.cpp
	$(CC) $(FLAGS)  Card.cpp

handTest.o: handTest.cpp
		g++ -c handTest.cpp

