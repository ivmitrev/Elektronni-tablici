#pragma once
#include "Cell.h"
#include <cstring>
/**
 * @class FormulaCell
 * @brief A class representing a cell containing a formula.
 */
class FormulaCell : public Cell 
{
public:
    /**
     * @brief Constructor to initialize the FormulaCell with a given formula string.
     * 
     * @param cellV The formula string of the cell.
     */
    FormulaCell(const std::string& cellV);

    /**
     * @brief Constructor to initialize the FormulaCell with a given formula string.
     * 
     * @param cellV The formula string of the cell.
     */
    void print() const override;

    /**
     * @brief Function to print the value of the FormulaCell with a specified width.
     * 
     * @param cellWidth The width of the cell to print.
     */
    void print(int cellWidth) const override;

    /**
     * @brief Function to get the size of the FormulaCell value.
     * 
     * @return The size of the FormulaCell value.
     */
    int getCellSize() const override;

    /**
     * @brief Function to set the computed answer of the FormulaCell.
     * 
     * @param value The string representation of the computed answer.
     */
    void setValueCellAnswerString(std::string value);

      /**
     * @brief Function to get the string representation of the FormulaCell value.
     * 
     * @return The string representation of the FormulaCell value.
     */
    std::string getValueCellString() const override final;

     /**
     * @brief Function to convert a double value to its string representation with a specified precision.
     * 
     * @param value The double value to convert.
     * @param precision The number of decimal places to include.
     * @return The string representation of the double value.
     */
    std::string doubleToString(double value, int precision)  const;

    /**
     * @brief Function to get the string representation of the FormulaCell value.
     * 
     * @return The string representation of the FormulaCell value.
     */
    std::string getValueCellAnswerString() const;
private:
    std::string cellValue;  /**< The formula string of the cell. */
    std::string cellValueAnswer;  /**< The computed answer of the formula cell. */
};