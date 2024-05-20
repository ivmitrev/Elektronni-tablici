#include "DoubleCell.h"

DoubleCell::DoubleCell(const double cellV)
{
    this->cellValue = cellV;
    this->flagPlus = false;
}
DoubleCell::DoubleCell(const double cellV,bool flagPlus)
{
    this->cellValue = cellV;
    this->flagPlus = flagPlus;
}
void DoubleCell::print() const
{
    std::cout << doubleToString(this->cellValue, 3);
}

std::string DoubleCell::doubleToString(double value, int precision)  const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    std::string str = oss.str();

    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
   
    if (str.back() == '.') {
        str.pop_back();
    }

    return str; 
} 

int DoubleCell::getCellSize() const
{
    if(this->flagPlus)
    {
        return doubleToString(this->cellValue, 3).size()+1;
    }
    else
    {
        return doubleToString(this->cellValue, 3).size();
    }
}
 
void DoubleCell::print(int cellWidth) const
{
    if(cellWidth < 0)
    {
        return;
    }

    if(this->getCellSize() <= cellWidth)
    {
        if(flagPlus)
        {
            std::cout<<"+"<<doubleToString(this->cellValue, 3);
        }
        else
        {
            std::cout<<doubleToString(this->cellValue, 3);
        }    
        
        for(int i=0;i<cellWidth-getCellSize();i++)
        {
            std::cout<<' ';
        }
    }
} 
   
    