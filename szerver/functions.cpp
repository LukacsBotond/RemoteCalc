#include "Functions.h"
#include "../common/DeValues.h"
#include "regFunc.h"
#include <map>
#include <vector>

using namespace std;

Functions::Functions(/* args */)
{
    FunctionsMap.insert(pair<string,Solve*>("add",new Add));
}

Functions::~Functions()
{
    for(auto i=FunctionsMap.begin();i!=FunctionsMap.end();i++){
        delete(i->second);
    }
}

string Functions::getFuncName(string message){
    Flength = decoder.Decode255(message.substr(0,2));
    return message.substr(2,Flength);
}

string Functions::getParameters(string message){
    return message.substr(Flength+2);
}

vector<string> Functions::getBoth(string message){
    vector<string> ret;
    ret.push_back(getFuncName(message));
    ret.push_back(getParameters(message));
    return ret;
}

std::string Functions::SolveFunc(std::string FuncName, std::string FuncParameter){
    auto item = FunctionsMap.find(FuncName);
        if(item != FunctionsMap.end()){
            return item->second->DecodeAll(FuncParameter);
        }
        else{
            return "nincs ilyen fuggveny implementalva";
        }
}

string Solve::DecodeAll(string parameters){
    throw out_of_range("you are not supposed to be here");
    return "";
}

string Add::DecodeAll(string parameters){
    int a,b;
    int shift = 3;
    unsigned int ahossz = decoder.Decode255(parameters.substr(0,2)) -1;
    a = stoi(parameters.substr(shift,ahossz));
    shift+=ahossz+3;
    b = stoi(parameters.substr(shift));
    string ret = to_string(add(a,b));
    return encoder.IntToString(ret.size()) + ret ;
}
