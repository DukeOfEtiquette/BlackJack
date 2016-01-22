#include <iostream>
#include <stdio.h>
#include <string>
#include "Card.h"

Card::Card(int val, Suit s)
{
	m_value = val;
	m_suit = s;
}

int Card::GetValue()
{
	if(m_value > 9)
		return 10;
	else
		return m_value;
}

void Card::PrintCard()
{
	char s;
	std::string v;

	switch(m_suit)
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

	switch(m_value)
	{
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			v = std::to_string(m_value);
			break;
		case 11:
			v = 'J';
			break;
		case 12:
			v = 'Q';
			break;
		case 13:
			v = 'K';
			break;
		//default:
		//	v = 'X';
		//	break;
	}

	std::cout << v << s;
}
