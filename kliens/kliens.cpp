#include <any>
#include <iostream>
#include <vector>
#include "../common/EnValues.h"
#include "Encode.h"
#include "Sender.h"

using namespace std;

int main(){

    vector<any> barmi;
    barmi.push_back(5);
    //barmi.push_back(5.55);
    any testi=32000000;
    any testd=98.1266;
    any testc='a';
    any tests="almafa de nagy";
    /*
    EnValues *point = new MyInt;
    EnValues values;
    EnValues values1;
    cout<<values.getType(testc)<<endl;
    string test=point->getString(testi);
    cout<<"vegso"<<endl;
    for(int i=0;i<4;i++){
        if(i==4){
            cout<<"||";
        }
        cout<<(int)test[i]<<" ";
    }*/
    cout<<"";
    Sender* send = new Sender;
    Encode* gg = new Encode;
    gg->encoding("add",barmi);
    send->Sending(gg->encoding("add",barmi));


    return 0;
}