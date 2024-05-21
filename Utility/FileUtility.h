#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include<algorithm>
class FileUtility
{
public:
    static std::vector<std::string> splitBy(const std::string& input, const std::string& delimiter);
    static std::vector<std::string> readFromFile(const std::string& filePath);
    static std::string trim(const std::string& str);
};