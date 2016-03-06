DEFO = Test0.o
DEFC = Test0.cpp
OBJS = ${DEFO}
EXES = prog
FLAGS = -c
CC = g++

all: $(EXES)

clean:
		rm $(OBJS)

prog: $(OBJS)
		$(CC) $(OBJS) -o prog

${DEFO}: ${DEFC}
		$(CC) $(FLAGS) ${DEFC}
