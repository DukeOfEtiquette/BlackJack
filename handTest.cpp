#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"

int main()
{
		std::vector<Card*> hand;
		Card* c;
		
		Card::Suit spade = Card::Spade;
		Card::Suit heart = Card::Heart;
		Card::Suit club = Card::Club;
		Card::Suit diamond = Card::Diamond;

		for (int i = 2; i < 14; i++) {
				c = new Card(i, spade);
				hand.push_back(c);
		}

		for (int i = 2; i < 14; i++) {
				c = new Card(i, heart);
				hand.push_back(c);
		}
		for (int i = 2; i < 14; i++) {
				c = new Card(i, club);
				hand.push_back(c);
		}
		for (int i = 2; i < 14; i++) {
				c = new Card(i, diamond);
				hand.push_back(c);
		}
		
		for (int i = 0; i < hand.size(); i++)
		{
				int val;
				std::cout << "Card: ";
				hand[i]->PrintCard();
				val = hand[i]->GetValue();
				std::cout << " Value: " << val;
				std::cout << std::endl;
				//hand.SumHand();
		}
}

