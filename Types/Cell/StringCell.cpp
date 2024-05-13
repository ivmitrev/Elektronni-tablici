#include "StringCell.h"

StringCell::StringCell(const std::string& cellV) : Cell(cellV)
{
    this->cellValue = cellV;
}
std::string StringCell::getValue() const
{
    return this->cellValue;
}

   
    