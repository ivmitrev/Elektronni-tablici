#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include<algorithm>
#include"../Types/Table/Table.h"

/**
 * @class FileUtility
 * @brief Provides utility functions for file operations.
 * 
 * This class contains static methods for performing various file-related operations,
 * such as splitting strings by delimiter, trimming whitespaces, reading from files,
 * and saving data to files.
 */
class FileUtility
{
public:
    /**
     * @brief Splits a string into substrings using the specified delimiter.
     * 
     * @param input The input string to be split.
     * @param delimiter The delimiter used to split the input string.
     * @return A vector containing the substrings after splitting.
     */
    static std::vector<std::string> splitBy(const std::string& input, const std::string& delimiter);

    /**
     * @brief Reads lines from a file and returns them as a vector of strings.
     * 
     * @param filePath The path to the file to be read.
     * @return A vector containing the lines read from the file.
     */
    static std::vector<std::string> readFromFile(const std::string& filePath);

    /**
     * @brief Removes leading and trailing whitespaces from a string.
     * 
     * @param str The input string to be trimmed.
     * @return The trimmed string.
     */
    static std::string trim(const std::string& str);

    /**
     * @brief Saves the content of a table to a file.
     * 
     * @param table Pointer to the table object to be saved.
     * @param filePath The path to the file where the table will be saved.
     * @return true if the file was successfully saved, false otherwise.
     */
    static bool saveFile(const Table* table,const std::string& filePath);

    /**
     * @brief Saves the content of a table to a new file.
     * 
     * @param table Pointer to the table object to be saved.
     * @param newFilePath The path to the new file where the table will be saved.
     * @return true if the file was successfully saved, false otherwise.
     */
    static bool saveAsFile(const Table* table, const std::string& newFilePath);
};