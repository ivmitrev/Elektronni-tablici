#include "Cell.h"


Cell::Cell(const std::string& value)
{
    this->cellValue = value;
}
Cell::~Cell()
{
    
}
int Cell::getLength() const
{
    return strlen(this->cellValue.c_str());
}

void Cell::setValue(const std::string newValue)
{
    this->cellValue = newValue;
}

std::string Cell::getValue() const
{
    return this->cellValue;
}