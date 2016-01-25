#ifndef Player_H
#define Player_H

#include "Card.h"
#include "Hand.h"
#include "Player.h"

class Player
{
public:
	Player();
	std::vector<Card*> m_handList;
	void Split(Hand* splitHand);
	void AddStartingHand(Hand* hand);
	void PrintHands();
	void DumpHands();
};

#endif
