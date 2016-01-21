#include <iostream>
#include <vector>
#include "Card.h"
#include "Hand.h"
#include "assert.h"


int main()
{
    Hand* hand = new Hand(1);   // handID id 1
    
    Card* c;
    
    Card::Suit heart = Card::Heart;
    Card::Suit diamond = Card::Diamond;
    Card::Suit club = Card::Club;
    Card::Suit spade = Card::Spade;
    
    for(int i = 2; i < 14; i++)
    {
        c = new Card(i, heart);
        hand->handy.push_back(c);
    }
    
    for(int i = 2; i < 14; i++)
    {
        c = new Card(i, diamond);
        hand->handy.push_back(c);
    }
    for(int i = 2; i < 14; i++)
    {
        c = new Card(i, club);
        hand->handy.push_back(c);
    }
    for(int i = 2; i < 14; i++)
    {
        c = new Card(i, spade);
        hand->handy.push_back(c);
    }
    
    int val;
    
    for(int i = 0; i < hand->handy.size(); i++)
    {
        std::cout << "Card: ";
        hand->handy[i]->PrintCard();
        val = hand->handy[i]->GetValue();
        std::cout << " Value: " << val;
        std::cout << std::endl;
    }
    val = hand->SumHand();
    std::cout << "SumHand(): " << val << std::endl;
    hand->PrintHand();
    
    hand->DumpHand();
    assert(hand->handy[0] == 0);
    
}




