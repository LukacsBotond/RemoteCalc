#include "regFunc.h"
#include <iostream>

using namespace std;

int add(int a,int b){
    return a+b;
}

int vectorAdd(int* a,int length){
    int sum = 0;
    for(int i=0;i<length;i++){
        sum+=a[i];
    }
    return sum;
}

float* vectScalar(float* a,int length,int scalar){
    for(int i=0;i<length;i++){
        a[i]*=scalar;
    }
    return a;
}