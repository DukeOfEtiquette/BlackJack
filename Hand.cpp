# include <iostream>
# include "Card.cpp"
# include "Card.h"
# include "Hand.h" 

std::vector<Card*> m_hand;

int Hand::SumHand() { 
		int sum = 0;
		for (int i = 0; m_hand.size(); i++) {
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


