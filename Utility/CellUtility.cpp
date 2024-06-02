#include "CellUtility.h"


bool CellUtility::isInt(const std::string& cellValue)
{     
    if(cellValue.empty())
    {
        return false;
    }
    std::size_t i = 0;
    if(cellValue[0] == '+' || cellValue[0] == '-')
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
    if (cellValue.size() < 2 || cellValue.front() != '"' || cellValue.back() != '"') 
    {
        return false;
    }

    for (size_t i = 1; i < cellValue.size() - 1; ++i) 
    {
        if (cellValue[i] == '"') 
        {
            if (cellValue[i - 1] != '\\') 
            {
                return false;
            }
        }
        else if (cellValue[i] == '\\') 
        {
            
            if (i + 1 >= cellValue.size() - 1 || (cellValue[i + 1] != '"' && cellValue[i + 1] != '\\')) 
            {
                return false;
            }
            ++i; 
        }
    }
    return true;
}
bool CellUtility::isFormula(const std::string& cellValue)
{
    std::string patternRc = R"(^=\s((R[1-9][0-9]*C[1-9][0-9]*)|([+-]?\d+(\.\d+)?))\s[\*\^\/\+\-]\s((R[1-9][0-9]*C[1-9][0-9]*)|([+-]?\d+(\.\d+)?))$)";
    std::string patternNumbers = R"(^=\s[+-]?\d+(\.\d+)?\s[\*\^\+\-\/]\s[+-]?\d+(\.\d+)?$)";
    std::regex regexRc(patternRc);    
    std::regex regexNumbers(patternNumbers);
    if(!std::regex_match(cellValue, regexRc) && !std::regex_match(cellValue, regexNumbers))
    {
        return false;
    }
    return true;
}
bool CellUtility::checkForValidCell(const std::string& cellValue)
{
    if(CellUtility::isDouble(cellValue) || CellUtility::isInt(cellValue) || CellUtility::isFormula(cellValue) || CellUtility::isString(cellValue))
    {
        return true;
    }
    else
    {
        return false;
    }
}
Cell* CellUtility::createCellFromInput(const std::string& value)
{
    if(CellUtility::isInt(value))
    {   
        if(value[0] == '+')
        {
            return new IntCell(std::stoi(value), true);
        }
        else
        {
            return new IntCell(std::stoi(value));
        }  
    }
    else if(CellUtility::isDouble(value))
    {
        if(value[0] == '+')
        {
            return new DoubleCell(std::stod(value),true);
        }
        else
        {
            return new DoubleCell(std::stod(value));
        }
    }
    else if(CellUtility::isString(value))
    {
        return new StringCell(value);
    }
    else if(CellUtility::isFormula(value))
    {
        return new FormulaCell(value);
    }
    else if(value == " " || value == "")
    {
        return new StringCell(" ");
    }
    else
    { 
        return nullptr;
    }

}
    
