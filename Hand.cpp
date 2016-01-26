#include <iostream>
#include "Card.h"
#include "Hand.h" 

Hand::Hand(int id)
{ 
	//Make sure a hand id is not negative
    if(id < 0)
	{
		std::cout << "Hand id is a negative number: " << id << std::endl;
	}
	//Assign a hands id the value passed by the constructor
    m_handID = id;
}

Hand::~Hand(void)
{
	m_hand.clear();
}

int Hand::SumHand() 
{
	//Add up all card values in a hand
	//Returns their sum
	int sum = 0;
	for(int i = 0; i < m_hand.size(); i++) 
	{
		sum += m_hand[i]->GetValue();		
	}

	return sum;
}

bool Hand::PrintHand() 
{
	int sum = SumHand();

	//Prints out all cards in a hand
	std::cout << "Hand" << m_handID+1 << ": "; 
	for(int i = 0; i < m_hand.size(); i++) 
	{
		m_hand[i]->PrintCard();
	}

	if(sum > 21)
	{
		std::cout << " - Bust!" << std::endl;
		return true;
	}
	else{
		std::cout << " - Total: " << sum << std::endl;
		return false;
	}
}

void Hand::DumpHand() 
{
	//Removes all elements from a vector
	//Leaves the container with a size of 0
	m_hand.clear();
}
