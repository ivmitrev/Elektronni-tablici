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
    if(cellValue.size() < 2 || cellValue.front() != '"' || cellValue.back() != '"')
    {
        return false;
    }

    for(int i = 1; i < cellValue.size()-1;i++)
    {
        if(cellValue[i] == '"' || cellValue[i] == '\\')
        {
            if(cellValue[i-1] != '\\')
            {
                return false;
            }
        }

        if(cellValue[i] == '\\')
        {
            if(i+1 >= cellValue.size() - 1 || (cellValue[i+1] != '"' && cellValue[i+1] != '\\'))
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
    std::string pattern = R"("^=\sR[1-9][0-9]*C[1-9][0-9]*\s[\*\^\/\+\-]\sR[1-9][0-9]*C[1-9][0-9]*$")";
    std::regex regex(pattern);    
     
       
  
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
        return nullptr;
    }
    else return new StringCell(" ");
}
    
