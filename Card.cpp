#include <iostream>
#include "Card.h"

Card ::Card(int val, Suit s)
{
	m_value = val;
	suit = s;
}

int Card::GetValue()
{
	if(m_value > 10)
		return 10;
	else
		return m_value;
}

void Card::PrintCard()
{
	char s;
	switch(suit)
	{
		case Club:
			s = 'C';
			break;
		case Diamond:
			s = 'D';
			break;
		case Spade:
			s = 'S';
			break;
		case Heart:
			s = 'H';
			break;
		default:
			s = 'X';
			break;
	}

	std::cout << GetValue() << s;
}
