#include "CellUtility.h"


bool CellUtility::isInt(const Cell* other)
{
    if(other == nullptr)
    {
        return false;
    }
    std::string cellValue = other->getValue();
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
bool CellUtility::isDouble(const Cell* other)
{
    if(other == nullptr)
    {
        return false;
    }
    std::string cellValue = other->getValue();
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
bool CellUtility::isString(const Cell* other)
{
    // dali raboti ili samo bog znae !
     
    if(other->getLength() != 0 && other->getValue()[0] == '\"' && other->getValue()[other->getLength()-1] == '\"')
    {
        return true;
    }
    return false;
}
bool CellUtility::isFormula(const Cell* other)
{
    return false;
}

    
