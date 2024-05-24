#pragma once
#include "Cell.h"
class FormulaCell : public Cell 
{
public:
    FormulaCell(const std::string& cellV);
    void print() const override;
    void print(int cellWidth) const override;
    int getCellSize() const override;
    void setValueCellAnswerString(std::string value);
    std::string getValueCellString() const override final;
    std::string doubleToString(double value, int precision)  const;
    std::string getValueCellAnswerString() const;
private:
    std::string cellValue;
    std::string cellValueAnswer;
};