#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

struct command
{
    int index = 0;
    std::vector<std::string> args;
    std::vector<command> commands;
    command(int _index) {index = _index;};
};

std::vector<command> fileCommands;

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

    std::string providedCommand = tokens[0];

    std::string compilationLine = "";

    if (providedCommand == "g++")
    {
        command cmd(1);
        return 0; 
    }
    else if (providedCommand == "gcc")
    {
        command cmd(2);
        cmd.args.push_back();
    }
    else if (providedCommand == "co")
    {
        /*compilationLine = "g++ -c " + tokens[2] + " -o " + tokens[1];  
        system(compilationLine.c_str());*/
        command cmd(3);
        return 0; 
    } else if (providedCommand == "IF")
    {
        if (stat(tokens[1]))
        {

        }
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
