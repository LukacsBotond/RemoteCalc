#ifndef EnValues_H
#define EnValues_H

#include <any>
#include <iostream>

class EnValues
{
private:
public:
    //EnValues();
    virtual ~EnValues(){
        std::cout<<"";
    }
    //visszateriti a valtozo hosszat, kulon alosztaly kell a mukodesehez
    int virtual getSize(std::any value);
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
private:
    /* data */
public:
    ~MyInt(){
        std::cout<<"";
    }
    int getSize(std::any value);
    std::string getString(std::any value);
};



#endif