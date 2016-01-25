#include <iostream>
#include "Hand.h"
#include "Player.h"
#include "Card.h"

Player::Player()
{

}

void Player::Split(std::vector<Card*> splitHand)
{
	//Splits a hand that is passed to it
	//Hand is poped off of the split hand and is added to the handList
	Hand* h = new Hand(0);
   	//h->m_hand.push_back(splitHand.pop_back());
	m_handList.push_back(h);
	splitHand.pop_back();
}	

void Player::AddStartingHand(std::vector<Card*> hand)
{
	//Adds starting hands to handList
	m_handList.push_back(new Hand(0));
}

void Player::PrintHands()
{
	//Prints hands in the handList
	for(int i = 0; i < m_handList.size(); i++)
	{ 
		//std::cout << "Print Hands(): " << std::endl;
		m_handList[i]->PrintHand();
	}
}

void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
