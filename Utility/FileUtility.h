#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
class FileUtility
{
public:
    static std::vector<std::string> splitBy(const std::string& input, const std::string& delimiter);
    static std::vector<std::string> readFromFile(const std::string& filePath);
};