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
	c = new Card(2, (Card::Suit)4);

    
    
    /**********************************************************************************
     * Graph Coverage
     ***********************************************************************************/
    if(cards == 0)
    {
        std::cout << "error cards is pointing to null/n";
    }
    if(cards.size() != 52)
    {
        std::cout << "error cards vector does not have 52 cards/n";
    }
    for(int i = 0; i < cards.size(); i++)
    {
        //check that every card has a valid value
        if(cards[i]->m_value < 1)
        {
            std::cout << "error the cards value is less than 1" << std::endl;
        }
        //check that every card has a suit
        if(cards[i]->m_suit == 'x')
        {
            std::cout << "error the card at " << i << " has no suit" << std::endl;
        }
        //test if cards have mod 4 suit
        if(cards[i]->m_suit != % 4)
        {
            std::cout << "error not mod 4 suit" << std::endl;
        }
        //test if cards have mod 11 value
        if(card[i]->m_value != % 11)
        {
            std::cout << "error not mod 11 value" << std::endl;
        }	
    }
}


