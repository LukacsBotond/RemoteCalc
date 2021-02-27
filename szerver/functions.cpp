#include "Functions.h"
#include "../common/DeValues.h"
#include "regFunc.h"
#include <map>
#include <vector>

using namespace std;

Functions::Functions(/* args */)
{
    FunctionsMap.insert(pair<string, Solve *>("add", new Add));
    FunctionsMap.insert(pair<string, Solve *>("vectorAdd", new VectorAdd));
    FunctionsMap.insert(pair<string, Solve *>("vectScalar", new VectScalar));
}

Functions::~Functions()
{
    for (auto i = FunctionsMap.begin(); i != FunctionsMap.end(); i++)
    {
        delete (i->second);
    }
}

string Functions::getFuncName(string message)
{
    Flength = decoder.Decode255(message.substr(0, 2));
    return message.substr(2, Flength);
}

string Functions::getParameters(string message)
{
    return message.substr(Flength + 2);
}

vector<string> Functions::getBoth(string message)
{
    vector<string> ret;
    ret.push_back(getFuncName(message));
    ret.push_back(getParameters(message));
    return ret;
}

std::string Functions::SolveFunc(std::string FuncName, std::string FuncParameter)
{
    auto item = FunctionsMap.find(FuncName);
    if (item != FunctionsMap.end())
    {
        return item->second->DecodeAll(FuncParameter);
    }
    else
    {
        return "nincs ilyen fuggveny implementalva";
    }
}

/////////////////////////////////////////////////////////

string Solve::DecodeAll(string parameters)
{
    throw out_of_range("you are not supposed to be here");
    return "";
}

string Add::DecodeAll(string parameters)
{
    MyInt tmp;
    int a, b;
    int shift = 3;
    unsigned int ahossz = decoder.Decode255(parameters.substr(0, 2)) - 1;
    a = stoi(parameters.substr(shift, ahossz));
    shift += ahossz + 3;
    b = stoi(parameters.substr(shift));
    return tmp.getString(add(a, b));
}

string VectorAdd::DecodeAll(string parameters)
{
    MyInt tmp;
    int parameterszam = decoder.Decode255(parameters.substr(3, 2));
    string values = parameters.substr(5);
    int ret1[parameterszam];
    int *ertekek = decoder.StringToIntP(values, parameterszam, ret1);
    return tmp.getString(vectorAdd(ertekek, parameterszam));
}

string VectScalar::DecodeAll(string parameters)
{
    MyFloatP tmp;
    MyFloatpS ret;
    int shift = 5;
    int vecthossz = decoder.Decode255(parameters.substr(0, 2));
    ret.size = decoder.Decode255(parameters.substr(3, 2));
    string values = parameters.substr(shift, vecthossz - shift);
    shift += vecthossz;
    int scalar = stoi(parameters.substr(shift));
    float ret1[ret.size];
    ret.ertek = decoder.StringToFloatP(values, ret.size, ret1);
    ret.ertek = vectScalar(ret.ertek, ret.size, scalar);
    return tmp.getString(ret);
}