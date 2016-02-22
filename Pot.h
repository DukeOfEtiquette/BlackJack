#ifndef _POT_H_INCLUDED
#define _POT_H_INCLUDED
#include "Card.h"
#include "Hand.h"
#include "Player.h"
#include <vector>

class Pot
{
public:
	Pot(int);
	~Pot();

	int m_curBet; 
	int m_curPot;
	int m_curInsurance;
	
	void PlaceBet(int);
	void DoubleDown();
	void BuyInsurance(int);
	void AddWinnings(bool);

	void PrintPot();
	void PrintBet();
}; 
#endif

