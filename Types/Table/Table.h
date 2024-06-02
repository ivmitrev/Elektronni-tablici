#pragma once
#include "../Row/Row.h"
#include "../../Utility/CellUtility.h"
#include "../Cell/FormulaCell.h"
#include <cmath>

/**
 * @class Table
 * @brief Represents a Table.
 */
class Table
{
public:
    /**
    * @brief Default constructor for the Table class.
    */
    Table() = default;

    /**
     * @brief Destructor for the Table class.
     * 
     * Deallocates memory for all rows in the table.
     */
    ~Table();

    /**
     * @brief Copy constructor for the Table class.
     * 
     * Creates a new table as a copy of another table.
     * 
     * @param other The table to be copied.
     */
    Table(const Table& other);

    /**
     * @brief Assignment operator for the Table class.
     * 
     * Assigns the contents of another table to this table.
     * 
     * @param other The table to be assigned.
     * @return Reference to the modified table.
     */
    Table& operator=(const Table& other);

    /**
     * @brief Adds a row to the table.
     * 
     * @param row Pointer to the row to be added.
     */
    void addRow(Row* row);

    /**
     * @brief Prints the entire table.
     * 
     * This method prints all cells in the table, aligning them in columns with appropriate widths.
     */
    void printAll() const;

    /**
     * @brief Calculates all formulas in the table.
     * 
     * This method calculates all formulas in the table, including those with and without references to other cells.
     */
    void calculatingFormulas() const;

    /**
     * @brief Edits the value of a specific cell in the table.
     * 
     * @param rowIndex The index of the row containing the cell to be edited.
     * @param colIndex The index of the column containing the cell to be edited.
     * @param newCellValue The new value to be assigned to the cell.
     */
    void edit(const int& rowIndex,const int& colIndex, const std::string& newCellValue);

    /**
     * @brief Retrieves all rows in the table.
     * 
     * @return A vector containing pointers to all rows in the table.
     */
    std::vector<Row*> getRows() const;
 
private:
    std::vector<Row*> rows; /**< Vector containing pointers to the rows in the Table. */

    /**
     * @brief Retrieves the value from a specific cell in the table.
     * 
     * @param row The index of the row.
     * @param column The index of the column.
     * @return The value stored in the specified cell.
     */
    std::string getValueFromRowColumn(const int row, const int column) const;

    /**
     * @brief Checks if a string represents a valid number.
     * 
     * @param str The string to be checked.
     * @return True if the string represents a valid number, false otherwise.
     */
    bool isValidNumber(const std::string& str) const;

    /**
     * @brief Calculates the power of a number.
     * 
     * @param num The base number.
     * @param exp The exponent.
     * @return The result of raising the base to the exponent.
     */
    double pow(const double& num, const int& exp) const;

    /**
     * @brief Calculates formulas in cells where references to other cells are allowed.
     * 
     * This method calculates formulas only for cells that reference other cells in the form "RxCy".
     */
    void calculatingFormulasOnlyRc() const;

    /**
     * @brief Calculates formulas in cells where references to other cells are not allowed.
     * 
     * This method calculates formulas for cells without references to other cells.
     */
    void calculatingFormulasNotRc() const;
};