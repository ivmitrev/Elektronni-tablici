#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<ostream>
class CommandUtility 
{
public:
    static void ParseCommand(const std::string& comm);
    static bool ValidateCommand(const std::string& comm, const std::string& arg);
    static void ExecuteCommand(const std::string& comm, const std::string& arg);

private:
    static std::vector<std::string> splitStringBySpace(const std::string& s, const std::string& delimeter);
};