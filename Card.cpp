#include <iostream>
#include <stdio.h>
#include <string>
#include "Card.h"

/***********************************************************************************
 * Purpose: Constructor for card, used in Hand.cpp
 * In: A value and a suit for the card is passed
 * Out: Assigns the member value and the member suit to the value and suit passed
 ***********************************************************************************/
Card::Card(int val, Suit s)
{
    //Make sure nothing about King (assuming Ace is 1) is created
	if(val > 13)
	{
		std::cout << "Value of card too high - " << val << std::endl;
		return;
	}

    //Making sure only 4 types of suits are created
	if((int)s > 3)
	{
		std::cout << "Invalid suit trying to be created\n";
	}

    //Assigning member variables the values passed to them by the constructor
	m_value = val;
	m_suit = s;
}

/***********************************************************************************
 * Purpose: Gets the value for a card 
 * Out: Returns the value 10 if if the cards member value is less than 9 
 ***********************************************************************************/
int Card::GetValue()
{
    //Any card value 10 or more is only returned as a 10
    //Otherwise just return the value of the member variable
	if(m_value > 9)
		return 10;
	else
		return m_value;
}

/***********************************************************************************
 * Purpose: PrintCard() will print the character suit and the value of the card
 * Out: The value and suit of the card will be printed. X being the default value
 ***********************************************************************************/
void Card::PrintCard()
{
	char s;
	std::string v;

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

    //Any non-face card will fall through to case 10
    //Otherwise each face value is handled individually
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
		default:
			v = 'X';
			break;
	}

    //Print the values to stdout
	std::cout << v << s << " ";
}

void Card::DecValue()
{

}

bool Card::IsLow()
{
	return true;
}
