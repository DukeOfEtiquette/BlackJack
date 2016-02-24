#include <iostream>
#include "Pot.h"

Pot::Pot(int initialPot)
{
    m_curPot = m_initialPot = initialPot;
	m_curBet = m_curInsurance = 0;
}

void Pot::PlaceBet(int bet)
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

	m_curBet += bet;
	m_curPot -= bet;
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
	m_curPot += m_curBet * (blackjack ? 2.5 : 2);
}

void Pot::ResetBets()
{
    m_curBet = m_curInsurance = 0;

	if(m_curPot == 0)
		m_curPot = m_initialPot;
}

void Pot::PrintPot()
{
    std::cout << "Pot: " << m_curPot << std::endl;
}

void Pot::PrintBet()
{
    std::cout << "Bet: " << m_curBet << std::endl;
}
