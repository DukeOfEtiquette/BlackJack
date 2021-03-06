#include <iostream>
#include <vector>
#include "Hand.h"
#include "Card.h"
#include "Player.h"
#include <assert.h>

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
    
    assert(h1->m_hand[0]->m_value == 2);
    assert(h1->m_hand[01]->m_value == 3);

	Hand* h2 = new Hand(0);
	c = new Card(4,club);
	h2->m_hand.push_back(c);
	c = new Card(5,spade);
	h2->m_hand.push_back(c);
    
	Player* p = new Player(0);
	Player* p1 = new Player(1);
	//p->m_handList.push_back(h1);
	
    
    
	p->AddStartingHand(h1);
	p1->AddStartingHand(h2);
    
    if(p->m_handList[0] == NULL)
    {
        std::cout << "error handList does not contain a card for player p" << std::endl;
    }
    if(p1->m_handList[0] == NULL)
    {
        std::cout << "error handList does not contain a card for player p1" << std::endl;
    }
    
	//m_handList.push_back(h2);
	//std::cout << "h1 PrintHands() ";
	p->PrintHands();
	std::cout << std::endl;

	p1->PrintHands();
	std::cout << std::endl;
    
	p->Split(0);
	p1->Split(0);
    
    if(p->m_handList[1] == NULL)
    {
        std::cout << "error split did not complete on p" << std::endl;
    }
    if(p1->m_handList[1] == NULL)
    {
        std::cout << "error split did not complete on p1" << std::endl;
    }
    
	//std::cout << "h1 PrintHands() after split ";
	
    
    try
    {
        p->PrintHands();
        std::cout << std::endl;
        
        p1->PrintHands();
        std::cout << std::endl;
        
        if (p->m_handList[0] == 0 || p->m_handList[1] == 0)
        {
            throw -1;
        }
    }
    catch (int e)
    {
        std::cout << "PrintHand() was unsuccessful error:"<< e << std::endl;
    }
    

	std::cout << "DumpingHands...";
	p->DumpHands();
	p1->DumpHands();
	std::cout << std::endl;
}
