# include <iostream>
# include "Card.cpp"
# include "Card.h"
# include "Hand.h"


int Hand::SumHand() { 
		int sum = 0;
		for (int i = 0; m_hand.size(); i++) {
				sum += m_hand[i]->GetValue();		
		}
return sum;
}



