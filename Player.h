#ifndef _PLAYER_H_INCLUDED
#define _PLAYER_H_INCLUDED


#include "Card.h"
#include "Hand.h"
#include <vector>

class Player
{
public:
	//Player is constructed with int ID
	Player(int);
	//Vector of hand pointers is created called m_handList, used in Board.cpp
	std::vector<Hand*> m_handList;
	//m_playerID used to keep track of the players id from constructor, used in Board.cpp
	int m_playerID;

	void Split(int index);
	void AddStartingHand(Hand* hand);
	void PrintHands();
	void DumpHands();
	bool HasSplit(int);
	bool HasAce();
};

#endif
