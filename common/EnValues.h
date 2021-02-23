#ifndef EnValues_H
#define EnValues_H

#include <any>
#include <iostream>

class EnValues
{
public:
    //EnValues();
    virtual ~EnValues(){
        std::cout<<"";
    }
    //visszateriti a valtozo tipusat, megy direkt
    std::string getType(std::any value);
    //visszateriti a valtozot strinnge alakitva,
    //az elso 2 byte a hossz, 
    //egy char a tipus
    //tobbi simma karakter
    //alosztaly kell elvegezze
    std::string virtual getString(std::any value);
    std::string IntToString(int value);
};

class MyInt:public EnValues
{
public:
    ~MyInt(){}
    std::string getString(std::any value);
};

class MyFloat:public EnValues
{
public:
    ~MyFloat(){}
    std::string getString(std::any value);
};

class MyDouble:public EnValues
{
public:
    ~MyDouble(){}
    std::string getString(std::any value);
};

class MyChar:public EnValues
{
public:
    ~MyChar(){}
    std::string getString(std::any value);
};

class MyString:public EnValues
{
public:
    ~MyString(){}
    std::string getString(std::any value);
};

class MyBool:public EnValues
{
public:
    ~MyBool(){}
    std::string getString(std::any value);
};








#endif