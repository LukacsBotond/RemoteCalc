#include "KregFunction.h"
#include "Encode.h"
#include "../common/Server.h"
#include "../common/EnValues.h"
#include "../common/DeValues.h"
#include "Encode.h"

using namespace std;

Server kliens(1);
Encode kodolo;
DeValues decode;

int add(int a, int b)
{
    string test = kodolo.encoding(__FUNCTION__, kodolo.parameters(a, b));
    kliens.Sending(test);
    return stoi(kliens.Recive().substr(1));
}

int vectorAdd(int* a,int length){
    MyIntpS tomb {length,a};
    string test = kodolo.encoding(__FUNCTION__, kodolo.parameters(tomb));
    kliens.Sending(test);
    return stoi(kliens.Recive().substr(1));
}

float* vectScalar(float* a,int length,int scalar){
    MyFloatpS tomb {length,a};
    string test = kodolo.encoding(__FUNCTION__, kodolo.parameters(tomb,scalar));
    kliens.Sending(test);
    a = decode.StringToFloatP(kliens.Recive().substr(3),length,a);
    cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
    return a;
}