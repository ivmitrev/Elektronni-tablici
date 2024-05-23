#pragma once
#include "Cell.h"
class StringCell : public Cell 
{
public:
    StringCell(const std::string& cellV);
    void print() const override;
    void print(int cellWidth) const override;
    int getCellSize() const override;
    std::string returnCellValueFormatted(const std::string& cellV) const;
    std::string getValueCellString() const override;
  
private:
    std::string cellValue;
};