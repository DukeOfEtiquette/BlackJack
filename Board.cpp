#include <iostream>
#include <map>
#include <string>
#include "Board.h"
#include "Player.h"

Board::Board(int nPlayers, int nDecks, std::string gameName)
{
	if(nPlayers < 2 || nDecks < 1)
	{
		std::cout << "Invalid number of players or decks passed.\n";
		return;
	}

	m_nPlayers = nPlayers;
	m_nDecks = nDecks;
	m_gameName = gameName;
	//m_curPlayer = 1;
	//m_curHand = 1;
	m_play = true;

	m_gameDeck = MakeGameDeck();

	Player* player;

	for(int i = 0; i <= nPlayers; i++)
	{
		player = new Player(i);
		m_players.insert(std::pair<int, Player*>(i, player));
	}
}

Board::~Board()
{
	for(int i = 0; i < m_players.size(); i++)
	{
		delete m_players[i];
	}

	delete m_gameDeck;
}

void Board::DealStartingHands()
{
	for(int i = 0; i < m_players.size(); i++)
	{
		m_players[i]->AddStartingHand(MakeStartingHand());
	}
}

Hand* Board::MakeStartingHand()
{
	Hand* h = new Hand(0);
	for(int i = 0; i < 2; i++)
	{
		h->m_hand.push_back(m_gameDeck->DealCard());
	}

	return h;
}

Deck* Board::MakeGameDeck()
{
	Deck* d = new Deck(m_nDecks);
	d->Shuffle();
	return d;
}

void Board::DealCard(int player, int hand)
{
	m_players[player]->m_handList[hand]->m_hand.push_back(m_gameDeck->DealCard());
}

void Board::SplitHand(Player* player, int index)
{
	player->Split(index);

	player->m_handList[index]->m_hand.push_back(m_gameDeck->DealCard());
	player->m_handList.back()->m_hand.push_back(m_gameDeck->DealCard());
}

void Board::PrintAllPlayers()
{
	for(int i = 1; i < m_players.size(); i++)
	{
		m_players[i]->PrintHands();
	}

	std::cout << std::endl;
}

void Board::PrintPlayerHand(int player, int iHand)
{
	m_players[player]->PrintHand(iHand);
}

void Board::PrintCurPlayer(int player)
{
	m_players[player]->PrintHands();
}

void Board::PrintDealer(bool hide)
{
	int sum = 0;
	std::cout << "\n### TABLE ###\n";

	if(hide)
	{
		std::cout << "Dealer : ";  
		m_players[0]->m_handList[0]->m_hand[0]->PrintCard();
		std::cout << " *\n";
	}else{

		std::cout << "Dealer : ";  
		m_players[0]->m_handList[0]->PrintHand();
		sum = m_players[0]->m_handList[0]->SumHand();

	}
}

bool Board::PlayerHasSplit(Player* player, int iHand)
{
	return player->CanSplit(iHand);
}

void Board::ClearBoard()
{
	for(int i = 0; i < m_players.size(); i++)
	{
		m_players[i]->DumpHands();
	}
}

void Board::StartGame()
{
	int option, ch;

/* Present user with menu of options:
 *		- Start round
 *		- Pause game
 *		- Exit game
 * */

	while(m_play)
	{
		CheckDeck();
		std::cout << "\n#### " << m_gameName << " Menu ###\n";
		std::cout << "\nPlease select an option below...\n";
		std::cout << "1) Start A Round\n";
		std::cout << "2) Pause game\n";
		std::cout << "3) End Game\n";
		std::cin >> option;

		while ((ch = std::cin.get()) != '\n' && ch != EOF);

		switch(option)
		{
			case 1:
				StartRound();
				break;
			case 2:
				PauseGame();
				break;
			case 3:
				EndGame();
				break;
			default:
				std::cout << "This is default.....\n\n\n\n\n";
				break;
		}
	}
}

void Board::CheckSplit(Player* player)
{
	bool split = true;
	std::string option;

	while(split)
	{
		for(int i = 0; i < player->m_handList.size(); i++)
		{
			if(player->CanSplit(i))
			{
				player->PrintHand(i);
				std::cout << "Would you like to split this hand (y/n): ";
				std::getline(std::cin, option);

				std::cout << std::endl;

				if(tolower(option[0]) == 'y')
				{
					SplitHand(player, i);//Split hand and deal two cards
					split = false;//We want to exit while loop and j for loop
					i--;//Restart split check at current hand
				}else if(tolower(option[0]) == 'n'){
					split = false;
				}else{
					std::cout << "Not a valid option, try again.\n";
					i--;
				}
			}

			split = false;
		}
	}
}

