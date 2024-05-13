#pragma once
#include<cstring>
#include<iostream>
class Cell 
{
public:
    Cell(const std::string& value);
    virtual ~Cell();
    virtual int getLength() const;
    virtual std::string getValue() const;
    virtual void setValue(const std::string newValue);
protected:
    std::string cellValue;
};
