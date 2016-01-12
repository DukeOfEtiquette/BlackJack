#include "Card.h"
#include <vector>

public:
	std::deque<Card*> m_deck;
	void InitializeSet();
	void Shuffle();
	Card* DealCard();
	Deck(int);
