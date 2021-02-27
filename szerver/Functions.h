#ifndef Functions_H
#define Functions_H

#include "../common/DeValues.h"
#include "../common/EnValues.h"
#include <iostream>
#include <map>
#include <vector>

class Solve;

class Functions
{
private:
    DeValues decoder;
    std::map<std::string, Solve *> FunctionsMap;
    int Flength;

public:
    Functions();
    ~Functions();
    std::string getFuncName(std::string message);
    std::string getParameters(std::string message);
    std::vector<std::string> getBoth(std::string message);
    std::string SolveFunc(std::string FuncName, std::string FuncParameter);
};

class Solve
{
protected:
    DeValues decoder;
    EnValues encoder;
public:
    Solve() {}
    virtual ~Solve() {}
    virtual std::string DecodeAll(std::string parameters);
};

class Add : public Solve
{
public:
    Add() {}
    ~Add() {}
    std::string DecodeAll(std::string parameters);
};

class VectorAdd: public Solve
{
private:
    /* data */
public:
    VectorAdd(){}
    ~VectorAdd(){}
    std::string DecodeAll(std::string parameters);
};

class VectScalar: public Solve
{
private:
    /* data */
public:
    VectScalar(){}
    ~VectScalar(){}
    std::string DecodeAll(std::string parameters);
};




#endif