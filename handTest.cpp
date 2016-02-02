#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"
#include <assert.h>
#include <math.h>
#include <exception>

int main()
{
	Hand* h = new Hand(0);
	assert (h != NULL);	

	Card* c;	

    Card::Suit heart = Card::Heart;
    Card::Suit diamond = Card::Diamond;
	Card::Suit club = Card::Club;
	Card::Suit spade = Card::Spade; 

    /*
    c = new Card(2, heart);
    h->m_hand.push_back(c);
	assert (h->m_hand[0]->GetValue() == 2);
	assert (h->m_hand.size() > 0);	
     */

	for(int i = 2; i < 14; i++) 
	{
		c = new Card(i, club);
		h->m_hand.push_back(c);
	}
	for(int i = 2; i < 14; i++)
	{
		c = new Card(i,diamond);
		h->m_hand.push_back(c);
	}
	for(int i = 2; i < 14; i++) 
	{
		c = new Card(i, spade);
		h->m_hand.push_back(c);
	}
	for(int i = 2; i < 14; i++)
	{
		c = new Card(i, heart);
		h->m_hand.push_back(c);
	}
	
	// test for x
	//c = new Card(400, spade);
	//h->m_hand.push_back(c);
	
	assert (isnan(h->SumHand()) == false); // SumHand has a number
	assert (h->SumHand() > 0); // SumHand > 0
	
    std::cout << "SumHand(): " << h->SumHand();
    std::cout << "PrintHand(): " << std::endl;
	
	try 
	{
        h->PrintHand();
        std::cout << "h GetValue():";
		std::cout << h->m_hand[0]->GetValue();
		if (h->m_hand[0] == 0) 
		{
			throw -1;
		}
	}
	catch (int e)
	{
		std::cout << "GetValue was unsuccessful error:"<< e << std::endl;
	}
    std::cout << std::endl;
    
    
    for(int i = 0; i < h->m_hand.size(); i++)
    {
        if(h->m_hand[i] == 0)
        {
            std::cout << "error hand is pointing to null\n";
        }
    }
    
    std::cout << "\n\n";
    
    //Does the hand start empty?
    std::cout << "h1 is being created..." << std::endl;
    Hand* h1 = new Hand(1);
   
    std::cout << "hand starts empty? ";
    
    
    for(int i = 0; i < h1->m_hand.size(); i++)
    {
        std::cout << h->PrintHand() << std::endl;
        
        /*
        assert(h1->m_hand[0]->m_value == 'X');
        assert(h1->m_hand[0]->m_suit == 'X');
        
        if(h1->m_hand[i]->m_value == 0)
        {
            std::cout << "pass" << std::endl;
        }
         */
    }
    
    std::cout << "h1 SumHand(): " << h1->SumHand() << std::endl;
    std::cout << "h1 PrintHand: ";
    h1->PrintHand();
    
    // destroys the hands that were created
    h->DumpHand();
    assert (h->m_hand.empty());
    h1->DumpHand();
    assert (h1->m_hand.empty());
    std::cout << std::endl;
	
	return 0;
}


