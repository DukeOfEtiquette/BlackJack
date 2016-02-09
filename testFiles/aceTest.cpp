#include <iostream>
#include <vector>
#include "Card.h"
#include "Ace.h"
#include <assert.h>

int main()
{
	std::vector<Card*> hand;
	Ace* a;
	Card* c;

	//Create a specific hand involving Aces, faces, and non-face cards	
	a = new Ace(1, (Card::Suit)0);
	hand.push_back(a);
	a = new Ace(1, (Card::Suit)1);
	hand.push_back(a);
	c = new Card(10, (Card::Suit)3);
	hand.push_back(c);
	a = new Ace(1, (Card::Suit)2);
	hand.push_back(a);
	c = new Card(13, (Card::Suit)3);
	hand.push_back(c);
	a = new Ace(1, (Card::Suit)3);
	hand.push_back(a);
	c = new Card(5, (Card::Suit)2);
	hand.push_back(c);

	std::cout << "### All cards ###\n";
	//Print out the cards and their value
	for(int i = 0; i < hand.size(); i++)
	{
		std::cout << "Card: ";
		hand[i]->PrintCard();
		std::cout << " " << hand[i]->GetValue() << std::endl;
	}

	//Dec on of the ace cards and print them all out again
	hand[0]->DecValue();
    
    //make sure DecValue() worked properly
    if(hand[0]->m_value != 1)
    {
        std::cout << "error DecValue() did not decrement properly m_value: " << hand[0]->m_value << std::endl;
    }
        

	std::cout << "\n### First Ace should be 1 ###\n";
	for(int i = 0; i < hand.size(); i++)
	{
		std::cout << "Card: ";
		hand[i]->PrintCard();
		std::cout << " " << hand[i]->GetValue() << std::endl;
	}

	//This shows that with dynamic casting we can cycle through a hand and test
	//if a card is an Ace or not
	std::cout << "\n### Looking for all Aces ###\n";
	for(int i = 0; i < hand.size(); i++)
	{
		if(dynamic_cast<Ace*>(hand[i]))
		{
            //Make sure Ace has a value of 1 or 11
            if(hand[i]->m_value == 1 || 11)
            {
                std::cout << "Found an Ace\n";
                
            }
            else
            {
                std::cout << "error DecValue() did not decrement properly m_value: " << hand[i]->m_value <<std::endl;
            }
            
		}
		else
		{
			std::cout << "Not an Ace\n";
		}
	}

	//Find the first Ace that hasn't been decremented yet, should be hand[1], and
	//decrement the hand, then break out of the for loop
	//This will be useful for when someone busts but has an Ace in their hand at 11
	for(int i = 0; i < hand.size(); i++)
	{
		if(dynamic_cast<Ace*>(hand[i]))
		{
			if(!hand[i]->IsLow())
			{
				hand[i]->DecValue();
				break;
			}
		}
	}

	//Now print them all out again to make sure first two aces are now 1, but rest
	//are at 11
	std::cout << "\n### First two Aces now 1 ###\n";
	for(int i = 0; i < hand.size(); i++)
	{
		std::cout << "Card: ";
		hand[i]->PrintCard();
		std::cout << " " << hand[i]->GetValue() << std::endl;
	}
    
    if(hand[1]->m_value != 1)
    {
        std::cout << "error DecValue() did not decrement properly m_value: " << hand[0]->m_value << std::endl;
    }

	//Cycle through entire hand and decrement only the ace cards, not including the
	//ace that has already been decremented
	for(int i = 0; i < hand.size(); i++)
	{
		if(dynamic_cast<Ace*>(hand[i]))
		{
			hand[i]->DecValue();
            assert(hand[i]->m_value == 1);
		}
	}

    

    for(int i = 0; i < hand.size(); i++)
    {
        if(dynamic_cast<Ace*>(hand[i]))
        {
            //Make sure Ace has a value of 11
            if(hand[i]->m_value == 1)
            {
                
                //Now print them all out again with all Aces having a value of 1
                std::cout << "\n### All Aces are now 1 ###\n";
                for(int i = 0; i < hand.size(); i++)
                {
                    std::cout << "Card: ";
                    hand[i]->PrintCard();
                    std::cout << " " << hand[i]->GetValue() << std::endl;
                }
                
            }
            else
            {
                std::cout << "error DecValue() did not decrement properly m_value: " << hand[i]->m_value <<std::endl;
            }
        }
    }
    

	return 0;
}
