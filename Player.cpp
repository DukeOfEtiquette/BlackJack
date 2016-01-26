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
	
	m_handList.push_back(h);
	m_handList[index]->m_hand.pop_back();
}	

void Player::AddStartingHand(Hand* hand)
{
	//Adds starting hands to handList
	m_handList.push_back(hand);
}

void Player::PrintHands()
{
	//Prints hands in the handList
		for(int i = 0; i < m_handList.size(); i++)
		{ 
			//std::cout << "Print Hands(): " << std::endl;
			std::cout << "Player" << m_playerID << ": ";
			m_handList[i]->PrintHand();
		}
}

bool Player::CanSplit(int iHand)
{
	if(m_handList[iHand]->m_hand[0]->m_value == m_handList[iHand]->m_hand[1]->m_value)
	{
		return true;
	}

	return false;
}

bool Player::DecAce(int iHand)
{
	//Find the first Ace that hasn't been decremented yet, and
	//decrement the hand, then break out of the for loop
	for(int i = 0; i < m_handList[iHand]->m_hand.size(); i++)
	{
		if(dynamic_cast<Ace*>(m_handList[iHand]->m_hand[i]))
		{
			if(!m_handList[iHand]->m_hand[i]->IsLow())
			{
				m_handList[iHand]->m_hand[i]->DecValue();
				return true;
			}
		}
	}

	return false;
}

void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
