#include "StringCell.h"

StringCell::StringCell(const std::string& cellV)
{
    this->cellValue = cellV;
}
void StringCell::print() const
{
    std::cout << cellValue;
}

int StringCell::getCellSize() const
{
    return this->cellValue.size();
}
