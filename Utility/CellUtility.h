#pragma once
#include "Cell/Cell.h"
class CellUtility
{
public:
    bool isInt(const Cell* other);
    bool isDouble(const Cell* other);
    bool isString(const Cell* other);
    bool isFormula(const Cell* other);
private:
    
};