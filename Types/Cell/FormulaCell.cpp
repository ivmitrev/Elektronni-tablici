#include "FormulaCell.h"


FormulaCell::FormulaCell(const std::string& cellV)
{
    this->cellValue = cellV;
    this->cellValueAnswer = "";
}
void FormulaCell::print() const
{        
    std::cout << this->cellValueAnswer;
}
std::string FormulaCell::doubleToString(double value, int precision)  const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(precision) << value;
    std::string str = oss.str();

    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
   
    if (str.back() == '.') 
    {
        str.pop_back();
    }

    return str; 
} 
int FormulaCell::getCellSize() const
{ 
    return strlen(this->cellValueAnswer.c_str());
}
std::string FormulaCell::getValueCellString() const 
{
    return this->cellValue;
}
std::string FormulaCell::getValueCellAnswerString() const
{
    return this->cellValueAnswer;
}
void FormulaCell::setValueCellAnswerString(std::string value) 
{
    if(this->cellValueAnswer == "")
    {
        this->cellValueAnswer = value;
        if(value != "ERROR")
        {
            double number = std::stod(this->cellValueAnswer);
            this->cellValueAnswer = doubleToString(number,3);
        }
    }
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