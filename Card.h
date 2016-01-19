#ifndef _CARD_H_INCLUDED
#define _CARD_H_INCLUDED


//#include "Card.cpp"

class Card
{

public:
	enum Suit{
		Club = 0,
		Diamond = 1,
		Spade = 2,
		Heart = 3,
	};

	Card(int, Suit);

	int m_value;
	Suit m_suit;

	void PrintCard();
	int GetValue();


};

#endif
