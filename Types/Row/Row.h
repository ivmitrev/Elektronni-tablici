#pragma once
#include<iostream>
#include<cstring>
#include<vector>
#include "../Cell/Cell.h"
class Row 
{
private:
    std::vector<Cell*> cells;
public:
    Row() = default;
    ~Row();

    void addCell(Cell* cell);
    void print(int index) const;
    void printAll() const;
    int getSize() const;
    std::vector<Cell*> getCells() const;

    // Row(const std::vector<Cell*> rowofcells);
    // Row(const Row& other);
    // Row& operator=(const Row& other);
    // ~Row();
    
    // void setCell(const std::string cellV,int col);
    // Cell* getCell(int col) const;
    // void print() const;
    // void addCell(Cell* other);
   

};