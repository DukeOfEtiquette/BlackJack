#include <iostream>
#include <fstream>
#include <string>
#include <math.h>


int main()
{
    std::ofstream fileOut ("out1.txt");
    
    if (fileOut.is_open())
    {
        fileOut << "Test1: Player Split" << std::endl <<std::endl;
    }
    
    std::ifstream fileIn ("TestIn1.txt");
    
    std::string line;
    
    if (fileIn.is_open())
    {
        while (getline(fileIn, line))
        {
         
            //Used right below this to record input
            
            fileOut << "Would you like to split this hand (y/n): " << std::endl;
            
            if(line[0] == 'y' || line[0] == 'Y')
            {
                fileOut << line << ":split successful" << std::endl;
            }
            else if(line[0] == 'n' || line[0] == 'N')
            {
                fileOut << line << ":chose not to split" << std::endl;
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


