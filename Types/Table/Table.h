#pragma once
#include "../Row/Row.h"
#include <cmath>
class Table
{
public:
    Table() = default;
    ~Table();

    void addRow(Row* row);
    void printAll() const;
    int getMaxRowWidth() const;
    void calculatingFormulas() const;
    
private:
    std::vector<Row*> rows;
    std::string getValueFromRowColumn(const int row, const int column) const;
    bool isValidNumber(const std::string& str) const;
    double pow(const double& num, const int& exp) const;
};