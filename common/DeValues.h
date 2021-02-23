#ifndef DeValues_H
#define DeValues_H

#include <iostream>

class DeValues
{
private:
    /* data */
public:
    DeValues();
    ~DeValues();
    int StringToInt(std::string input);
    unsigned int Decode255(std::string code);
    
};

#endif