#pragma once
#include "Cell.h"
class StringCell : public Cell 
{
public:
    StringCell(const std::string& cellV);
    virtual std::string getValue() const;
private:
    std::string cellValue;

};