#pragma once
#include<iostream>
#include<sstream>
#include<iomanip>
#include<cstring>
/**
 * @class Cell
 * @brief The base class representing a cell in a table
*/
class Cell 
{
public:
   /**
 * @brief Virtual function to print the value of the cell.
*/
   virtual void print() const = 0;

    /**
     * @brief Virtual function to print the value of the cell with a specified width.
     * 
     * @param cellWidth The width of the cell to print.
     */
   virtual void print(int cellWidth) const = 0;

    /**
     * @brief Virtual function to get the size of the cell value.
     * 
     * @return The size of the cell value.
     */
   virtual int getCellSize() const = 0;

   /**
     * @brief Virtual function to get the string representation of the cell value.
     * 
     * @return The string representation of the cell value.
     */
   virtual std::string getValueCellString() const = 0;
   
    /**
     * @brief Virtual destructor for proper memory management.
     */
   virtual ~Cell() = default;
};
