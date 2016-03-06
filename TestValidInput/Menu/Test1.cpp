#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out1.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test1: GameMenu" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn1.txt");
    
    std::string line;
    int m_option = 0;
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
            //fileOut << line << std::endl;
            m_option = std::atoi(line.c_str());
            
            switch (m_option)
            {
                case 1:
                    //StartRound();
                    fileOut << "1 was entered" << std::endl;
                    break;
                case 2://Return out of StartGame to main
                    fileOut << "2 was entered" << std::endl;
                    break;
                case 3:
                    //HelpButton();
                    fileOut << "3 was entered" << std::endl;
                    break;
                case 4:
                    fileOut << "4 was entered" << std::endl;
                    break;
                default:
                    fileOut << "That option is not valid, try again..." << std::endl;
                    break;
            }
        }
    }
    
    fileIn.close();
    fileOut.close();
    return 0;
}


