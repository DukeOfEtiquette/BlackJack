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
	m_curPlayer = 1;
	m_curHand = 1;

	m_gameDeck = new Deck(m_nDecks);

	Player* player;

	for(int i = 0; i < nPlayers; i++)
	{
		player = new Player(i);
		m_players.insert(std::pair<int, Player*>(i, player));
	}
}
