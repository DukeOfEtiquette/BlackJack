#include "Card.h"
#include <vector>

public:
	std::vector<Card*> m_deck;
	void InitializeSet();
	void Shuffle();
	Card* DealCard();
	Deck(int);
