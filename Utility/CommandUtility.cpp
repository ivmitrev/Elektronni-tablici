#include "CommandUtility.h"
#include "../Types/Cell/Cell.h"
#include "../Types/Row/Row.h"
#include "../Types/Cell/IntCell.h"
#include "../Types/Cell/DoubleCell.h"
#include "../Types/Cell/StringCell.h"
#include "../Types/Table/Table.h"
#include "CellUtility.h"
#include "FileUtility.h"
// #include <typeinfo>

std::string filePath = "";

Table* CommandUtility::ParseCommand(const std::string& comm, Table* table)
{   
    std::vector<std::string> commArgs = FileUtility::splitBy(comm, " ");

    if(commArgs.empty())
    {
        std::cout << "Command input must not be empty!" << std::endl;
    }
    else
    {  
        const std::string command = commArgs[0];
        if(command == "open" && commArgs.size() == 2)
        {   
            table = new Table();
            filePath = commArgs[1];
            std::vector<std::string> lines = FileUtility::readFromFile(filePath);
            int maxRowWidth = 0;
            for(const auto& line : lines)
            {
                std::vector<std::string> splitLine = FileUtility::splitBy(line, ", ");
                if(maxRowWidth < splitLine.size())
                {
                    maxRowWidth = splitLine.size();
                }
            }
            for(const auto& line : lines)
            {
                Row* row = new Row();
                std::vector<std::string> splitLine = FileUtility::splitBy(line, ", ");
                for(const std::string& cell : splitLine)
                {
                    std::string trimmedCell = FileUtility::trim(cell); 
                    row->addCell(CellUtility::createCellFromInput(trimmedCell));
                }
                for (int i = 0; i < maxRowWidth-splitLine.size(); i++)
                {
                    row->addCell(CellUtility::createCellFromInput(" "));
                }
                
                table->addRow(row);
            }  
            return table;
        }
        else if(command == "close" && commArgs.size() == 1)
        {
            if(!filePath.empty())
            {
                delete table;
                std::cout << "Successfully closed " << filePath << std::endl;
                filePath="";
            }
            else
            {
                std::cerr << "Should open file first" << std::endl;
            }
        }
        else if(command == "save" && commArgs.size() == 1)
        {
            if(!filePath.empty())
            {
                if(FileUtility::saveFile(table,filePath))
                {
                    std::cout << "Successfully saved " << filePath << std::endl;
                }
            }
            else
            {
                std::cerr << "Should open file first" << std::endl;
            }

        }
        else if(command == "saveas" && commArgs.size() == 2)
        {
            if(!filePath.empty())
            {
               if(FileUtility::saveAsFile(table,commArgs[1]))
               {
                    std::cout << "Successfully saved " << commArgs[1] << " " << filePath << std::endl;
               }
            }
            else
            {   
                std::cerr << "Should open file first" << std::endl;
            }
        }
        else if(command == "help" && commArgs.size() == 1)
        {
            std::cout << R"(The following commands are supported:
open <file>	opens <file>
close			closes currently opened file
save			saves the currently open file
saveas <file>	saves the currently open file in <file>
help			prints this information
exit			exists the program
                )"<< std::endl;
            
        }
        else if(command == "exit" && commArgs.size() == 1)
        {
            delete table;
            exit(0);
        }
        else if(command == "print" && commArgs.size() == 1)
        {
            if(!filePath.empty())
            {
                table->calculatingFormulas();
                table->printAll();
            }
            else
            {
                std::cerr << "Should open file first" << std::endl;
            }
            
        }
        else if(command == "edit" && commArgs.size() == 4)
        {
            if(!filePath.empty())
            {
                try
                {
                    // stoi ako e drobno zakruglqva
                    table->edit(std::stoi(commArgs[1]),std::stoi(commArgs[2]),commArgs[3]);
                }
                catch(const std::invalid_argument& e)
                {
                    std::cerr << "Invalid argument in row or column" << std::endl;
                }
                catch(const std::out_of_range& e)
                {
                    std::cerr << "Invalid argument in row or column" << std::endl;
                }
            }
            else
            {
                std::cerr << "Should open file first" << std::endl;
            }
           
        }
        else
        {
            std::cerr << "Invalid command arguments" << std::endl;
        }
    }
}
bool ValidateCommand(const std::string& comm, const std::string arg);
void ExecuteCommand(const std::string& comm, const std::string arg);
