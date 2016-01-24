#include <iostream>
#include <string>
#include "Ace.h"


Ace::Ace(int val, Suit s) : Card(val, s)
{
	if(val != 1)
	{
		std::cout << "Invalid value for Ace - " << val << std::endl;
		return;
	}

	m_value = 11;
	m_suit = s;
	m_bLowVal = false;
}

int Ace::GetValue()
{
	if(m_bLowVal)
		return 1;
	else
		return 11;
}

void Ace::PrintCard()
{
	char val, s;

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

	val = 'A';

	std::cout << val << s;
}


void Ace::DecValue()
{
	if(!m_bLowVal)
	{
		m_value -= 10;
		m_bLowVal = true;
	}
}

bool Ace::IsLow()
{
	return m_bLowVal;
}
