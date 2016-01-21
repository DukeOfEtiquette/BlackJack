#ifndef Hand_cpp
#define Hand_cpp

#include "Card.h"
#include <vector>

class Hand {
public:
	std::vector<Card*> m_hand;
	int m_handID;

	int SumHand();
	void PrintHand();
	void DumpHand();

};

#endif
