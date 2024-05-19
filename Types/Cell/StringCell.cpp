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
    return strlen(this->cellValue.c_str());
}


void StringCell::print(int cellWidth) const
{
    if(cellWidth < 0)
    {
        return;
    }

    if(this->getCellSize() <= cellWidth)
    {
        std::cout<<this->cellValue;
        for(int i=0;i<cellWidth-getCellSize();i++)
        {
            std::cout<<' ';
        }
    }
} 