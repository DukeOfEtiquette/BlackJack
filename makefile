DEFO = potTest.o
DEFC = potTest.cpp
OBJS = ${DEFO}
EXES = blackjack
FLAGS = -c
CC = g++

//all: $(EXES)

clean:
	rm $(OBJS)

Blackjack: $(OBJS)
	$(CC) $(OBJS) -o Blackjack

${DEFO}: ${DEFC}
	$(CC) $(FLAGS) ${DEFC}
