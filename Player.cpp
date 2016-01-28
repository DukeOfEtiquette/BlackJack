#include <iostream>
#include "Hand.h"
#include "Player.h"
#include "Card.h"

//No default constructor, this is only constructor that will be used
Player::Player(int id)
{
	m_playerID = id;
}

/***********************************************************************************
 * Purpose: This function will split a players hand into two hands.
 *
 * In: The index of which hand in m_handList that needs to split
 *
 * Out: m_handList[index] will have one card and the last element of m_handList will
 *		have one card.
***********************************************************************************/
void Player::Split(int index)
{
	Hand* h = new Hand(m_handList.size());
	h->m_hand.push_back(m_handList[index]->m_hand.back());

	//If splitting a double Ace then Inc first Ace back up to value of 11
	if(dynamic_cast<Ace*>(m_handList[index]->m_hand[0]))
	{
		dynamic_cast<Ace*>(m_handList[index]->m_hand[0])->IncValue();;
	}
	
	m_handList.push_back(h);
	m_handList[index]->m_hand.pop_back();
}	

void Player::AddStartingHand(Hand* hand)
{
	//Adds starting hands to handList
	m_handList.push_back(hand);
}

bool Player::PrintHand(int iHand)
{
	std::cout << "Player " << m_playerID << ": ";
	return m_handList[iHand]->PrintHand();
}

void Player::PrintHands()
{
	//Prints hands in the handList
		for(int i = 0; i < m_handList.size(); i++)
		{ 
			//std::cout << "Print Hands(): " << std::endl;
			std::cout << "Player " << m_playerID << ": ";
			m_handList[i]->PrintHand();
		}
}

bool Player::CanSplit(int iHand)
{
	return m_handList[iHand]->CanSplit();
}

void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
