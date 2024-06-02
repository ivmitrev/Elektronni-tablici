#include "Runner.h"

void Runner::run()
{
    while (true)
    { 
        std::cout << "Write a command!" << std::endl;
        std::string command;
        std::getline(std::cin,command);
        Table* newTable = CommandUtility::ExecuteCommand(command, table); 
        if(newTable != nullptr)
        {
            table = newTable;
        }
    }
}