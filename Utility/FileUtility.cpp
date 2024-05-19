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

    return splitInput;
}

std::vector<std::string> FileUtility::readFromFile(const std::string& filePath)
{
    std::ifstream file(filePath); 
    if(!file.is_open())
    {
        std::ofstream createFile(filePath);
        createFile.close();

        file.open(filePath);
        if(!file.is_open())
        {
            std::cout << "Failed to open the file." << std::endl;
        }
    }
    std::string line;
    std::vector<std::string> lines;
    while(std::getline(file, line))
    {
        lines.push_back(line);
    }
    file.close();
    std::string filename = filePath.substr(filePath.find_last_of('\\')+1);
    std::cout << "Successfully opened " << filename << std::endl;
    return lines;
}