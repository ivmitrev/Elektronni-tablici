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
    static std::string ParseCommand(const std::string& comm);
    static Table* ExecuteCommand(const std::string& comm, Table* table);
};