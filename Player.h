#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED

#include "Pot.h"
#include "Card.h"
#include "Hand.h"
#include <vector>

class Player
{
public:
	Player(int, int);
	~Player();
	std::vector<Hand*> m_handList;
	int m_playerID;
	Pot* m_pot;
	bool m_bSurrender;
	
    void Surrender();
	void Split(int index);
	void AddHand(Hand* hand);
	bool PrintHand(int);
	void PrintHands();
	void DumpHands();
	bool CanSplit(int);
	bool HasBlackJack();
    void AwardInsurance();

	void PrintPot();
	bool PlaceBet(int);
	void DoubleDown();
	void BuyInsurance();
	void AddWinnings(bool);
	void PushWinnings();
	void ResetBets();
	bool CanDoubleDown();
	bool CanBuyInsur();
	int AcePos(int);
	int BlackjackPos();
};

#endif
