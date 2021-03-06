#include <iostream>
#include <string>
#include "Ace.h"

/***********************************************************************************
* Purpose: Constructor for Ace, Ace is derived from Card and is used in Deck.cpp
* In: Takes in a value and a suit
* Out: Ace is defaulted with the value of 11 and suit of spade 
***********************************************************************************/
Ace::Ace(int val, Suit s) : Card(val, s)
{
    //Make sure that Ace doesn't have a value of 1
	if(val != 1)
	{
		std::cout << "Invalid value for Ace - " << val << std::endl;
		return;
	}
    
    //Sets member variables
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
    //If boolean bLowVal is true an Ace has been decremented
	if(m_bLowVal)
		return 1;
	else
		return 11;
}

/***********************************************************************************
 * Purpose: Print an Ace card
 * Out: Print's an A and an Aces's value and suit
***********************************************************************************/
void Ace::PrintCard()
{
	char val, s;

    //Switch statement for each suit, with X being default to detect errors
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
 * Purpose: Increment an Ace card to set its value to 11
 * Out: boolean bLowVal is set to false and the value is incremented by 10
 ***********************************************************************************/
void Ace::IncValue()
{
	if(m_bLowVal)
	{
		m_value += 10;
		m_bLowVal = false;
	}
}


/***********************************************************************************
 * Purpose: Decrements the value of an Ace 
 * Out: Decrements and Ace's value to one and sets LowVal to true
***********************************************************************************/
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
