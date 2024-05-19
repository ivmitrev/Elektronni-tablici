#include "IntCell.h"


IntCell::IntCell(const int cellV)
{
    this->cellValue = cellV;
}
void IntCell::print() const
{
    std::cout << cellValue;
}

int IntCell::getCellSize() const
{
    return std::to_string(this->cellValue).size();
}

    