#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out0.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test0: Init Decks" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn0.txt");
    
    std::string line;
    int nDecks = 0;
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            nDecks = atoi(line.c_str());
            if (nDecks < 1)
            {
                 fileOut << nDecks << ":Invalid number of players or decks passed" << std::endl;
            }
            else
            {
                fileOut << nDecks << ":successfully initialized" << std::endl;
            }
        }
    }
    
    fileIn.close();
    fileOut.close();
    return 0;
}


