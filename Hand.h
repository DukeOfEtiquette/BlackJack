#ifndef Hand_H
#define Hand_H

#include "Card.h"
#include "Ace.h"
#include <vector>

class Hand
{
public:
	Hand(int);
    ~Hand();
    std::vector<Card*> m_hand;

    int SumHand();
    void PrintHand();
    void DumpHand();
    int m_handID;
};

#endif
