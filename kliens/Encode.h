#ifndef Encode_H
#define Encode_H

#include <iostream>
#include <vector>
#include <any>
#include <map>
#include "../common/EnValues.h"


class Encode
{
private:
    //set tipus es a hozza tartozo alosztaly (MyInt, stb)
    std::map<std::string,EnValues*> EncodeMap;
    
public:
    Encode();
    ~Encode();
    std::string encoding(std::string Fnev, std::vector<std::any> parameterek);
};

#endif