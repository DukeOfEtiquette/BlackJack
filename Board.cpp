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

	m_gameDeck = MakeGameDeck();

	Player* player;

	for(int i = 0; i < nPlayers; i++)
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
	return d;
}

void Board::DealCard(int player, int hand)
{
	m_players[player]->m_handList[hand]->m_hand.push_back(m_gameDeck->DealCard());
}

void Board::SplitHand(int player, int index)
{
	m_players[player]->Split(index);

	m_players[player]->m_handList[index]->m_hand.push_back(m_gameDeck->DealCard());
	m_players[player]->m_handList.back()->m_hand.push_back(m_gameDeck->DealCard());
}

void Board::PrintAllPlayers()
{
	for(int i = 0; i < m_players.size(); i++)
	{
		m_players[i]->PrintHands();
	}
}

void Board::PrintCurPlayer(int player)
{
	m_players[player]->PrintHands();
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

	while(m_play)
	{
		ClearBoard();

		//Deal out starting hands
		//Check if dealer has Blackjack
		//Ask Player 1 would they would like to do
		//Move through all players
		//Have dealer perform AI
		//If dealer busts then everyone who didn't busts wins
		//If dealer doesn't bust, everyone who beat deal without busting wins
		//Check deck size to see if a new deck needs to be created
		//Repeat
	}

}

void Board::EndGame()
{
	m_play = false;
}
