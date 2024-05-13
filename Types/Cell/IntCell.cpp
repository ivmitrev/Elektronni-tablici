#include "IntCell.h"

IntCell::IntCell(const std::string& cellV) : Cell(cellV)
{
    this->cellValue = std::stoi(cellV);
}
int IntCell::getValue() const
{
    return this->cellValue;
}

   
    