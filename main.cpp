#include<iostream>
#include<cstring>
#include "Utility/CommandUtility.cpp"
int main()
{
    while (true)
    { 
        std::cout << "Write a command!" << std::endl;
        std::string command;
        std::getline(std::cin,command);
        CommandUtility::ParseCommand(command); 
    }

    return 0;
}