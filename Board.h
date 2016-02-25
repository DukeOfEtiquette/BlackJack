#ifndef _BOARD_H_INCLUDED
#define _BOARD_H_INCLUDED

#include <map>
#include <string>
#include <vector>
#include "Player.h"
#include "Deck.h"

class Board
{
public:
    Deck* m_gameDeck; //First used in the constructor
    int m_nPlayers;//Used in constructor and destructor
    int m_nDecks;//Used in constructor, MakeGameDeck and CheckDeck
	int m_initialPot; //Initial pot size for all players
    std::map<int, Player*> m_players;//Used in nearly every function
    int m_option;//Used in StartGame
    bool m_bPlay;//Used in StartGame and EndGame
	std::vector<Player*> m_roundWinners; //Keep track of all winners for a round
	bool m_bPush; //Keep track if table pushed
	bool m_bDealerBJ; //This will track if dealer has a Blackjack
    
    Board(int, int, int);
    ~Board();
    
    Deck* MakeGameDeck();
    void GameMenu();
	void OfferSurrender();
	void AwardInsurance();
	void GetPlayerBets();
	void RewardPlayers();
	void ResetPlayerBets();
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
	void OfferInsurance();
	bool DealerHasBJ();
};

#endif
