#include "FileUtility.h"

std::vector<std::string> FileUtility::splitBy(const std::string &input, const std::string &delimiter)
{
    std::vector<std::string> splitInput;
    size_t prevIndex = 0;
    size_t delimiterLength = delimiter.length();

    if (input.find_first_not_of(" \t\n\r") == std::string::npos)
    {
        return splitInput;
    }

    size_t currentIndex = input.find(delimiter, prevIndex);
    while (currentIndex != std::string::npos)
    {
        std::string substring = input.substr(prevIndex, currentIndex - prevIndex);
        splitInput.push_back(substring);
        prevIndex = currentIndex + delimiterLength;
        currentIndex = input.find(delimiter, prevIndex);
    }

    std::string lastSubstring = input.substr(prevIndex);
    splitInput.push_back(lastSubstring);
    // zashtoto nqkou put slaga elementa i sled tova zapetaika
    if(splitInput.back().back() == ',')
    {
        splitInput.back() =  splitInput.back().substr(0, splitInput.back().size()-1);
        splitInput.push_back(" ");
    }
   
    return splitInput;
}

std::string FileUtility::trim(const std::string& str) 
{
    if (str.empty()) 
    {
        return str;
    }
    auto start = str.find_first_not_of(" \t");
    auto end = str.find_last_not_of(" \t");
    return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
}

std::vector<std::string> FileUtility::readFromFile(const std::string& filePath)
{
    std::ifstream file(filePath); 
    std::string filename = filePath.substr(filePath.find_last_of('\\')+1);
    if(!file.is_open())
    {
        std::ofstream outputfile(filePath);
        if(outputfile.is_open())
        {
            std::cout << "Successfully opened " << filename << std::endl;
            outputfile.close();
            return {{}};

        }
        else
        {
            std::cout << "Failed to open the file" << std::endl;
        }

    }
    else
    {   
        std::cout << "Successfully opened " << filename << std::endl;
        std::string line;
        std::vector<std::string> lines;
        while(std::getline(file, line))
        {
            lines.push_back(line);
        }
        file.close();
        return lines;
    }
}

bool FileUtility::saveFile(const Table* table,const std::string& filePath)
{
    std::ofstream outputFile(filePath, std::ios::trunc);
    if(!outputFile.is_open())
    {
        std::cout << "Failed to open the file" << std::endl;
        return false;
    }

    for(auto row : table->getRows())
    {
       int index = 0;
       for(auto cell : row->getCells())
       {
            outputFile << cell->getValueCellString();
            if(index != row->getCells().size()-1)
            {
                outputFile << ", ";
            }
            index+=1;
       }
       outputFile << std::endl;
    }
    outputFile.close();
    return true;
}


bool FileUtility::saveAsFile(const Table* table, const std::string& newFilePath)
{
    std::ifstream file(newFilePath);
    if(file.good())
    {
        std::cout << newFilePath << " already exists" << std::endl;
        return false; 
    }
    file.close();
    saveFile(table,newFilePath);
    return true;
}