#include <iosteam>
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

Pot::PlaceBet(int)
{
	int userInput = -1;

	while(isnan(userInput))
	{
		std::cin.clear();
		std::cin.ignore();
	
		std::cout << "Please enter a number" << endl;
		std::cin >> userInput;
	}
	m_curBet = userInput;
}

Pot::DoubleDown() 
{
	std::string option = "";
	
	if(std::getline(std::cin, option))
	std::cout << "Would you like to double down?" << std::endl;

}

Pot::PrintPot()
{
	std::cout << "pot:" << m_curPot << std::endl; 
}

Pot::PrintBet()
{
	std::cout << "bet:" << m_curBet << std::endl;
}
