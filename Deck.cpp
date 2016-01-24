#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include "Deck.h"
#include "Ace.h"


Deck::Deck(int sets)
{
	m_nSets = sets; //sets is passed in, m_nSets is used in InitializeSets
	InitializeSet();
}

Deck::~Deck()
{
	//Destroy all Cards still in hand
	m_deck.clear();
}

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
////			a = new Ace(1, (Card::Suit)j);

			for(int k = 2; k < 14; k++)
			{
				c = new Card(k, (Card::Suit)j);
				m_deck.push_back(c);
			}
		}
	}
}

int shuffleRandom(int i) {return std::rand()%i;}

void Deck::Shuffle()
{
	//Seed a random time
	std::srand(unsigned(std::time(0)));

	//This will shuffle everything in the vector using our custom random	
	std::random_shuffle(m_deck.begin(), m_deck.end(), shuffleRandom);
}

Card* Deck::DealCard()
{
	//Here we set the value of c to be the card at the end of the deck
	//We then pop that card off the deck and return c
	Card* c = m_deck.back();
	m_deck.pop_back();
	
	return c;
}
