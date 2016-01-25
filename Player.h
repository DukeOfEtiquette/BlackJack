#ifndef Player_H
#define Player_H

#include "Card.h"
#include "Hand.h"
#include "Player.h"

class Player
{
public:
	Player(int);
	std::vector<Hand*> m_handList;
	void Split(int index);
	void AddStartingHand(Hand* hand);
	void PrintHands();
	void DumpHands();
	int m_playerID;
};

#endif
