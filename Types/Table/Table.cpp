#include "Table.h"
#include "../../Utility/CellUtility.h"
#include "../Cell/FormulaCell.h"
Table::~Table()
{
    for(Row* row : rows)
    {
        delete row;
    }
}
void Table::addRow(Row* row)
{
    rows.push_back(row);
}
std::string Table::getValueFromRowColumn(const int rowIndex,const int colIndex) const
{   
    int rowIndexinFor=1,colIndexinFor=1;
    for(auto row : rows)
    {
       
        for(auto cell : row->getCells())
        {
            if(rowIndexinFor == rowIndex && colIndexinFor == colIndex)
            {
                return cell->getValueCellString();
            }
            colIndexinFor+=1;
        }
        colIndexinFor=0;
        rowIndexinFor+=1;
    }  
}

double Table::pow(const double& num, const int& exp) const
{
    double result = 1;
    if(exp == 0)
    {
        return 1;
    }
    for(int i =0; i < exp;i++)
    {
        result*=num;
    }
    return result;
}
void Table::calculatingFormulas() const 
{
    for(auto row : rows)
    {
        for(auto cell : row->getCells())
        {
            if(CellUtility::isFormula(cell->getValueCellString()))
            {
                
                int secondWhiteSpaceIndex = cell->getValueCellString().find_first_of(" \t\n\r\f\v",2);
                int thirdWhiteSpaceIndex = cell->getValueCellString().find_first_of(" \t\n\r\f\v",secondWhiteSpaceIndex+1);
                std::string firstValue = cell->getValueCellString().substr(2,secondWhiteSpaceIndex-2);
                std::string secondValue = cell->getValueCellString().substr(thirdWhiteSpaceIndex+1,cell->getCellSize()-secondWhiteSpaceIndex);
                std::string operation = cell->getValueCellString().substr(secondWhiteSpaceIndex+1,1);
                // if(firstValue.front() == 'R')
                // {
                //     std::cout << firstValue[1] << std::endl;
                //     int rowIndex = firstValue[1] - '0';
                //     int colIndex = firstValue[3] - '0';
                //     std::cout << rowIndex << " " << colIndex << std::endl;
                //     firstValue = getValueFromRowColumn(rowIndex,colIndex);
                // }
                // if(secondValue.front() == 'R')
                // {
                //     int rowIndex = secondValue[1] - '0';
                //     int colIndex = secondValue[3] - '0';
                //     secondValue = getValueFromRowColumn(rowIndex,colIndex);
                // }
                
                double firstValueDouble,secondValueDouble;
                if(isValidNumber(firstValue) && isValidNumber(secondValue))
                {
                    firstValueDouble = std::stod(firstValue);
                    secondValueDouble = std::stod(secondValue);
                }
                else if(!isValidNumber(firstValue) && isValidNumber(secondValue))
                {
                    firstValueDouble = 0;
                    secondValueDouble = std::stod(secondValue);
                }
                else if(isValidNumber(firstValue) && !isValidNumber(secondValue))
                {
                    firstValueDouble = std::stod(firstValue); 
                    secondValueDouble = 0;      
                }
                else 
                {
                    firstValueDouble = 0;
                    secondValueDouble = 0;
                }
                double result = 0;
                std::string resultString;
               
                if(operation == "+") {result = firstValueDouble + secondValueDouble;}
                else if(operation == "-") {result = firstValueDouble - secondValueDouble;}
                else if(operation == "*") {result = firstValueDouble * secondValueDouble;}
                else if(operation == "^") {result = pow(firstValueDouble,secondValueDouble);}
                else if(operation == "/") 
                {
                    if(secondValueDouble == 0) { resultString = "ERROR";}
                    else {result = firstValueDouble / secondValueDouble;}        
                }
                
                if(resultString != "ERROR") {resultString = std::to_string(result);}
                if(FormulaCell* formulaCell = dynamic_cast<FormulaCell*>(cell))
                {
                    formulaCell->setValueCellAnswerString(resultString);
                    
                }

                
            }
        }
    }
    
}
int Table::getMaxRowWidth() const
{
    int maxSize = -1;
    for(auto i : rows)
    {
        if(i->getSize() > maxSize)
        {
            maxSize = i->getSize();
        }
    }
    return maxSize;
}

void Table::printAll() const
{
    std::vector<int> colWidths;
    int currentColMaxWidth = 0;

    Row* firstRow = rows[0];
    for(int i=0;i<firstRow->getSize();i++)
    {
        for(auto row : rows)
        {
            int cellSize = row->getCells()[i]->getCellSize();
            if(currentColMaxWidth < cellSize)
            {
                currentColMaxWidth = cellSize;
            }
        }
        colWidths.push_back(currentColMaxWidth);
        currentColMaxWidth = 0;
    }

//todo izkarai v drug metod
    for(auto row : rows)
    {
        for(int i=0;i<row->getCells().size();i++)
        {
            row->getCells()[i]->print(colWidths[i]);
            std::cout << " | ";
        }

        std::cout<<std::endl;
    }
}

bool Table::isValidNumber(const std::string& str) const
{
    try 
    {
        size_t pos;
        std::stod(str, &pos); 
        return pos == str.size(); 
    } 
    catch (const std::invalid_argument&) 
    {
        return false; 
    }
    catch (const std::out_of_range&)
    {
        return false; 
    }
}