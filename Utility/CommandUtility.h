#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<ostream>
// #include "../Types/Table/Table.h"
#include "../Types/Cell/Cell.h"
#include "../Types/Row/Row.h"
#include "../Types/Cell/IntCell.h"
#include "../Types/Cell/DoubleCell.h"
#include "../Types/Cell/StringCell.h"
#include "CellUtility.h"
#include "FileUtility.h"
/**
 * @class CommandUtility
 * @brief Provides utility functions for parsing and executing commands.
 * This class contains static methods for parsing user commands and executing
 * corresponding actions, such as opening, closing, saving, and editing files.
 * It also handles interactions with the table data structure.
 */
class CommandUtility 
{
public:

    /**
     * @brief Parses the command string and extracts the command keyword.
     * 
     * @param comm The command string to parse.
     * @return The extracted command keyword, or an empty string if parsing fails.
     */
    static std::string ParseCommand(const std::string& comm);

    /**
     * @brief Executes the command based on the parsed command keyword.
     * 
     * @param comm The command string to execute.
     * @param table Pointer to the table object.
     * @return A pointer to the modified table object, or nullptr if no modifications were made.
     */
    static Table* ExecuteCommand(const std::string& comm, Table* table);  
};