#include <iostream>
#include "Board.h"

int main()
{
	for(int i = 0; i < 100; i++)
		std::cout << std::endl;



	Board* gameBoard = new Board(2, 2, "fun game");

	//Test if a starting hand gets dealt properly
	gameBoard->DealStartingHands();
	gameBoard->PrintDealer(true);
	gameBoard->PrintAllPlayers();

	//Deal an additional card, aka hit, for player one
	gameBoard->DealCard(1, 0);
	gameBoard->PrintCurPlayer(1);

	return 0;
}
