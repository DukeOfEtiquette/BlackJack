#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED


#include "Card.h"
#include "Hand.h"
#include <vector>

class Player
{
public:
	Player(int);
	std::vector<Hand*> m_handList;
	int m_playerID;

	void Split(int index);
	void AddStartingHand(Hand* hand);
	void PrintHands();
	void DumpHands();
	bool HasSplit();
};

#endif
