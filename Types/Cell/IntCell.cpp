#include "IntCell.h"


IntCell::IntCell(const int cellV)
{
    this->cellValue = cellV;
    this->flagPlus = false;
}
IntCell::IntCell(const int cellV, bool flagPlus)
{
    this->cellValue = cellV;
    this->flagPlus= flagPlus;
}
void IntCell::print() const
{        
    std::cout << cellValue;
}

int IntCell::getCellSize() const
{
    if(this->flagPlus)
    {
        return strlen(std::to_string(this->cellValue).c_str())+1;
    }
    else
    {
        return strlen(std::to_string(this->cellValue).c_str());
    }
    
}

void IntCell::print(int cellWidth) const
{
    if(cellWidth < 0)
    {
        return;
    }

    if(this->getCellSize() <= cellWidth)
    {
        if(flagPlus)
        {
            std::cout<<"+";
            print();
        }
        else
        {
            print();
        }     
        for(int i=0;i<cellWidth-getCellSize();i++)
        {
            std::cout<<' ';
        }
    }
}     

std::string IntCell::getValueCellString() const
{
    if(flagPlus)
    {
        return "+" + std::to_string(this->cellValue);
    }
    return std::to_string(this->cellValue).c_str();
}
