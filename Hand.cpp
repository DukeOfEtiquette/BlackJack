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
	//Destructor clears hand vector 
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

void Hand::DumpHand() 
{
	//Removes all elements from a vector
	//Leaves the container with a size of 0
	m_hand.clear();
}
