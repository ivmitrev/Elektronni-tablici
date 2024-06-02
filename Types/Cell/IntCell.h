#pragma once
#include "Cell.h"

/**
 * @class IntCell
 * @brief A class representing a cell containing an integer value.
 */
class IntCell : public Cell 
{
public:
     /**
     * @brief Constructor to initialize the IntCell with a given integer value.
     * 
     * @param cellV The integer value of the cell.
     */
    IntCell(const int cellV);

     /**
     * @brief Constructor to initialize the IntCell with a given integer value and a flag indicating if it's positive.
     * 
     * @param cellV The integer value of the cell.
     * @param flagPlus A flag indicating if the integer value is positive.
     */
    IntCell(const int cellV, bool flagPlus);

     /**
     * @brief Function to print the value of the IntCell.
     */
    void print() const override;

    /**
     * @brief Function to print the value of the IntCell with a specified width.
     * 
     * @param cellWidth The width of the cell to print.
     */
    void print(int cellWidth) const override;

    /**
     * @brief Function to get the size of the IntCell value.
     * 
     * @return The size of the IntCell value.
     */
    int getCellSize() const override;

    /**
     * @brief Function to get the string representation of the IntCell value.
     * 
     * @return The string representation of the IntCell value.
     */
    std::string getValueCellString() const override;
private:
    int cellValue; /**< The integer value of the cell. */
    bool flagPlus; /**< Flag indicating if the integer value is positive. */
};