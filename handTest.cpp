#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"

int main()
{
	std::cout << "Hello World!\n";

	Hand* h = new Hand(0);

	Card* c;
	

    Card::Suit heart = Card::Heart;
    Card::Suit diamond = Card::Diamond;

    c = new Card(2, heart);
    h->m_hand.push_back(c);

    std::cout << "SumHand(): " << h->SumHand() << std::endl;    
    std::cout << "PrintHand(): "; 
    h->PrintHand();   
    std::cout << std::endl;
 
	h->DumpHand();   
          
	return 0;
}


