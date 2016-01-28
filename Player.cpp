#include <iostream>
#include "Hand.h"
#include "Player.h"
#include "Card.h"


/***********************************************************************************
 * Purpose: Player constructor, uses Hand.cpp, used in Board.cpp
 * In: The id that will referance the player
 * Out: Assigns id passed to the member playerID
***********************************************************************************/
Player::Player(int id)
//Player contains a m_handList which is a vector of hands comes from Hand.cpp used in Board.cpp 
//No default constructor, this is the only constructor that will be used
{
	//Passes ID and assing it to m_playerID
	m_playerID = id;
}

/***********************************************************************************
 * Purpose: This function will split a players hand into two hands.
 * In: The index of which hand in m_handList that needs to split
 * Out: m_handList[index] will have one card and the last element of m_handList will
 *		have one card.
***********************************************************************************/
void Player::Split(int index)
{
	//Splits a hand located at the index of m_handList apart of Player.h
	Hand* h = new Hand(m_handList.size());
	h->m_hand.push_back(m_handList[index]->m_hand.back());
	
	//Stores of the hand into the next location in m_handList
	m_handList.push_back(h);
	m_handList[index]->m_hand.pop_back();
}	

/***********************************************************************************
 * Purpose: This function will add the starting hands to the handList of player
 * In: The Hand* that will be added to the handList of player
 * Out: The handList of the player will now contains a pointer to a hand 
 ***********************************************************************************/
void Player::AddStartingHand(Hand* hand)
{
	//Adds starting hands to handList
	m_handList.push_back(hand);
}

/***********************************************************************************
 * Purpose: This function will print all of the hands in the handList.
 * Out: The Players and Hands are printed and the sum of the cards is printed if the 
 *		sum is less than 21 and prints Bust if their sum is greater than 21
 ***********************************************************************************/
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

/***********************************************************************************
 * Purpose: This function will determines if a hand can be split
 * In: The index of the handList
 * Out: Will return true or false if the handList can be split
 ***********************************************************************************/
bool Player::CanSplit(int iHand)
{
	return m_handList[iHand]->CanSplit();
}


/***********************************************************************************
 * Purpose: Will dump a Players hands
 * Out: Clears all of a Players handList and sets the handList size to 0
 ***********************************************************************************/
void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
