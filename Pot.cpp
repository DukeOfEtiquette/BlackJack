#include <iosteam>
#include <vector>
#include <math.h>

Pot::Pot(int initialPot)
{
	m_curPot = initialPot;
}

Pot::~Pot()
{

}

Pot::PlaceBet(int betAmount)
{
	m_curPot -= betAmount;
	m+curBet += betAmount;
}

Pot::DoubleDown() 
{
	PlaceBet(m_curBet);	
}

Pot::BuyInsurance(int insurAmount)
{
	m_curInsurance += insurAmount;
	m_curPot -= insurAmount;
}

Pot::AddWinnings(bool blackjack)
{
	if(blackjack)
	{
		m_curPot+= m_curBet * 1.5;
		m_curBet = 0;
	}
}

Pot::ResetBets()
{
	m_curBet = m_curInsurance = 0;
}

Pot::PrintPot()
{
	std::cout << "pot:" << m_curPot << std::endl; 
}

Pot::PrintBet()
{
	std::cout << "bet:" << m_curBet << std::endl;
}
