#pragma once
#include "Cell.h"
/**
 * @class DoubleCell
 * @brief A class representing a cell containing a double value.
 */
class DoubleCell : public Cell 
{
public:
    /**
     * @brief Constructor to initialize the DoubleCell with a given double value.
     * 
     * @param cellV The double value of the cell.
     */
    DoubleCell(const double cellV);

     /**
     * @brief Constructor to initialize the DoubleCell with a given double value and a flag indicating if it's positive.
     * 
     * @param cellV The double value of the cell.
     * @param flagPlus A flag indicating if the value is positive.
     */
    DoubleCell(const double cellV,bool flagPlus);

     /**
     * @brief Function to print the value of the DoubleCell.
     */
    void print() const override;

     /**
     * @brief Function to print the value of the DoubleCell with a specified width.
     * 
     * @param cellWidth The width of the cell to print.
     */
    void print(int cellWidth) const override;

    /**
     * @brief Function to get the size of the DoubleCell value.
     * 
     * @return The size of the DoubleCell value.
     */
    int getCellSize() const override;

     /**
     * @brief Function to convert a double value to its string representation with a specified precision.
     * 
     * @param value The double value to convert.
     * @param precision The number of decimal places to include.
     * @return The string representation of the double value.
     */
    std::string doubleToString(double value, int precision) const;

     /**
     * @brief Function to get the string representation of the DoubleCell value.
     * 
     * @return The string representation of the DoubleCell value.
     */
    std::string getValueCellString() const override;
private:
    double cellValue; /**< The double value of the cell. */
    bool flagPlus;  /**< Flag indicating if the value is positive. */
};