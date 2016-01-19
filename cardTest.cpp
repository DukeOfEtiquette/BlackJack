#include <iostream>
#include "Card.h"

class Card;

int main()
{
	Card::Suit suit = Card::Heart;
	Card* c = new Card(2, suit);
	Card* c2 = new Card(10, suit);

	std::cout << "Card: ";
	c->PrintCard();
	std::cout << std::endl;
	std::cout << "Card2: ";
	c2->PrintCard();
	std::cout << std::endl;

	return 0;
}
