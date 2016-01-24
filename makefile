<<<<<<< HEAD
OBJS = Board.o Deck.o Player.o Hand.o Card.o handTest.o
=======
OBJS = Board.o Deck.o Player.o Hand.o Card.o deckTest.o
>>>>>>> 77cadeb4670c6d0663ac6f5e515caede53d85f8f
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

<<<<<<< HEAD
handTest.o: handTest.cpp
	$(CC) $(FLAGS) handTest.cpp
=======
deckTest.o: deckTest.cpp
	$(CC) $(FLAGS) deckTest.cpp
>>>>>>> 77cadeb4670c6d0663ac6f5e515caede53d85f8f
