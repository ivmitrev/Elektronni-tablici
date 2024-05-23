#pragma once
#include<cstring>
#include<iostream>
#include<sstream>
#include<iomanip>
class Cell 
{
public:
   virtual void print() const = 0;
   virtual void print(int cellWidth) const = 0;
   virtual int getCellSize() const = 0;
   virtual std::string getValueCellString() const = 0;
   // virtual void setValueCellString(const std::string& value) = 0;
   virtual ~Cell() = default;
protected:
};
