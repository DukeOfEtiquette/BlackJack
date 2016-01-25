#include <iostream>
#include "Hand.h"
#include "Player.h"
#include "Card.h"

Player::Player()
{

}

void Player::Split(Hand* splitHand)
{
	//Splits a hand that is passed to it
	//Hand is poped off of the split hand and is added to the handList
	
	//Hand* h = new Hand(0);
	//m_handList.push_back(splitHand->m_hand.pop_back());
	
	m_handList.push_back(splitHand->m_hand.back());
	splitHand->m_hand.pop_back();
}	

void Player::AddStartingHand(Hand* hand)
{
	//Adds starting hands to handList
	m_handList.push_back(hand->m_hand.front());
}

void Player::PrintHands()
{
	//Prints hands in the handList
	for(int i = 0; i < m_handList.size(); i++)
	{ 
		//std::cout << "Print Hands(): " << std::endl;
		m_handList[i]->PrintCard();
	}
}

void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
