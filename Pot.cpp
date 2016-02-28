#include <iostream>
#include "Pot.h"

Pot::Pot(int initialPot)
{
    m_curPot = m_initialPot = initialPot;
	m_curBet = m_curInsurance = 0;
}

bool Pot::PlaceBet(int bet)
{
//	int userInput = -1;
//
//	while(isnan(userInput))
//	{
//		std::cin.clear();
//		std::cin.ignore();
//	
//		std::cout << "Please enter a number" << std::endl;
//		std::cin >> userInput;
//	}

	if(bet > m_curPot)
	{
		std::cout << "You do not have enough chips to make that bet, try again.\n";
		return false;
	}else if(bet == 0)
	{
		std::cout << "Cannot bet 0, try again.\n";
		return false;
	}
	else
	{
		m_curBet += bet;
		m_curPot -= bet;
		return true;
	}
}

void Pot::DoubleDown()
{
    PlaceBet(m_curBet);
}

void Pot::BuyInsurance(int insurAmount)
{
    m_curInsurance += insurAmount;
    m_curPot -= insurAmount;
}

void Pot::AddWinnings(bool blackjack)
{
	std::cout << "i got here " << std::endl;
	m_curPot += m_curBet * (blackjack ? 2.5 : 2);
}

bool Pot::ResetBets()
{
    m_curBet = m_curInsurance = 0;

	if(m_curPot == 0)
	{
		m_curPot = m_initialPot;
		return true;
	}

	return false;
}

void Pot::PrintPot()
{
    std::cout << "Pot: " << m_curPot << std::endl;
}

void Pot::PrintBet()
{
    std::cout << "Bet: " << m_curBet << std::endl;
}

bool Pot::CanDoubleDown()
{
	return m_curBet <= m_curPot ? true : false;
}

bool Pot::CanBuyInsur()
{
	return m_curBet/2 <= m_curPot ? true : false;
}

void Pot::PushWinnings()
{
	m_curPot += m_curBet;
}
