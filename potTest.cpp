#include <iostream>
#include <assert.h>
#include "Pot.h"

int main(int argc,char *argv[])
{
    std::cout << "Pot Test" << std::endl;
    
    Pot* pot1 = new Pot(500);
    assert(pot1->m_curPot != 0);
    
    Pot* pot2 = new Pot(500);
    assert(pot2->m_curPot != 0);
    
    std::cout << "pot1 Pot:" << pot1->m_curPot << std::endl;
    std::cout << "pot2 Pot:" << pot2->m_curPot << std::endl;
    
    pot1->PlaceBet(50);
    std::cout << "curPot1:" << pot1->m_curPot << std::endl;
    std::cout << "curBet1:" << pot1->m_curBet << std::endl;
    
    pot2->PlaceBet(50);
    std::cout << "curPot2:" << pot1->m_curPot << std::endl;
    std::cout << "curBet2:" << pot1->m_curBet << std::endl << std::endl;
    
    pot1->DoubleDown();
    std::cout << "curPot1 DoubledDown:" << pot1->m_curPot << std::endl;
    std::cout << "curBet1 DoubledDown:" << pot1->m_curBet << std::endl;
    
    //buy insurance if you think dealer has blackjack
    pot1->BuyInsurance(100);
    std::cout << "insurance1:" << pot1->m_curInsurance << std::endl;
    std::cout << "curPot1:" << pot1->m_curPot << std::endl;
    
    bool blackjack = true;
    pot2->AddWinnings(blackjack);
    std::cout << "curPot2:" << pot2->m_curPot << std::endl;
    std::cout << "curBet2:" << pot2->m_curBet << std::endl << std::endl;
    
    pot1->ResetBets();
    assert(pot1->m_curBet == 0);
    assert(pot1->m_curInsurance == 0);
    
    
    pot1->PrintPot();
    pot1->PrintBet();
    
}

