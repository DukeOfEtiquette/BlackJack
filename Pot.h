#ifndef _POT_H_INCLUDED
#define _POT_H_INCLUDED

class Pot
{
public:
    Pot(int);
    
	int m_initialPot;
    int m_curBet;
    int m_curPot;
    int m_curInsurance;
    
    void Surrender();
    void AwardInsurance();
    bool PlaceBet(int);
    void DoubleDown();
    void BuyInsurance(int);
    void AddWinnings(bool);
	void PushWinnings();
    bool ResetBets();
	bool CanDoubleDown();
	bool CanBuyInsur();
    
    void PrintPot();
    void PrintBet();
}; 

#endif

