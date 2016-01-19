#include <iostream>
#include "Card.h"

class Card;

int main()
{
	Card::Suit suit = Card::Heart;
	Card* c = new Card(2, suit);

	std::cout << "Card: ";
	c->PrintCard();
	std::cout << std::endl;

	return 0;
}
