#include "DoubleCell.h"

DoubleCell::DoubleCell(const std::string& cellV) : Cell(cellV)
{
    this->cellValue = std::stod(cellV);
}
double DoubleCell::getValue() const
{
    return this->cellValue;
}

   
    