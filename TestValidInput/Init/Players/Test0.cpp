#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out0.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test0: Init Players" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn0.txt");
    
    std::string line;
    int nPlayers = 0;
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            nPlayers = std::atoi(line.c_str());
            if (nPlayers < 2)
            {
                fileOut << nPlayers << ":Invalid number of players or decks passed" << std::endl;
            }
            else
            {
                fileOut << nPlayers << ":successfully initialized" << std::endl;
            }
        }
    }
    
    fileIn.close();
    fileOut.close();
    return 0;
}


