#include <iostream>
#include "Hand.h"
#include "Player.h"
#include "Card.h"

/***********************************************************************************
 * Purpose: Player constructor. No default constructor
 * In: The id that will referance the player
 * Out: Assigns id passed to the member variable m_playerID
 ***********************************************************************************/
Player::Player(int id, int potSize)
{
    m_playerID = id;//Use
	m_pot = new Pot(potSize);
}

/***********************************************************************************
 * Purpose: Player destructor, uses Hand.cpp, used in Board.cpp. No default destructor
 * Out: Deletes all hands in a handList
 ***********************************************************************************/
Player::~Player()
{
    for(int i = 0; i < m_handList.size(); i++)
    {
        delete m_handList[i];
    }
    
    //Clears the handList by setting its size to 0
    m_handList.clear();

	delete m_pot;
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
    //Adds starting hands to handList
    m_handList.push_back(hand);
}

/***********************************************************************************
 * Purpose: This function will print a hand in the handList at the given index
 * Out: A Player and a hand at a particular index is printed
 ***********************************************************************************/
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
    //Prints all hands in a players handList
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
    //Clears a players handList
    m_handList.clear();
}

/***********************************************************************************
 * Purpose: Determine if a player has blackjack
 * Out: Returns true if the sum of a players hand is 21
 ***********************************************************************************/
bool Player::HasBlackJack()
{
	for(int i = 0; i < m_handList.size(); i++)
	{
		if(m_handList[i]->SumHand() == 21)
			return true;
	}

	return false;
}

/***********************************************************************************
 * Purpose: See how much a players pot amount is
 * Out: Prints a players pot
 ***********************************************************************************/
void Player::PrintPot()
{
	m_pot->PrintPot();
}

/***********************************************************************************
 * Purpose: Places a players bet
 * Out: Sets a players current bet to the amount specified
 ***********************************************************************************/
bool Player::PlaceBet(int betAmount)
{
	return m_pot->PlaceBet(betAmount);
}

/***********************************************************************************
 * Purpose: Doubling Down
 * Out: Asks a player if they want to double down on their 1st card
 ***********************************************************************************/
void Player::DoubleDown()
{
	bool valid = false;

	do{
		std::string option = "";

		std::cout << "Player" << m_playerID << " would you like to double down? (y/n): ";
		std::getline(std::cin, option);

		if(tolower(option[0]) == 'y')
		{
			m_pot->DoubleDown();
			valid = true;
		}else if(tolower(option[0] == 'n'))
		{
			valid = true;
		}else
		{
			std::cout << "Not a valid option, try again.\n";
		}

	}while(!valid);
}

/***********************************************************************************
 * Purpose: Allows a player to Doubling Down
 * Out: Asks a player if they want to buy insurance if the dealers 1st card is an Ace
 ***********************************************************************************/
void Player::BuyInsurance()
{
	bool valid = false;
	bool bFail = false;

	do{
		std::string option;

		std::cout << "Player" << m_playerID << " would you like to buy insurance? (y/n): ";
		std::getline(std::cin, option);

		if(tolower(option[0]) == 'y')
		{
			int bet;
			
			do {
				std::cout << "Player" << m_playerID << " please enter your insurance bet> ";
				std::cin >> bet;
				bFail = std::cin.fail();
				if(bFail) 
					std::cout << "Not a valid option, try again.\n";
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}while(bFail);

			m_pot->BuyInsurance(bet);

			valid = true;
		}else if(tolower(option[0] == 'n'))
		{
			valid = true;
		}else
		{
			std::cout << "Not a valid option, try again.\n";
		}

	}while(!valid);
}

/***********************************************************************************
 * Purpose: Adds winnings to a players pot
 * Out: Adds winnings if a player has blackjack
 ***********************************************************************************/
void Player::AddWinnings(bool blackJack)
{
	m_pot->AddWinnings(blackJack);
}

/***********************************************************************************
 * Purpose: Handling if a player runs out of chips
 * Out: If a player runs out of chips, reset back to their initial amount
 ***********************************************************************************/
void Player::ResetBets()
{
	if(m_pot->ResetBets())
	{
		std::cout << "\nPlayer" << m_playerID << " you have run out of chips. Your pot has been reset to the initial amount.";
	}
}

/***********************************************************************************
 * Purpose: Check if a player can double down, used in Board.cpp
 * Out: return true if they can afford doubling down
 ***********************************************************************************/
bool Player::CanDoubleDown()
{
	return m_pot->CanDoubleDown();
}

/***********************************************************************************
 * Purpose: Check if a player can buy insurance, used in Board.cpp
 * Out: return true if they can afford insurance
 ***********************************************************************************/
bool Player::CanBuyInsur()
{
	return m_pot->CanBuyInsur();
}

/***********************************************************************************
 * Purpose: Push a players bet if they tie with the dealer
 * Out: On push, pushes a players winnings
 ***********************************************************************************/
void Player::PushWinnings()
{
	m_pot->PushWinnings();
}

/***********************************************************************************
 * Purpose: Check if a player has an Ace at a particular index
 * Out: returns the index of the 1st Ace if it finds one and -1 otherwise
 ***********************************************************************************/
int Player::AcePos(int index)
{
	return m_handList[index]->AcePos();
}

int Player::BlackjackPos()
{
	for(int i = 0; i < m_handList.size(); i++)
	{
		if(m_handList[i]->HasBlackjack())
			return i;
	}

	return -1;
}
