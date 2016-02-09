#include <iostream>
#include "Hand.h"
#include "Player.h"
#include "Card.h"


/***********************************************************************************
 * Purpose: Player constructor. No default constructor
 * In: The id that will referance the player
 * Out: Assigns id passed to the member variable m_playerID
***********************************************************************************/
Player::Player(int id)
{
	m_playerID = id;//Use
}

/***********************************************************************************
 * Purpose: Player destructor
 * Out: The player's handlist will be empty
***********************************************************************************/
Player::~Player()
{
	for(int i = 0; i < m_handList.size(); i++)
	{
		delete m_handList[i];
	}

	m_handList.clear();
}

/***********************************************************************************
 * Purpose: This function will split a players hand into two hands
 * In: The index of which hand in m_handList that needs to split
 * Out: m_handList[index] will have one card and the last element of m_handList will
 *		have one card. THey are dealt a new card by the Board
***********************************************************************************/
void Player::Split(int index)
{
	//Create a new Hand object and move a card from splitting hand into it
	Hand* h = new Hand(m_handList.size());
	h->m_hand.push_back(m_handList[index]->m_hand.back());
	m_handList[index]->m_hand.pop_back();

	//If splitting a double Ace then Inc first Ace back up to value of 11
	if(dynamic_cast<Ace*>(m_handList[index]->m_hand[0]))
	{
		dynamic_cast<Ace*>(m_handList[index]->m_hand[0])->IncValue();;
	}
	
	//Add new hand to handlist
	AddHand(h);
}	

/***********************************************************************************
 * Purpose: This function will add a Hand pointer to the handList
 * In: A Hand pointer that will be added to the handList
 * Out: The handList will now contain a pointer to a Hand 
 ***********************************************************************************/
void Player::AddHand(Hand* hand)
{
	m_handList.push_back(hand);
}

bool Player::PrintHand(int iHand)
{
	std::cout << "Player " << m_playerID << ": ";
	return m_handList[iHand]->PrintHand();
}

/***********************************************************************************
 * Purpose: This function will print all of the hands in the handList to stdout
 ***********************************************************************************/
void Player::PrintHands()
{
	for(int i = 0; i < m_handList.size(); i++)
	{
		std::cout << "Player " << m_playerID << ": ";
		m_handList[i]->PrintHand();
	}
}

/***********************************************************************************
 * Purpose: This function will determine if a hand can be split
 * In: The index of the handList to check
 * Out: Will return true if the handList can be split else false
 ***********************************************************************************/
bool Player::CanSplit(int iHand)
{
	return m_handList[iHand]->CanSplit();
}

/***********************************************************************************
 * Purpose: Will dump a handlist
 * Out: Clears handList and sets the handList size to 0
 ***********************************************************************************/
void Player::DumpHands()
{
	m_handList.clear();
}
