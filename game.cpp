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

	if(gameBoard->m_players[0]->m_handList[0]->SumHand() == 21)
	{
		gameBoard->PrintDealer(false);
		std::cout << "Dealer wins!\n";
	}

	bool split;
	std::string option;

	for(int i = 1; i < gameBoard->m_players.size(); i++)
	{
		split = true;
		while(split)
		{
			for(int j = 0; j < gameBoard->m_players[i]->m_handList.size(); j++)
			{
				if(gameBoard->PlayerHasSplit(i, j))
				{
					gameBoard->PrintPlayerHand(i, j);
					std::cout << "Would you like to split this hand (y/n): ";
					std::getline(std::cin, option);

					std::cout << std::endl;

					if(tolower(option[0]) == 'y')
					{
						gameBoard->SplitHand(i, j);//Split hand and deal two cards
						split = false;//We want to exit while loop and j for loop
						j--;//Restart split check at current hand
					}else if(tolower(option[0]) == 'n'){
						split = false;
					}else{
						std::cout << "Not a valid option, try again.\n";
						j--;
					}
				}

				split = false;
			}
		}
		gameBoard->PlayHands(gameBoard->m_players[i]);
		std::cout << "\n\n";
	}

	bool dBust = true;
	int dSum = 0;
	int sum = 0;
	int maxHand = 0;

	for(int i = 0; i < gameBoard->m_players.size(); i++)
	{
		for(int j = 0; j < gameBoard->m_players[i]->m_handList.size(); j++)
		{
			sum = gameBoard->m_players[i]->m_handList[j]->SumHand();

			if(maxHand < sum && sum < 22)
			{
				maxHand = sum;
				dBust = false;
			}
		}
	}

	while(!dBust)
	{
		dSum = gameBoard->m_players[0]->m_handList[0]->SumHand();

		if(dSum < 17 || dSum < sum)
		{
			gameBoard->DealCard(0, 0);
		}else{
			dBust = true;
		}
	}

	//Deal an additional card, aka hit, for player one
	gameBoard->PrintDealer(false);
	gameBoard->PrintAllPlayers();

	int playerSum = 0;
	bool dWin = true;
	bool bPush = false;

	//Display winners
	std::cout << "Winner(s):";

	for(int i = 1; i < gameBoard->m_players.size(); i++)
	{
		for(int j = 0; j < gameBoard->m_players[i]->m_handList.size(); j++)
		{
			playerSum = gameBoard->m_players[i]->m_handList[j]->SumHand();

			if(dSum == playerSum)
				bPush = true;
			else if(playerSum > dSum)
				bPush = false;
		}
	}

	//If no push, else push
	if(!bPush)
	{
		for(int i = 1; i < gameBoard->m_players.size(); i++)
		{
			for(int j = 0; j < gameBoard->m_players[i]->m_handList.size(); j++)
			{
				playerSum = gameBoard->m_players[i]->m_handList[j]->SumHand();
				if(dSum > 21)
				{
					if(playerSum < 22)
					{
						std::cout << " Player" << gameBoard->m_players[i]->m_playerID;
						dWin = false;
						break;
					}
				}else if(dSum < playerSum && playerSum < 22){
						
					std::cout << " Player" << gameBoard->m_players[i]->m_playerID;
					dWin = false;
					continue;
				}
			}
		}

		if(dWin && dSum < 22)
			std::cout << " Dealer";
	}else{

		std::cout << " Dealer";

		for(int i = 1; i < gameBoard->m_players.size(); i++)
		{
			for(int j = 0; j < gameBoard->m_players[i]->m_handList.size(); j++)
			{
				playerSum = gameBoard->m_players[i]->m_handList[j]->SumHand();
				
				if(dSum == playerSum)
					std::cout << " Player" << gameBoard->m_players[i]->m_playerID;
			}
		}
	}

	std::cout << "\n\n";

	return 0;
}
