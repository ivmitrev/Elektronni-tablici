#include "CellUtility.h"
#include "../Types/Cell/IntCell.h"
#include "../Types/Cell/DoubleCell.h"
#include "../Types/Cell/StringCell.h"

bool CellUtility::isInt(const std::string& cellValue)
{     
    if(cellValue.empty())
    {
        return false;
    }
    std::size_t i = 0;
    if(cellValue[0] == '+' || cellValue[1] == '-')
    {
        ++i;
    }
    for(;i< cellValue.size();++i)
    {
        if(!isdigit(cellValue[i]))
        {
            return false;
        }
    }
    return true;
}
bool CellUtility::isDouble(const std::string& cellValue)
{
    if(cellValue.empty())
    {
        return false;
    }

    std::size_t i =0;
    if(cellValue[0] == '+' || cellValue[0] == '-')
    {
        ++i;
    }

    bool dotSeen = false;
    bool digitsSeenBeforeDot = false;

    for(; i < cellValue.size(); ++i)
    {
        char ch = cellValue[i];
        if(isdigit(ch))
        {
            if(!dotSeen)
            {
                digitsSeenBeforeDot = true;
            }
        }
        else if(ch == '.')
        {
            if(dotSeen || !digitsSeenBeforeDot || i == cellValue.size() - 1)
            {
                return false;
            }
            dotSeen = true;

        }
        else
        {
            return false;
        }
    }
    return digitsSeenBeforeDot && dotSeen;
}
bool CellUtility::isString(const std::string& cellValue)
{
    // dali raboti ili samo bog znae !
     
    if(cellValue.size() != 0 && cellValue[0] == '\"' && cellValue[cellValue.size()-1]== '\"')
    {
        return true;
    }
    return false;
}
bool CellUtility::isFormula(const std::string& other)
{
    return false;
}

Cell* CellUtility::createCellFromInput(const std::string& value)
{
    if(CellUtility::isInt(value))
    {
        return new IntCell(std::stoi(value));
    }
    else if(CellUtility::isDouble(value))
    {
        return new DoubleCell(std::stod(value));
    }
    else if(CellUtility::isString(value))
    {
        return new StringCell(value);
    }
    else if(CellUtility::isFormula(value))
    {
        return nullptr;
    }
    else return new StringCell(" ");
}
    
