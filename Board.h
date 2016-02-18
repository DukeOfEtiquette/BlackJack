#ifndef _BOARD_H_INCLUDED
#define _BOARD_H_INCLUDED

#include <map>
#include <string>
#include "Player.h"
#include "Deck.h"

class Board
{
public:
	Deck* m_gameDeck; //First used in the constructor
	std::string m_gameName;//First used in the constructor and in StartGame
	int m_nPlayers;//Used in constructor and destructor
	int m_nDecks;//Used in constructor, MakeGameDeck and CheckDeck
	std::map<int, Player*> m_players;//Used in nearly every function
	int m_option;//Used in StartGame
	bool m_play;//Used in StartGame and EndGame

	Board(int, int, char*);
	~Board();

	Deck* MakeGameDeck();
	void DealStartingHands();
	Hand* MakeStartingHand();
	void DealCard(int, int);
	void SplitHand(Player*, int);
	void PrintAllPlayers();
	void PrintDealer(bool);
	void PlayHands(Player*);
	void CheckSplit(Player*);
	void ClearBoard();
	bool StartGame();
	void EndGame();
	void StartRound();
	void PlayDealer();
	void PrintWinners();
	void CheckDeck();
	
	void GameInterface(); 

	void BettingSystem();
	void AssignStartingBetChips();

};

#endif
