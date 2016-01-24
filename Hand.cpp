#include <iostream>
#include "Card.h"
#include "Hand.h" 

Hand::Hand(int id)
{
    m_handID = id;
}

Hand::~Hand(void)
{

}

int Hand::SumHand() 
{ 
		int sum = 0;
		for (int i = 0; i < m_hand.size(); i++) 
		{
				sum += m_hand[i]->GetValue();		
		}

		return sum;
}

void Hand::PrintHand() {
		for (int i = 0; i < m_hand.size(); i++) {
				m_hand[i]->PrintCard();
		}
}

void Hand::DumpHand() {
		m_hand.clear();
}
