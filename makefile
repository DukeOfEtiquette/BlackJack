
OBJS = Board.o Deck.o Player.o Hand.o Card.o playerTest.o

OBJS = Board.o Deck.o Player.o Hand.o Card.o playerTest.o

EXES = Blackjack
FLAGS = -c
CC = g++

all: $(EXES)

clean:
	rm $(OBJS)

Blackjack: $(OBJS)
	$(CC) $(OBJS) -o Blackjack

Board.o: Board.cpp
	$(CC) $(FLAGS) Board.cpp

Deck.o: Deck.cpp
	$(CC) $(FLAGS) Deck.cpp

Player.o: Player.cpp
	$(CC) $(FLAGS) Player.cpp

Hand.o: Hand.cpp
	$(CC) $(FLAGS) Hand.cpp

Card.o: Card.cpp
	$(CC) $(FLAGS) Card.cpp

playerTest.o: playerTest.cpp
	$(CC) $(FLAGS) playerTest.cpp
