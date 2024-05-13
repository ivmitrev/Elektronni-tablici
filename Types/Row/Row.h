#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include "Cell.h"
class Row 
{
private:
    std::vector<Cell*> rowofcells;
    Cell* createCell(const std::string cellValue) const;

public:
    Row();
    Row(const std::vector<Cell*> rowofcells);
    Row(const Row& other);
    Row& operator=(const Row& other);
    ~Row();
    
    void setCell(const std::string cellV,int col);
    Cell* getCell(int col) const;

};