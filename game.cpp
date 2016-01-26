#include <iostream>
#include "Board.h"



int main()
{
	Board* gameBoard = new Board(2, 2, "fun game");

	gameBoard->DealStartingHands();
	gameBoard->PrintAllPlayers();

	return 0;
}
