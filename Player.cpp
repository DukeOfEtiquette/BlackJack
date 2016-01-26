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
	//Prints hands in the handList
	if(m_playerID == 0)
	{
		std::cout << "Dealer : ";  
		m_handList[0]->PrintHand();
		std::cout << std::endl;
	}
	else 
	{
		for(int i = 0; i < m_handList.size(); i++)
		{ 
			//std::cout << "Print Hands(): " << std::endl;
			std::cout << "Player" << m_playerID << ": ";
			m_handList[i]->PrintHand();
			std::cout << std::endl;
		}
	}
}

void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
