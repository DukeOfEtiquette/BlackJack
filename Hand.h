#ifndef Hand_H
#define Hand_H

#include "Card.h"
#include "Ace.h"
#include <vector>

class Hand
{
public:
    //Constructor assigns int passed to m_handID
	Hand(int);
	//Destructor clears the m_hand vector
    ~Hand();
	//Hand vector m_hand will contain cards, used in Board.cpp
    std::vector<Card*> m_hand;

    int SumHand();
    void PrintHand();
    void DumpHand();
    int m_handID;
};

#endif
