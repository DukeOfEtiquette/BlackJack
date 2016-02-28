#ifndef _DECK_H_INCLUDED
#define _DECK_H_INCLUDED

#include "Card.h"
#include "Ace.h"
#include <vector>

class Deck
{
public:

/*! \var std::vector<Card*> m_deck
 *  \brief Contains all the cards in the game deck
 *
 *  This vector holds pointers to all cards in the game deck. As cards are dealt to
 *  players the size will get smaller as those cards are removed. When it gets
 *  below 50% of it's starting size it will reinitialize to a full deck
 */

/*! \fn void InitializeSet()
 *  \brief Creates a game deck
 *
 *  This function is used to make the game deck with m_deck.
 */

/*! \fn void Shuffle()
 *  \brief Shuffles m_deck
 *
 *  Since InitializeSet create the deck in a specific order, this function will
 *  actually shuffle the deck into a random order for us.
 */

/*! \fn Card* DealCard()
 * 
 *  This will pop off the top Card in m_deck and return it
 */

/*! \fn Deck(int)
 *  \brief The one consructor
 *
 *  This is the only constructor for the class. It takes a single int the 
 *  represents the number of set of cards to use for the deck
 */

/*! \fn ~Deck()
 *
 *  Standard destructor.
 */

/*! \var int m_nSets
 *  \brief Number of sets in the deck
 *
 *  The int passed to the constructor is stored in a member variable for later use
 *  in InitializeSet() once m_deck is reduced below 50% of it's starting size
 */
	std::vector<Card*> m_deck;
	void InitializeSet();
	void Shuffle();
	Card* DealCard();
	Deck(int);
	~Deck();
	int m_nSets;

};


#endif
