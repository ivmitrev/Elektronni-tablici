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
std::vector<Row*> Table::getRows() const
{
    return rows;
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
                if(FormulaCell* formulaCell = dynamic_cast<FormulaCell*>(cell))
                {
                    return formulaCell->getValueCellAnswerString();  
                }
                else
                {   
                    return cell->getValueCellString();
                }
            }
            colIndexinFor+=1;
        }
        colIndexinFor=1;
        rowIndexinFor+=1;
    }  
    // ako nqma takuv index izliza
    return "0";
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
void Table::calculatingFormulasOnlyRc() const
{
    for(auto row : rows)
    {
        for(auto cell : row->getCells())
        {
            if(CellUtility::isFormula(cell->getValueCellString()))
            {
                bool rc = false;
                int secondWhiteSpaceIndex = cell->getValueCellString().find_first_of(" \t\n\r\f\v",2);
                int thirdWhiteSpaceIndex = cell->getValueCellString().find_first_of(" \t\n\r\f\v",secondWhiteSpaceIndex+1);
                std::string firstValue = cell->getValueCellString().substr(2,secondWhiteSpaceIndex-2);
                std::string secondValue = cell->getValueCellString().substr(thirdWhiteSpaceIndex+1,cell->getCellSize()-secondWhiteSpaceIndex);
                std::string operation = cell->getValueCellString().substr(secondWhiteSpaceIndex+1,1);
                if(firstValue.front() == 'R')
                {   
                    std::string rowIndexString;
                    std::string colIndexString;       
                    for (int i = 1; i < firstValue.find('C'); i++)
                    {
                        rowIndexString+=firstValue[i]; 
                    }
                    for (int i = firstValue.find('C')+1; i < firstValue.size(); i++)
                    {
                        colIndexString+=firstValue[i];
                    }
                      
                    int rowIndex = std::stoi(rowIndexString);
                    int colIndex = std::stoi(colIndexString); 
                    firstValue = getValueFromRowColumn(rowIndex,colIndex);
                    rc = true;
                }

                if(secondValue.front() == 'R')
                {
                    std::string rowIndexString;
                    std::string colIndexString;       
                    for (int i = 1; i < secondValue.find('C'); i++)
                    {
                        rowIndexString+=secondValue[i]; 
                    }
                    for (int i = secondValue.find('C')+1; i < secondValue.size(); i++)
                    {
                        colIndexString+=secondValue[i];
                    }


                    int rowIndex = std::stoi(rowIndexString);
                    int colIndex = std::stoi(colIndexString);
                    secondValue = getValueFromRowColumn(rowIndex,colIndex);
                    rc = true;
                }
                
                if(rc)
                {
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
}
void Table::calculatingFormulasNotRc() const
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

                if(firstValue.front() != 'R' || secondValue.front() != 'R')
                {
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
}
void Table::calculatingFormulas() const 
{     
    this->calculatingFormulasNotRc();
    this->calculatingFormulasOnlyRc();
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

void Table::edit(const int& rowIndex,const int& colIndex, const std::string& newCellValue)
{
    int correctedRowIndex = rowIndex - 1;
    int correctedColIndex = colIndex - 1;
    
    if (correctedRowIndex >= rows.size() || correctedRowIndex < 0) 
    {
        std::cerr << "Error: Index out of range\n";
        return;
    }
    rows[correctedRowIndex]->editCell(correctedColIndex, newCellValue);
    std::cout<<"Edited" << std::endl;
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