#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED


#include "Card.h"
#include "Hand.h"
#include <vector>

class Player
{
public:
	Player(int);
	~Player();
	std::vector<Hand*> m_handList;
	int m_playerID;
	int m_pot; //This will actually be a pot class once complete

	void Split(int index);
	void AddHand(Hand* hand);
	bool PrintHand(int);
	void PrintHands();
	void DumpHands();
	bool CanSplit(int);

	void PlaceBet(int);
	void DoubleDown();
	void BuyInsurance(int);
	void AddWinnings(bool);
	void ResetBets();
};

#endif
