#include "EnValues.h"
#include <iostream>
#include <algorithm>

using namespace std;

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
        value /= 256;
        ret+=ures;
    }
    reverse(ret.begin(),ret.end());
    return ret;
}

string MyInt::getString(any value){
    int ertek = any_cast<int>(value);
    string ret2= to_string(ertek);
    string ret1=IntToString(ret2.size())+'i';
    return ret1+ret2;
}

string MyFloat::getString(any value){
    float ertek = any_cast<float>(value);
    string ret2= to_string(ertek);
    string ret1=IntToString(ret2.size())+'f';
    return ret1+ret2;
}

string MyDouble::getString(any value){
    double ertek = any_cast<double>(value);
    string ret2= to_string(ertek);
    string ret1=IntToString(ret2.size())+'d';
    return ret1+ret2;
}

string MyChar::getString(any value){
    char ertek = any_cast<char>(value);
    string ret1=IntToString(1)+'c'+ertek;
    return ret1;
}

string MyString::getString(any value){
    string ret2 = any_cast<const char*>(value);
    string ret1=IntToString(ret2.size())+'s';
    return ret1+ret2;
}

string MyBool::getString(any value){
    bool ertek = any_cast<bool>(value);
    string ret2= to_string(ertek);
    string ret1=IntToString(ret2.size())+'b';
    return ret1+ret2;
}

