#ifndef DeValues_H
#define DeValues_H

#include <iostream>

class DeValues
{
private:
    /* data */
public:
    DeValues(/* args */);
    ~DeValues();
    int StringToInt(std::string input);
    unsigned int Decode255(std::string code);
};

DeValues::DeValues(/* args */)
{
}

DeValues::~DeValues()
{
}




#endif