#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

std::vector<std::string> splitTokens(std::string string)
{
    std::vector<std::string> tokens;
    
    std::string currentString = "";

    for (unsigned int i = 0; i < string.length(); i++)
    {
        char currentChar = string[i];
        if ((currentChar == ' ' || currentChar == ';') && currentString.length() > 0)
        {
            tokens.push_back(currentString);
            currentString = "";
        }
        else
        {
            currentString += currentChar;   
        }
    }

    return tokens;
}

int parse(std::string line)
{
    std::vector<std::string> tokens = splitTokens(line);
    if (tokens.size() == 0)
    {
        return 0;
    }

    std::string command = tokens[0];

    std::string compilationLine = "";

    if (command == "g++" || command == "gcc")
    {
        system(line.c_str());
        return 0; 
    }
    else if (command == "co")
    {
        compilationLine = "g++ -c " + tokens[2] + " -o " + tokens[1];  
        system(compilationLine.c_str());
        return 0; 
    }

    return 0;
}

int main(int argc, char* argv[])
{

    printf("\n gco V0.1.0 \n\n");

    std::ifstream inputFile(argv[1]);
    if (inputFile.is_open())
    {
        printf("\n Opened File %s\n", argv[1]);
        
        std::string line;
        while (std::getline(inputFile, line))
        {
            printf("\n | Parsing \"%s\"\n", line.c_str());
            if (parse(line))
            {
                printf("\n ++ Failed to Parse %s \n", line.c_str());
                break;
            }
        }

        inputFile.close();
    }
    else
    {
        printf("\n ++ Generation File \"%s\" could not be accessed or found. \n", argv[1]);
    }

    return 0;
}
