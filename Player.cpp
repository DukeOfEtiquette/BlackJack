#include <iostream>
#include "Hand.h"
#include "Player.h"
#include "Card.h"

Player::Player(int id)
{
	m_playerID = id;
}

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
	int sum = 0;

	//Prints hands in the handList
		for(int i = 0; i < m_handList.size(); i++)
		{ 
			//std::cout << "Print Hands(): " << std::endl;
			std::cout << "Player" << m_playerID << ": ";
			m_handList[i]->PrintHand();
			sum = m_handList[i]->SumHand();

			if(sum > 21)
			{
				std::cout << " - Bust!" << std::endl;
			}else{
				std::cout << " - Total: " << sum << std::endl;
			}
		}
}

bool Player::HasSplit(int iHand)
{
	if(m_handList[iHand]->m_hand[0]->m_value == m_handList[iHand]->m_hand[1]->m_value)
	{
		return true;
	}

	return false;
}

bool Player::HasAce()
{
	return true;
}

void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
