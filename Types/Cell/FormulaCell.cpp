#include "FormulaCell.h"


FormulaCell::FormulaCell(const std::string& cellV)
{
    this->cellValue = cellV;
}
void FormulaCell::print() const
{        
    std::cout << cellValue;
}
int FormulaCell::getCellSize() const
{ 
    return strlen(this->cellValue.c_str()); 
}
void FormulaCell::setCellValueAnswer(const std::string& cellV)
{
    this->cellValueAnswer = cellV;
}
void FormulaCell::print(int cellWidth) const
{
    if(cellWidth < 0)
    {
        return;
    }

    if(this->getCellSize() <= cellWidth)
    {  
        this->print();     
        for(int i=0;i<cellWidth-getCellSize();i++)
        {
            std::cout<<' ';
        }
    }
}     