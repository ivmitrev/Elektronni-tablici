#pragma once
#include "Cell.h"
class IntCell : public Cell 
{
public:
    IntCell(const int cellV);
    IntCell(const int cellV, bool flagPlus);
    void print() const override;
    void print(int cellWidth) const override;
    int getCellSize() const override;
    std::string getValueCellString() const override;
private:
    int cellValue;
    bool flagPlus;
};