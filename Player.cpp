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
				break;
			}
		}
	}

	return true;
}

bool isValid(char option)
{
	if(option == 'h' || option == 'H' || option == 's' || option ==  'S')
		return true;
	else
		return false;
}

void Player::PlayHands()
{
	std::string option;
	bool validOption;

	for(int i = 0; i < m_handList.size(); i++)
	{
		validOption = false;

		while(!validOption)
		{
			m_handList[i]->PrintHand();
			std::cout << "\nPlayer" << m_playerID << " would you like to (h)it, (s)tand?>";
			std::getline(std::cin, option);

			if(!isValid(option[0]))
			{
				std::cout << "Invalid choice, pleese choose again.\n";
			}
			else{
				if(option[0] == 's' || option[0] == 'S')
				{
					validOption = true;
				}else{

					std::cout << "Option: " << option[0] << std::endl;
				}
			}
		}
	}

	std::cout << "\n\n";
}

void Player::DumpHands()
{
	//Dumps hands in a handList
	m_handList.clear();
}
