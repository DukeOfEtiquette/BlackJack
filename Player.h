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

	void Split(int index);
	void AddHand(Hand* hand);
	bool PrintHand(int);
	void PrintHands();
	void DumpHands();
	bool CanSplit(int);
};

#endif
