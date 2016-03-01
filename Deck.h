#ifndef _DECK_H_INCLUDED
#define _DECK_H_INCLUDED

#include "Card.h"
#include "Ace.h"
#include <vector>

class Deck
{
public:
    /*!
     * A Deck is represented as a vector of cards
     */
	std::vector<Card*> m_deck;
    /*!
     * A Deck of cards is created with 52 cards.
     */
    void InitializeSet();
    /*!
     * Shuffles a Deck seeded off of a random time
     */
    void Shuffle();
    /*!
     * A Card will be popped off of the Deck and the method will return a pointer
     *		to that card
     */
	Card* DealCard();
    /*!
     * Constructor for deck, derived from Card
     */
    Deck(int);
    /*!
     * Destructor for deck
     */
	~Deck();
    /*!
     * integer variable to keep track of the number of decks
     */
	int m_nSets;
};


#endif
