#include <iostream>
#include "Card.h"
#include "Hand.h" 

/***********************************************************************************
 * Purpose: This is the default constructor
 * In: Takes an integer id
 * Out: Assign the value of the id passed to the hands member handID
 ***********************************************************************************/

Hand::Hand(int id)
// Hand contains m_hand (vector of cards) comes from Card.cpp used in Player.cpp 
{
	//Make sure a hand id is not negative
    if(id < 0)
	{
		std::cout << "Hand id is a negative number: " << id << std::endl;
	}
	//Assign a hands id the value passed by the constructor
    m_handID = id;
}

/***********************************************************************************
 * Purpose: This is the default destructor 
 * Out: Clears every element in the hand and sets size equal to 0 
***********************************************************************************/

Hand::~Hand(void)
{
	//Destructor clears hand vector 
	DumpHand();
}

/***********************************************************************************
 * Purpose: Adds up all of the card value in a hand
 * Out: Return the sum of all of the cards in a hand 
 ***********************************************************************************/

int Hand::SumHand() 
{
	int sum = 0;
	for(int i = 0; i < m_hand.size(); i++) 
	{
		sum += m_hand[i]->GetValue();		
	}

	return sum;
}

/***********************************************************************************
 * Purpose: Prints all cards in a hand
 * Out: Prints all cards in m_hand and their hand ID's 
 ***********************************************************************************/

void Hand::PrintHand() 
{
	//Prints out all cards in a hand
	std::cout << "Hand" << m_handID+1 << ": "; 
	for(int i = 0; i < m_hand.size(); i++) 
	{
		//std::cout << "Hand" << m_handID+1 << ": ";
		m_hand[i]->PrintCard();
		//m_handID += 1;
	}
}

/***********************************************************************************
 * Purpose: Clear the hand
 * Out: Clears all elements in the hand and sets it's size to zero
 ***********************************************************************************/

void Hand::DumpHand() 
{
	//Removes all elements from a vector
	//Leaves the container with a size of 0
	m_hand.clear();
}
