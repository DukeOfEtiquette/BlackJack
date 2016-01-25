#ifndef Player_H
#define Player_H

#include "Card.h"
#include "Hand.h"
#include "Player.h"

class Player
{
public:
	Player();
	std::vector<Hand*> m_handList;
	void Split(std::vector<Card*> splitHand);
	void AddStartingHand(std::vector<Card*> hand);
	void PrintHands();
	void DumpHands();
};

#endif
