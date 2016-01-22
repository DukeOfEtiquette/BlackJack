#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"
#include <assert.h>

int main()
{
	Hand* h = new Hand(0);
	
	Card* c;

    Card::Suit heart = Card::Heart;
    Card::Suit diamond = Card::Diamond;
	Card::Suit club = Card::Club;
	Card::Suit spade = Card::Spade; 

    c = new Card(1, heart);
    h->m_hand.push_back(c);
	//c = new Card(2, club);
	//h->m_hand.push_back(c);
	//c = new Card(3, diamond);
	//h->m_hand.push_back(c);
	

    std::cout << "SumHand(): " << h->SumHand() << std::endl;    
    std::cout << "PrintHand(): "; 
    h->PrintHand();   
    std::cout << std::endl;
 
	h->DumpHand();   
	assert (h->m_hand.empty());
	
	return 0;
}


