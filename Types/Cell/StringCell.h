#pragma once
#include "Cell.h"
class StringCell : public Cell 
{
public:
    StringCell(const std::string& cellV);
    void print() const override;
    int getCellSize() const override;
private:
    std::string cellValue;

};