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

	while(sum > 21 && DecAce())
	{
		sum = 0;

		for(int i = 0; i < m_hand.size(); i++) 
		{
			sum += m_hand[i]->GetValue();		
		}
	}

	return sum;
}

bool Hand::PrintHand() 
{
	int sum = SumHand();

	//Prints out all cards in a hand
	std::cout << "Hand " << m_handID + 1 << ": "; 
	for(int i = 0; i < m_hand.size(); i++) 
	{
		m_hand[i]->PrintCard();
	}

	if(sum > 21)
	{
		std::cout << "- Total: " << sum << " - Bust!" << std::endl;
		return true;
	}else if(sum == 21){
		std::cout << "- Blackjack!" << std::endl;
		return true;
	}
	else{
		std::cout << "- Total: " << sum << std::endl;
		return false;
	}
}

void Hand::DumpHand() 
{
	//Removes all elements from a vector
	//Leaves the container with a size of 0
	m_hand.clear();
}

bool Hand::CanSplit()
{
	Ace* a1 = dynamic_cast<Ace*>(m_hand[0]);
	Ace* a2 = dynamic_cast<Ace*>(m_hand[1]);

	//If one card is an ace and the other is not, return false
	if((a1 != 0 && a2 == 0) || (a2 != 0 && a1 == 0))
		return false;

	//If both are Ace, restore original value of 11 to first Ace and return true
	if(a1 != 0 && a2 != 0)
	{
		a1->m_value = 11;
		return true;
	}

	//If both are not Ace, but have the same value, return true
	if(m_hand[0]->m_value == m_hand[1]->m_value)
	{
		return true;
	}

	//Otherwise return false
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
