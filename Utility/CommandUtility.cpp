#include "CommandUtility.h"

void CommandUtility::ParseCommand(const std::string& comm)
{
    std::vector<std::string> commArgs = splitStringBySpace(comm, ' ');
    if(commArgs.empty())
    {
        std::cout << "Command input must not be empty!" << std::endl;
    }
    else
    {  
        const std::string command = commArgs[0];
        if(command == "open")
        {      
            std::string filepath = commArgs[1];
            std::ifstream file(filepath);
            std::string filename = filepath.substr(filepath.find_last_of('\\')+1);
            if(!file.is_open())
            {
                std::ofstream outputfile(filepath);
                if(outputfile.is_open())
                {
                    std::cout << "Successfully opened " << filename << std::endl;
                    outputfile.close();
                }
                else
                {
                    std::cout << "Failed to open the file" << std::endl;
                    return;
                }

            }
            else
            {
                std::string line;
                while(std::getline(file,line))
                {
                    std::cout << line << std::endl;
                }
                file.close();
                std::cout << "Successfully opened " << filename << std::endl;
            }

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

    
std::vector<std::string> CommandUtility::splitStringBySpace(const std::string& input,const char delimiter) 
{
    std::vector<std::string> splitInput;
    size_t prevIndex = 0;

    if (input.find_first_not_of(" \t\n\r") == std::string::npos) {
        return splitInput;
    }

    for (size_t i = 0; i <= input.size(); i++) {
        if (i == input.size() || input[i] == delimiter) {
            std::string substring = input.substr(prevIndex, i - prevIndex);
            if (!substring.empty()) {
                splitInput.push_back(substring);
            }
            prevIndex = i + 1;
        }
    }

    return splitInput;
}