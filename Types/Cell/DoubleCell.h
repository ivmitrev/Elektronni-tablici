#pragma once
#include "Cell.h"
class DoubleCell : public Cell 
{
public:
    DoubleCell(const double cellV);
    void print() const override;
    int getCellSize() const override;

private:
    double cellValue;

};