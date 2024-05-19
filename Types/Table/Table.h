#pragma once
#include "../Row/Row.h"

class Table
{
public:
    Table() = default;
    ~Table();

    void addRow(Row* row);
    void printAll() const;
    int getMaxRowWidth() const;

private:
    std::vector<Row*> rows;

};