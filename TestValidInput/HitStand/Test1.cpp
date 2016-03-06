#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out1.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test1: Player Hit or Stand" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn1.txt");
    
    std::string line;
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            //Ask player if they want to hit or stay
            fileOut << "Player " << " would you like to (h)it, (s)tand for Hand " << "?>";
            
            if(line[0] == 'h' || line[0] == 'H')
            {
                fileOut << line << ":You were dealt a card" << std::endl;
            }
            else if (line[0] == 's' || line[0] == 'S')
            {
                fileOut << line << ":You stood" << std::endl;
            }
            else
            {
                fileOut << line << ":Not valid input" << std::endl;
            }
        }
    }
    
    fileIn.close();
    fileOut.close();
    return 0;
}


