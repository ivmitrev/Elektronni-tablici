#include "Table.h"

Table::~Table()
{
    for(Row* row : rows)
    {
        delete row;
    }
}
void Table::addRow(Row* row)
{
    rows.push_back(row);
}

int Table::getMaxRowWidth() const
{
    int maxSize = -1;
    for(auto i : rows)
    {
        if(i->getSize() > maxSize)
        {
            maxSize = i->getSize();
        }
    }
    return maxSize;
}

void Table::printAll() const
{
    std::vector<int> colWidths;
    int currentColMaxWidth = 0;

    Row* firstRow = rows[0];
    for(int i=0;i<firstRow->getSize();i++)
    {
        for(auto row : rows)
        {
            int cellSize = row->getCells()[i]->getCellSize();
            if(currentColMaxWidth < cellSize)
            {
                currentColMaxWidth = cellSize;
            }
        }
        colWidths.push_back(currentColMaxWidth);
        currentColMaxWidth = 0;
    }

//todo izkarai v drug metod
    for(auto row : rows)
    {
        for(int i=0;i<row->getCells().size();i++)
        {
            row->getCells()[i]->print(colWidths[i]);
            std::cout << " | ";
        }

        std::cout<<std::endl;
    }
}