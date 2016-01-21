
#ifndef Hand_cpp
#define Hand_cpp

#include "Card.h"
#include <vector>

class Hand
{
public:
    Hand(int size);
    std::vector<Card*> handy;
    int SumHand();
    void PrintHand();
    void DumpHand();
private:
    int m_handID;
};

Hand::Hand(int id) {
    m_handID = id;
}

#endif