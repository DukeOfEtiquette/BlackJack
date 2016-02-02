#include <iostream>
#include <vector>
#include "Card.h"

class Card;

int main()
{
	std::vector<Card*> cards;
	Card* c;

	Card::Suit heart = Card::Heart;
	Card::Suit diamond = Card::Diamond;
	Card::Suit club = Card::Club;
	Card::Suit spade = Card::Spade;

	for(int i = 0; i < 4; i++)
	{
		for(int j = 2; j < 14; j++)
		{
			c = new Card(j, (Card::Suit)i);
			cards.push_back(c);
		}
	}

	int val;

	for(int i = 0; i < cards.size(); i++)
	{
		std::cout << "Card: ";
		cards[i]->PrintCard();
		val = cards[i]->GetValue();
		std::cout << " Value: " << val;
		std::cout << std::endl;
	}
    
	if(cards.size() % 48 != 0) // note 48 cards bcs Ace is not included
    {
		std::cout << "error cards vector does not have 48 cards\n";
    }
    for(int i = 0; i < cards.size(); i++)
    {
		if(cards[i] == 0)
		{
			std::cout << "error cards is pointing to null\n";
		}
        //check that every card has a valid value
        if(cards[i]->m_value < 2 || cards[i]->m_value > 13)
        {
            std::cout << "error the cards value is not in range" << std::endl;
        }
		else 
		{
			std::cout << "checked value at index:" << i << std::endl;
		}
    }
    std::cout << "\n\n\n";
    
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 13; j++)
        {
            if(cards[i]->m_suit % 4 == 0)
            {
                std::cout << "checked suit at:" << j << std::endl;
            }
            else
            {
                std::cout << "error not a suit of case:" << 0 << " at index:" << i <<std::endl;
            }
                
        }
    }
}
