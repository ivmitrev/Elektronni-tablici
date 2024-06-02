#pragma once
#include "../Types/Cell/Cell.h"
#include "../Types/Cell/FormulaCell.h"
#include "../Types/Cell/StringCell.h"
#include "../Types/Cell/IntCell.h"
#include "../Types/Cell/DoubleCell.h"
#include<regex>
/**
 * @class CellUtility
 * @brief Utility class for handling cell-related operations. 
 * This class provides static methods for various cell-related operations such as 
 * determining the type of cell value, checking for valid cell values, and creating 
 * cell objects from input values.
 */
class CellUtility
{
public:
    /**
     * @brief Check if the given string represents an integer.
     * 
     * @param cellValue The string to be checked.
     * @return true if the string represents an integer, false otherwise.
     */
    static bool isInt(const std::string& cellValue);

    /**
     * @brief Check if the given string represents a double.
     * 
     * @param cellValue The string to be checked.
     * @return true if the string represents a double, false otherwise.
     */
    static bool isDouble(const std::string& cellValue);

    /**
     * @brief Check if the given string represents a string enclosed in double quotes.
     * 
     * @param cellValue The string to be checked.
     * @return true if the string represents a string, false otherwise.
     */
    static bool isString(const std::string& cellValue);

    /**
     * @brief Check if the given string represents a formula.
     * 
     * @param cellValue The string to be checked.
     * @return true if the string represents a formula, false otherwise.
     */
    static bool isFormula(const std::string& cellValue);

    /**
     * @brief Create a cell object based on the given input value.
     * 
     * @param value The input value to create the cell from.
     * @return A pointer to the created Cell object.
     */
    static Cell* createCellFromInput(const std::string& value);

     /**
     * @brief Check if the given string represents a valid cell value.
     * 
     * @param cellValue The string to be checked.
     * @return true if the string represents a valid cell value, false otherwise.
     */
    static bool checkForValidCell(const std::string& cellValue);
};