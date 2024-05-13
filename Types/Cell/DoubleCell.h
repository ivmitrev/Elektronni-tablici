#pragma once
#include "Cell.h"
class DoubleCell : public Cell 
{
public:
    DoubleCell(const std::string& cellV);
    virtual double getValue() const;
private:
    double cellValue;

};