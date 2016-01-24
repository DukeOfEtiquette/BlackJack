#include <iostream>
#include <vector>
#include "Deck.h"
#include "Hand.h"

int main()
{
	Deck* deck = new Deck(2);

	std::vector<Hand*> handList;
	Hand* h;

	for(int i = 0; i < 2; i++)
	{
		h = new Hand(i);
		handList.push_back(h);
	}

	std::cout << "### Top of the deck ###\n";
	deck->m_deck.back()->PrintCard();
	std::cout << std::endl;

	handList[0]->m_hand.push_back(deck->DealCard());

	std::cout << "### Printing hand[0] ###\n";
	handList[0]->PrintHand();

	return 0;
}
