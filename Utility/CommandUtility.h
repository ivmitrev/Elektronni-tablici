#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<ostream>
#include "../Types/Table/Table.h"
class CommandUtility 
{
public:
    static Table* ParseCommand(const std::string& comm, Table* table);
    static bool ValidateCommand(const std::string& comm, const std::string& arg);
    static void ExecuteCommand(const std::string& comm, const std::string& arg);
};