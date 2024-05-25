#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include<algorithm>
#include"../Types/Table/Table.h"
class FileUtility
{
public:
    static std::vector<std::string> splitBy(const std::string& input, const std::string& delimiter);
    static std::vector<std::string> readFromFile(const std::string& filePath);
    static std::string trim(const std::string& str);
    static bool saveFile(const Table* table,const std::string& filePath);
    static bool saveAsFile(const Table* table, const std::string& newFilePath);
};