#pragma once
#include "Cell.h"
class FormulaCell : public Cell 
{
public:
    FormulaCell(const std::string& cellV);
    void print() const override;
    void print(int cellWidth) const override;
    int getCellSize() const override;
    void setCellValueAnswer(const std::string& cellV);
private:
    std::string cellValue;
    std::string cellValueAnswer;
};