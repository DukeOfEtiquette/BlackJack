#include "Card.h"
#include "Hanh.h"
#include <vector>

public:
	std::vector<Hand*> m_handList;
	void Split();
	void AddStartingHand(Board*);
	void PrintHands();
	void DumpHands();
