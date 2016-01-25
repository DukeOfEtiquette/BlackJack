#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED


#include "Card.h"
#include "Hand.h"
#include <vector>

class Player
{
public:
	std::vector<Hand*> m_handList;
	void Split();
	void AddStartingHand(Hand*);
	void PrintHands();
	void DumpHands();


};

#endif
