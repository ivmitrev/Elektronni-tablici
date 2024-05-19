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
    return strlen(std::to_string(this->cellValue).c_str());
}

void IntCell::print(int cellWidth) const
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