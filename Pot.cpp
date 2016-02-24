#include <iostream>
#include <vector>
#include <math.h>
#include "Card.h"
#include "Hand.h"
#include "Player.h"

Pot::Pot(int potNum)
{
	m_curPot = potNum;
}

Pot::~Pot()
{

}

void Pot::PlaceBet(int)
{
	int userInput = -1;

	while(isnan(userInput))
	{
		std::cin.clear();
		std::cin.ignore();
	
		std::cout << "Please enter a number" << std::endl;
		std::cin >> userInput;
	}
	m_curBet = userInput;
}

void Pot::DoubleDown() 
{
	std::string option = "";
	
	if(std::getline(std::cin, option))
	std::cout << "Would you like to double down?" << std::endl;
}

void Pot::BuyInsurance(int)
{

}

void Pot::AddWinnings(bool)
{

}

void Pot::ResetBets()
{

}

void Pot::PrintPot()
{
	std::cout << "pot:" << m_curPot << std::endl; 
}

void Pot::PrintBet()
{
	std::cout << "bet:" << m_curBet << std::endl;
}
