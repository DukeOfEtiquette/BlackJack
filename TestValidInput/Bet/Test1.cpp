#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out1.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test1: Player Bet" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn1.txt");
    
    std::string line;
    int bet = 500; //init amount a bet has
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            bet = std::atoi(line.c_str());
            fileOut << "Player" << " please enter your bet" << std::endl;
            if(bet > 500 || bet <= 0)
                fileOut << bet << ":Not a valid option, try again" << std::endl;
            else
                fileOut << bet << ":Player has bet" << std::endl;
        }
    }
    
    fileIn.close();
    fileOut.close();
    return 0;
}


