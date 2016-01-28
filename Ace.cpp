#include <iostream>
#include <string>
#include "Ace.h"

/***********************************************************************************
* Purpose: Constructor for Ace, used in Deck.cpp 
* In: Takes in a value and a suit
* Out: Ace is defaulted with the value of 11 and suit of spade 
***********************************************************************************/
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

/***********************************************************************************
 * Purpose: Gets the value of and Ace if its boolean LowVal is true, then sets the 
 *		Ace's value to 1
 * Out: Sets an Ace's value to 1 if its LowVal is true
 ***********************************************************************************/
int Ace::GetValue()
{
	//Gets the value of Ace, if boolean LowVal is true then the value will be 1 
	if(m_bLowVal)
		return 1;
	else
		return 11;
}

/***********************************************************************************
 * Purpose: Print an Ace card
 * Out: Print's an Aces's value and suit
***********************************************************************************/
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

	std::cout << val << s << " ";
}

/***********************************************************************************
 * Purpose: Decrements the value of an Ace 
 * Out: Decrements and Ace's value to one and sets LowVal to true
***********************************************************************************/
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
