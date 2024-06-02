#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include "../Cell/Cell.h"
#include "../../Utility/CellUtility.h"

/**
 * @class Row
 * @brief Represents a row in a table.
 */
class Row 
{
private:
    std::vector<Cell*> cells;  /**< Vector containing pointers to the cells in the row. */
public:
    
    /**
     * @brief Default constructor for Row class.
     * 
     * Constructs a Row object with default initialization.
     */
    Row() = default;

    /**
     * @brief Destructor to clean up dynamically allocated memory.
     */
    ~Row();

    /**
     * @brief Copy constructor for deep copying.
     * 
     * @param other The row to be copied.
     */
    Row(const Row& other);

    /**
     * @brief Assignment operator for deep copying.
     * 
     * @param other The row to be assigned.
     * @return Reference to the assigned row.
     */
    Row& operator=(const Row& other);
    
    /**
     * @brief Adds a cell to the row.
     * 
     * @param cell Pointer to the cell to be added.
     */
    void addCell(Cell* cell);

    /**
     * @brief Prints the value of the cell at the specified index.
     * 
     * @param index The index of the cell to print.
     */
    void print(int index) const;

    /**
     * @brief Prints all cells in the row.
     */
    void printAll() const;

    /**
     * @brief Gets the number of cells in the row.
     * 
     * @return The number of cells in the row.
     */
    int getSize() const;

    /**
     * @brief Gets a copy of the vector containing pointers to the cells in the row.
     * 
     * @return A vector containing pointers to the cells in the row.
     */
    std::vector<Cell*> getCells() const;

    /**
     * @brief Edits the value of the cell at the specified column index.
     * 
     * @param colIndex The index of the column to edit.
     * @param value The new value for the cell.
     */
    void editCell(size_t colIndex, const std::string& value);
};