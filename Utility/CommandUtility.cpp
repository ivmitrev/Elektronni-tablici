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

std::string CommandUtility::ParseCommand(const std::string& comm)
{   
    std::vector<std::string> commArgs = FileUtility::splitBy(comm, " ");

    if(commArgs.empty())
    {
        std::cout << "Command input must not be empty!" << std::endl;
        return "";
    }
    else
    {  
        const std::string command = commArgs[0];
        if(command == "open" && commArgs.size() == 2)
        {
            return "open";
        }
        else if(command == "close" && commArgs.size() == 1)
        {
            return "close";
        }
        else if(command == "save" && commArgs.size() == 1)
        {
            return "save";
        }
        else if(command == "saveas" && commArgs.size() == 2)
        {
            return "saveas";
        }
        else if(command == "help" && commArgs.size() == 1)
        {
            return "help";
        }
        else if(command == "exit" && commArgs.size() == 1)
        {
            return "exit";
        }
        else if(command == "print" && commArgs.size() == 1)
        {
            return "print";
        }
        else if(command == "edit" && commArgs.size() == 4)
        {
            return "edit";
        }
        else
        {
            std::cout << "Invalid command arguments" << std::endl;
            return "";
        }
    }
}

Table* CommandUtility::ExecuteCommand(const std::string& comm, Table* table)
{
    std::string parsedCommand = ParseCommand(comm);
    std::vector<std::string> commArgs = FileUtility::splitBy(comm," ");
    if(parsedCommand == "open")
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
        int rowIndex = 1, colIndex = 1;
        for(const auto& line : lines)
        {
            Row* row = new Row();
            std::vector<std::string> splitLine = FileUtility::splitBy(line, ", ");        
            for(const std::string& cell : splitLine)
            {
               
                std::string trimmedCell = FileUtility::trim(cell); 
                Cell* newCell = CellUtility::createCellFromInput(trimmedCell);
                if(newCell == nullptr)
                {
                    std::cout << "Error: row " << rowIndex << ", col " << colIndex << ", " << trimmedCell << " is unknown data type." << std::endl;
                    filePath = "";
                    return nullptr;
                }
                row->addCell(newCell);
                colIndex++;
            }
            for (int i = 0; i < maxRowWidth-splitLine.size(); i++)
            {
                row->addCell(CellUtility::createCellFromInput(" "));
            }
                
            table->addRow(row);
            colIndex=1;
            rowIndex++;
        }  
        return table;
    }
    else if(parsedCommand == "close")
    {
        if(!filePath.empty())
        {
            delete table;
            std::cout << "Successfully closed " << filePath << std::endl;
            filePath="";
        }
        else
        {
            std::cout << "Should open file first" << std::endl;
        }
    }
    else if(parsedCommand == "save")
    {
        if(!filePath.empty())
        {
            if(table == nullptr)
            {
                std::cout << "Invalid table pointer" << std::endl;
                return nullptr;
            }

            if(FileUtility::saveFile(table,filePath))
            {
                std::cout << "Successfully saved " << filePath << std::endl;
            }
        }
        else
        {
            std::cout << "Should open file first" << std::endl;
        }

    }
    else if(parsedCommand == "saveas")
    {
        if(!filePath.empty())
        {
            if(table == nullptr)
            {
                std::cout << "Invalid table pointer" << std::endl;
            }
            
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
    else if(parsedCommand == "help")
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
    else if(parsedCommand == "exit")
    {
        delete table;
        exit(0);
    }
    else if(parsedCommand == "print")
    {
        if(!filePath.empty())
        {
            if(table == nullptr)
            {
                std::cout << "Invalid table pointer" << std::endl;
                return nullptr;
            }


            table->calculatingFormulas();
            table->printAll();
        }
        else
        {
            std::cout << "Should open file first" << std::endl;
        }
            
    }
    else if(parsedCommand == "edit")
    {
        if(!filePath.empty())
        {
            if(table == nullptr)
            {
                std::cout << "Invalid table pointer" << std::endl;
                return nullptr;
            }    
        
            try
            {
                table->edit(std::stoi(commArgs[1]),std::stoi(commArgs[2]),commArgs[3]);
            }
            catch(const std::invalid_argument& e)
            {
                std::cout << "Invalid argument in row or column" << std::endl;
            }
            catch(const std::out_of_range& e)
            {
                std::cout << "Invalid argument in row or column" << std::endl;
            }
        }
        else
        {
            std::cout << "Should open file first" << std::endl;
        }
           
    }
    return nullptr;
}
