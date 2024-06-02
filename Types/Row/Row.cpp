#include "Row.h" 

Row::~Row() 
{
    for(Cell* cell : cells)
    {
        delete cell;
    }
}

Row::Row(const Row& other)
{
    cells.reserve(other.cells.size());
    for(const auto& cell : other.cells)
    {
        cells.push_back(CellUtility::createCellFromInput(cell->getValueCellString()));
    }
}

Row& Row::operator=(const Row& other)
{
    if(this != &other)
    {
        for(Cell* cell : cells)
        {
            delete cell;
        }
        cells.clear();

        cells.reserve(other.cells.size());
        for(const auto& cell : other.cells)
        {
            cells.push_back(CellUtility::createCellFromInput(cell->getValueCellString()));
        }
    }

    return *this;
}

void Row::addCell(Cell* cell)
{
    cells.push_back(cell);
}

void Row::print(int index) const
{
    if(index < 0 || index >= cells.size())
    {
        std::cout << "Index out of range." << std::endl;
    }
    else
    {
        cells[index]->print();
    }
}


void Row::printAll() const
{
    for(auto cell : cells)
    {
        cell->print();
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

void Row::editCell(size_t colIndex, const std::string& value) 
{
    if (colIndex >= this->getCells().size() || colIndex < 0) 
    {
        std::cout << "Error: Index out of range" << std::endl;
    }
    else
    {
        auto newCell = CellUtility::createCellFromInput(value);
        delete cells[colIndex];
        cells[colIndex] = newCell;
        std::cout<<"Edited" << std::endl;
    }
}