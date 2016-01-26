#include <iostream>
#include "Board.h"

int main()
{
	//Clear terminal window
	for(int i = 0; i < 100; i++)
		std::cout << std::endl;



	Board* gameBoard = new Board(5, 12, "fun game");

	//Test if a starting hand gets dealt properly
	gameBoard->DealStartingHands();
	gameBoard->PrintDealer(true);
	gameBoard->PrintAllPlayers();

	if(gameBoard->m_players[0]->m_handList[0]->SumHand() > 20)
	{
		gameBoard->PrintDealer(false);
		std::cout << "Dealer wins!\n";
	}

	bool split = true;

	//Check all starting hands for ability to split
	while(split)
	{
		split = false;

		for(int i = 1; i < gameBoard->m_players.size(); i++)
		{
			for(int j = 0; j < gameBoard->m_players[i]->m_handList.size(); j++)
			{
				if(gameBoard->PlayerHasSplit(i, j))
				{
					split = true;
					gameBoard->SplitHand(i, j);
				}
			}
		}
	}

	for(int i = 1; i < gameBoard->m_players.size(); i++)
	{
		gameBoard->m_players[i]->PlayHands();
	}

	gameBoard->PrintCurPlayer(1);

	//Deal an additional card, aka hit, for player one
	gameBoard->DealCard(1, 0);
	gameBoard->PrintDealer(false);
	gameBoard->PrintAllPlayers();

	return 0;
}