void Board::StartRound()
{
	ClearBoard();
	DealStartingHands();
	PrintDealer(true);
	PrintAllPlayers();

	for(int i = 1; i < m_players.size(); i++)
	{
		CheckSplit(m_players[i]);
		PlayHands(m_players[i]);
	}

	PlayDealer();
	PrintDealer(false);
	PrintAllPlayers();
	PrintWinners();

	std::cout << "\n\n";
}

void Board::PlayDealer()
{

	bool dBust = true;
	int dSum = 0;
	int pSum = 0;
	int maxHand = 0;

	for(int i = 0; i < m_players.size(); i++)
	{
		for(int j = 0; j < m_players[i]->m_handList.size(); j++)
		{
			pSum = m_players[i]->m_handList[j]->SumHand();

			if(maxHand < pSum && pSum < 22)
			{
				maxHand = pSum;
				dBust = false;
			}
		}
	}

	while(!dBust)
	{
		dSum = m_players[0]->m_handList[0]->SumHand();

		if(dSum < 17 || dSum < pSum)
		{
			DealCard(0, 0);
		}else{
			dBust = true;
		}
	}
}

void Board::PrintWinners()
{
	int playerSum = 0;
	bool dWin = true;
	bool bPush = false;
	int dSum = m_players[0]->m_handList[0]->SumHand();

	//Display winners
	std::cout << "Round Winner(s):";

	//Determine if there is a push
	for(int i = 1; i < m_players.size(); i++)
	{
		for(int j = 0; j < m_players[i]->m_handList.size(); j++)
		{
			playerSum = m_players[i]->m_handList[j]->SumHand();

			if(dSum == playerSum)
				bPush = true;
			else if(playerSum > dSum)
				bPush = false;
		}
	}

	//If no push, else push
	if(!bPush)
	{
		for(int i = 1; i < m_players.size(); i++)
		{
			for(int j = 0; j < m_players[i]->m_handList.size(); j++)
			{
				playerSum = m_players[i]->m_handList[j]->SumHand();
				if(dSum > 21)
				{
					if(playerSum < 22)
					{
						std::cout << " Player" << m_players[i]->m_playerID;
						dWin = false;
						break;
					}
				}else if(dSum < playerSum && playerSum < 22){
						
					std::cout << " Player" << m_players[i]->m_playerID;
					dWin = false;
					continue;
				}
			}
		}

		if(dWin && dSum < 22)
			std::cout << " Dealer";
	}else{

		std::cout << " Dealer";

		for(int i = 1; i < m_players.size(); i++)
		{
			for(int j = 0; j < m_players[i]->m_handList.size(); j++)
			{
				playerSum = m_players[i]->m_handList[j]->SumHand();
				
				if(dSum == playerSum)
					std::cout << " Player" << m_players[i]->m_playerID;
			}
		}
	}
}

void Board::PauseGame()
{
	std::cout << "The game is pausing.....\n\n\n\n";
}

void Board::EndGame()
{
	std::cout << "The game is ending......\n\n\n\n";
	m_play = false;
}

bool isValid(char option)
{
	if(tolower(option) == 'h' || tolower(option) == 's')
		return true;
	else
		return false;
}

void Board::PlayHands(Player* player)
{
	std::string option;
	bool validOption;

	for(int i = 0; i < player->m_handList.size(); i++)
	{
		std::cout << std::endl;
		validOption = false;

		while(!validOption)
		{
			if(player->PrintHand(i))
				break;

			std::cout << "Player " << player->m_playerID << " would you like to (h)it, (s)tand for Hand " << i + 1 << "?>";
			std::getline(std::cin, option);

			if(!isValid(option[0]))
			{
				std::cout << "Invalid choice, pleese choose again.\n";
			}
			else{
				if(option[0] == 's' || option[0] == 'S')
				{
					validOption = true;
				}else{
					DealCard(player->m_playerID, i);
				}
			}
		}
	}
}

void Board::CheckDeck()
{
	if(m_gameDeck->m_deck.size() < (m_nDecks/2)*52)
	{
		std::cout << "Creating new deck....\n";
		delete m_gameDeck;
		m_gameDeck = 0;
		m_gameDeck = MakeGameDeck();
	}
}
