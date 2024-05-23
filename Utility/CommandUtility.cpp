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

void CommandUtility::ParseCommand(const std::string& comm)
{   
    std::vector<std::string> commArgs = FileUtility::splitBy(comm, " ");
    if(commArgs.empty())
    {
        std::cout << "Command input must not be empty!" << std::endl;
    }
    else
    {  
        const std::string command = commArgs[0];
        if(command == "open")
        {   
            std::string filePath = commArgs[1];
            std::vector<std::string> lines = FileUtility::readFromFile(filePath);
            Table table;
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
                
                table.addRow(row);
            }
            // !!!
           table.calculatingFormulas();
           table.printAll();
        }
        else if(command == "close")
        {
            
        }
        else if(command == "save")
        {

        }
        else if(command == "saveas")
        {

        }
        else if(command == "help")
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
        else if(command == "exit")
        {
            exit(0);
        }
    }
}
bool ValidateCommand(const std::string& comm, const std::string arg);
void ExecuteCommand(const std::string& comm, const std::string arg);
