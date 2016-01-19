#include <iostream>
#include <stdio.h>
#include <string>
#include "Card.h"

Card::Card(int val, Suit s)
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
	std::string v;

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

	switch(m_value)
	{
		case 2:
			v = std::to_string(m_value);
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
			v = static_cast<char>(m_value);
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
		default:
			v = 'X';
			break;
	}

	//printf("%s %s", v, s);
	std::cout << v << s;
}
