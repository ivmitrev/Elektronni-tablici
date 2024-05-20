#pragma once
#include "Cell.h"
class DoubleCell : public Cell 
{
public:
    DoubleCell(const double cellV);
    DoubleCell(const double cellV,bool flagPlus);
    void print() const override;
    void print(int cellWidth) const override;
    virtual int getCellSize() const override;
    std::string doubleToString(double value, int precision) const;

private:
    double cellValue;
    bool flagPlus;
};