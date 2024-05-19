#include "DoubleCell.h"

DoubleCell::DoubleCell(const double cellV)
{
    this->cellValue = cellV;
}
void DoubleCell::print() const
{
    std::cout << cellValue;
}
   
int DoubleCell::getCellSize() const
{
    return std::to_string(this->cellValue).size();
}
 
// void DoubleCell::print(int cellWidth) const
// {
//     if(cellWidth < 0)
//     {
//         return;
//     }

//     if(this->getCellSize() <= cellWidth)
//     {
//         this->print();
//         for(int i=0;i<cellWidth-getCellSize();i++)
//         {
//             std::cout<<' ';
//         }
//     }
// } 
   
    