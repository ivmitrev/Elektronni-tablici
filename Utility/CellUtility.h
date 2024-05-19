#pragma once
#include "../Types/Cell/Cell.h"
class CellUtility
{
public:
    static bool isInt(const std::string& cellValue);
    static bool isDouble(const std::string& cellValue);
    static bool isString(const std::string& cellValue);
    static bool isFormula(const std::string& cellValue);
    static Cell* createCellFromInput(const std::string& value);
private:  
};