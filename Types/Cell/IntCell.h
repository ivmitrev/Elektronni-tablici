#pragma once
#include "Cell.h"
class IntCell : public Cell 
{
public:
    IntCell(const int cellV);
    void print() const override;
    void print(int cellWidth) const override;
    int getCellSize() const override;
private:
    int cellValue;

};