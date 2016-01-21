#include "Card.h"
#include <vector>

public:
	std::vector<Card*> m_hand;
	int m_handID;


	int SumHand();
	void PrintHand();
	void DumpHand();
