#pragma once
#include "Cell.h"
/**
 * @class StringCell
 * @brief A class representing a cell containing a string value.
 */
class StringCell : public Cell 
{
public:
    /**
     * @brief Constructor to initialize the StringCell with a given string value.
     * 
     * @param cellV The string value of the cell.
     */
    StringCell(const std::string& cellV);

    /**
     * @brief Function to print the value of the StringCell.
     */
    void print() const override;

    /**
     * @brief Function to print the value of the StringCell with a specified width.
     * 
     * @param cellWidth The width of the cell to print.
     */
    void print(int cellWidth) const override;

    /**
     * @brief Function to get the size of the StringCell value.
     * 
     * @return The size of the StringCell value.
     */
    int getCellSize() const override;

    /**
     * @brief Formats the cell value by removing escape characters and surrounding quotes.
     * 
     * @param cellV The cell value to be formatted.
     * @return The formatted cell value.
     */
    std::string returnCellValueFormatted(const std::string& cellV) const;

     /**
     * @brief Function to get the string representation of the StringCell value.
     * 
     * @return The string representation of the StringCell value.
     */
    std::string getValueCellString() const override;
private:
    std::string cellValue; /**< The string value of the cell. */
};