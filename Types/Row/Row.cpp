#include "Row.h"
    
Row::Row() 
{

}

Row::Row(const std::vector<Cell*> rowofcells)
{
    this->rowofcells = rowofcells;
}
Row::Row(const Row& other)
{
//    for(auto* cell : other.rowofcells)
//    {
//     rowofcells.push_back(new Ce)
//    }
}
Row& Row::operator=(const Row& other)
{

}
Row::~Row()
{

}
    
void Row::setCell(const std::string cellV,int col)
{
    // rowofcells[col] = cellV;
}

Cell* Row::createCell(const std::string cellValue) const
{

}

Cell* Row::getCell(int col) const
{
    return nullptr;
}
