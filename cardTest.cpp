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

	for(int i = 2; i < 14; i++)
	{
		c = new Card(i, heart);
		cards.push_back(c);
	}

	for(int i = 2; i < 14; i++)
	{
		c = new Card(i, diamond);
		cards.push_back(c);
	}
	for(int i = 2; i < 14; i++)
	{
		c = new Card(i, club);
		cards.push_back(c);
	}
	for(int i = 2; i < 14; i++)
	{
		c = new Card(i, spade);
		cards.push_back(c);
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
}
