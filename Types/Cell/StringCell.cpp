#include "StringCell.h"

StringCell::StringCell(const std::string& cellV)
{
    this->cellValue = cellV;
}
void StringCell::print() const
{
    // printvam bes escape znacite i bez kavichkite v nachaloto i kraq
    std::cout << returnCellValueFormatted(this->cellValue).c_str();
}
std::string StringCell::returnCellValueFormatted(const std::string& cellV) const
{
    std::string formatted;
    // formatiram bes escape znacite i bez kavichkite v nachaloto i kraq
    bool escaped = false;
    for(int i = 1; i < this->cellValue.size()-1;i++)
    {
        if(escaped)
        {
            formatted += this->cellValue[i];
            escaped = false;
        }
        else if(this->cellValue[i] == '\\')
        {
            escaped = true;
        }
        else
        {
            formatted += this->cellValue[i];
        }

    }
    return formatted;
}


int StringCell::getCellSize() const
{
    return strlen(returnCellValueFormatted(this->cellValue).c_str());
}


void StringCell::print(int cellWidth) const
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

std::string StringCell::getValueCellString() const
{
    return this->cellValue;
    
}