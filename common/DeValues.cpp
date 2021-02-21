#include "DeValues.h"

using namespace std;

int DeValues::StringToInt(string input){
    return stoi(input);
}

unsigned int DeValues::Decode255(string code){
    unsigned int hossz = 0;
    unsigned int mult = 1;
    for (int i = 1; i >= 0; i--)
    {
        hossz += ((unsigned char)code[i] * mult);
        mult *= 256;
    }
    return hossz;
}