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
bool Hand::PrintHand() 
{
	int sum = SumHand();

	//Prints out all cards in a hand
	std::cout << "Hand " << m_handID+1 << ": "; 
	for(int i = 0; i < m_hand.size(); i++) 
	{
		m_hand[i]->PrintCard();
	}

	if(sum > 21)
	{
		if(DecAce())
		{
			sum = SumHand();
			std::cout << "- Total: " << sum << std::endl;
			return false;
		}else{
			std::cout << "- Total: " << sum << " - Bust!" << std::endl;
			return true;
		}
	}else if(sum == 21){
		std::cout << "- Blackjack!" << std::endl;
		return true;
	}
	else{
		std::cout << "- Total: " << sum << std::endl;
		return false;
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

bool Hand::CanSplit()
{
	Ace* a1 = dynamic_cast<Ace*>(m_hand[0]);//jack
	Ace* a2 = dynamic_cast<Ace*>(m_hand[1]);//ace
	if((a1 != 0 && a2 == 0) || (a2 != 0 && a1 == 0))
		return false;

	if(m_hand[0]->m_value == m_hand[1]->m_value)
	{
		return true;
	}

	return false;
}

bool Hand::DecAce()
{
	//Find the first Ace that hasn't been decremented yet, and
	//decrement the Ace, then break out of the for loop
	for(int i = 0; i < m_hand.size(); i++)
	{
		if(dynamic_cast<Ace*>(m_hand[i]))
		{
			if(!m_hand[i]->IsLow())
			{
				m_hand[i]->DecValue();
				return true;
			}
		}
	}

	return false;
}
