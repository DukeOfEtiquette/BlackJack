#include <iostream>
#include <string>
#include "Ace.h"


Ace::Ace(int val, Suit s) : Card(val, s)
//Ace is dervived from Card and is used in Deck.cpp
{
	//Makes sure the value of Ace is 1 
	if(val != 1)
	{
		std::cout << "Invalid value for Ace - " << val << std::endl;
		return;
	}

	//Sets the member variables of Ace to their default values 
	m_value = 11;
	m_suit = s;
	m_bLowVal = false;
}

int Ace::GetValue()
{
	//Gets the value of Ace, if boolean LowVal is true then the value will be 1 
	if(m_bLowVal)
		return 1;
	else
		return 11;
}

void Ace::PrintCard()
{
	//Prints A and the suit of Ace
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
	//Decrements the value of an Ace by 10 (back to 1) and sets boolean LowVal to true
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
