#include "Row.h" 
#include "../../Utility/CellUtility.h"

Row::~Row() 
{
    for(Cell* cell : cells)
    {
        delete cell;
    }
}

void Row::addCell(Cell* cell)
{
    cells.push_back(cell);
}

void Row::print(int index) const
{
    if(index < 0 || index >= cells.size())
    {
        // greshka hvurlqm
        return;
    }
    cells[index]->print();
}


void Row::printAll() const
{
    //std::cout << "Print all " << cells.size() << " cells\n";
    for(auto cell : cells)
    {
        cell->print();
        // std::cout << " | " ;
    } 

}

int Row::getSize() const
{
    return cells.size();
}

std::vector<Cell*> Row::getCells() const
{
    return this->cells;
}


// Row::Row(const std::vector<Cell*> rowofcells)
// {
//     this->rowofcells = rowofcells;
// }
// Row::Row(const Row& other)
// {
// //    for(auto* cell : other.rowofcells)
// //    {
// //     rowofcells.push_back(new Ce)
// //    }
// }
// Row& Row::operator=(const Row& other)
// {

// }

void Row::editCell(size_t colIndex, const std::string& value) 
{
    if (colIndex >= this->getCells().size() || colIndex < 0) 
    {
        std::cerr << "Error: Index out of range\n";
        return;
    }
    auto newCell = CellUtility::createCellFromInput(value);
    // da se opravi
    if(newCell->getValueCellString() == " ") 
    {
        std::cerr<<"Invalid value\n";
        delete newCell;
        return;
    }

    delete cells[colIndex];
    cells[colIndex] = newCell;
}