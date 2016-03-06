#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out0.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test0: Init Pot" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn0.txt");
    
    std::string line;
    int bet = 0;
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            bet = std::atoi(line.c_str());
            if (bet < 1)
            {
                fileOut << bet << ":Invalid pot number passed" << std::endl;
            }
            else
            {
                fileOut << bet << ":successfully initialized" << std::endl;
            }
        }
    }
    
    fileIn.close();
    fileOut.close();
    return 0;
}


