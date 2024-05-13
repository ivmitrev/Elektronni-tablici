#pragma once
#include "Cell.h"
class IntCell : public Cell 
{
public:
    IntCell(const std::string& cellV);
    virtual int getValue() const;
private:
    int cellValue;

};