#include <iostream>
#include <vector>
#include "Hand.h"
#include "Card.h"
#include "Player.h"

int main()
{
	Card* c;
	
	Card::Suit heart = Card::Heart;
	Card::Suit diamond = Card::Diamond;
	Card::Suit club = Card::Club;
	Card::Suit spade = Card::Spade;
	
	Hand* h1 = new Hand(0);
	c = new Card(2,heart);
	h1->m_hand.push_back(c);
	c = new Card(3,diamond);
	h1->m_hand.push_back(c);
	

	Hand* h2 = new Hand(1);
	c = new Card(4,club);
	h2->m_hand.push_back(c);
	c = new Card(5,spade);
	h2->m_hand.push_back(c);
	
	Player* p = new Player();
	
	//p->m_handList.push_back(h1);
	
	p->AddStartingHand(h1);
	//m_handList.push_back(h2);
	std::cout << "h1 PrintHands() ";
	p->PrintHands();
	std::cout << std::endl;
	
	p->Split(h1);

	std::cout << "h1 PrintHands() after split ";
	p->PrintHands();
	std::cout << std::endl;
	
	std::cout << "DumpHands: ";
	p->DumpHands();
	std::cout << std::endl;
}
