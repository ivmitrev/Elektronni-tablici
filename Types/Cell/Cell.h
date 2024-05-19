#pragma once
#include<cstring>
#include<iostream>
class Cell 
{
public:
   virtual void print() const = 0;
  // virtual void print(int cellWidth) const = 0;
   virtual ~Cell() = default;
   virtual int getCellSize() const = 0;
};
