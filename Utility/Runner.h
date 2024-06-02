#pragma once
#include<iostream>
#include<string>
#include "CommandUtility.cpp"
#include "FileUtility.cpp"
#include "CellUtility.cpp"
#include "../Types/Table/Table.cpp"
#include "../Types/Row/Row.cpp"
#include "../Types/Cell/IntCell.cpp"
#include "../Types/Cell/DoubleCell.cpp"
#include "../Types/Cell/StringCell.cpp"
#include "../Types/Cell/FormulaCell.cpp"

 /**
 * @class Runner
 * @brief Provides functionality to run the command line interface for interacting with tables.
 */
class Runner
{
public:
    /**
     * @brief Runs the command line interface for interacting with tables.
     * 
     * This method continuously prompts the user for commands and executes them.
     * It utilizes the CommandUtility class to parse and execute commands, updating the table accordingly.
     * The loop continues indefinitely until the program is terminated with exit command.
     */
    void run();
private:
    Table* table = nullptr; /**< Pointer to the current table being operated on. */
};