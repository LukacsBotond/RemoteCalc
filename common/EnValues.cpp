#include "EnValues.h"
#include <iostream>
#include <algorithm>

using namespace std;

int EnValues::getSize(any value)
{
    throw out_of_range("you are not supposed to be here");
    return sizeof(value);
}

string EnValues::getType(any value){
    string ret(value.type().name());
    return ret;
}

string EnValues::getString(any value){
    throw out_of_range("you are not supposed to be here");
    return "";
}

string EnValues::IntToString(int value)
{
    string ret="";
    unsigned char ures;
    for (int i = 0; i <= 1; i++)
    {
        ures = value % 256;
        //cout<<(int)ures<<" ";
        value /= 256;
        ret+=ures;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

int MyInt::getSize(any value)
{
    return sizeof(int);
}

string MyInt::getString(any value){
    int ertek = any_cast<int>(value);
    string ret2= to_string(ertek);
    string ret1=IntToString(ret2.size())+'i';
    return ret1+ret2;
}
