#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Deck.h"

/***********************************************************************************
 * Purpose: Constructor for Deck, comes from Card.cpp and is used in Board.cpp
 * In: int sets is passed and represents the number of decks that will be created
 * Out: Sets m_nSets of Deck equal to the sets passed and Initialzes a Deck
***********************************************************************************/
Deck::Deck(int sets)
//Deck is a vector of cards. It comes from Card.cpp and is used in Board.cpp
{
	m_nSets = sets; //sets is passed in, m_nSets is used in InitializeSets
	InitializeSet();
}

/***********************************************************************************
 * Purpose: Destructor for Deck
 * Out: Clears a Deck and sets its size to 0
***********************************************************************************/
Deck::~Deck()
{
	//Destroy all Cards still in hand
	m_deck.clear();
}

/***********************************************************************************
 * Purpose: Initializes a Deck
 * Out: A Deck of cards is created with 52 cards. 
***********************************************************************************/
void Deck::InitializeSet()
{
	//Pointer to a Card and Ace to be used while creating a Deck
	Card* c;
	Ace* a;

	//The i loop will occur once for every set of cards we want to make
	//The j loop will happen once for every suit in a set
	//The k loop will happen for values 2 through 13, or 2 through King
	for(int i = 0; i < m_nSets; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			a = new Ace(1, (Card::Suit)j);

			for(int k = 2; k < 14; k++)
			{
				c = new Card(k, (Card::Suit)j);
				m_deck.push_back(c);
			}
		}
	}
}

/***********************************************************************************
 * Purpose: Shuffles a Deck seeded off of a random time
 * Out: A Deck is shuffled from the begining to the end 
***********************************************************************************/
int shuffleRandom(int i) {return std::rand()%i;}

void Deck::Shuffle()
{
	//Seed a random time
	std::srand(unsigned(std::time(0)));

	//This will shuffle everything in the vector using our custom random	
	std::random_shuffle(m_deck.begin(), m_deck.end(), shuffleRandom);
}

/***********************************************************************************
 * Purpose: Deal a Card
 * Out: A Card will be popped off of the Deck and the method will return a pointer 
 *		to that card
***********************************************************************************/
Card* Deck::DealCard()
{
	//Here we set the value of c to be the card at the end of the deck
	//We then pop that card off the deck and return c
	Card* c = m_deck.back();
	m_deck.pop_back();
	
	return c;
}
