#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out1.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test1: Player Double Down" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn1.txt");
    
    std::string line;
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            fileOut << "Player" << " would you like to double down? (y/n): ";
            
            if(line[0] == 'y' || line[0] == 'Y')
            {
                fileOut << line << ":You doubled down" << std::endl;
            }
            else if(line[0] == 'n' || line[0] == 'N')
            {
                fileOut << line << ":You did not doubled down" << std::endl;
            }
            else
            {
                fileOut << line << ":Not a valid option, try again" << std::endl;
            }

        }
    }
    
    fileIn.close();
    fileOut.close();
    return 0;
}


