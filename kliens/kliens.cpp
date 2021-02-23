#include <any>
#include <iostream>
#include <vector>
#include "../common/EnValues.h"
#include "Encode.h"
#include "Sender.h"

using namespace std;

int main(){

    vector<any> barmi;
    //barmi.push_back(5);
    //barmi.push_back(5.55);
    float fff = 5.525;
    any testf = fff;
    any testi=32000000;
    any testd=98.1266;
    any testb = true;
    any testc='a';
    any tests="almafa de nagy";
    barmi.push_back(testf);
    barmi.push_back(testi);
    barmi.push_back(testd);
    barmi.push_back(testc);
    barmi.push_back(tests);

    cout<<"float: "<< testf.type().name()<<endl;
    cout<<"bool: "<< testb.type().name()<<endl;
    cout<<"char: "<< testc.type().name()<<endl;
    cout<<"string: "<< tests.type().name()<<endl;
    
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
    }
    cout<<"";
    Sender* send = new Sender;
    */
    Encode* gg = new Encode;
    string a = gg->encoding("add",barmi);
    cout<<"end"<<endl;
    for(unsigned int i=0;i<a.size();i++){
        cout<<(int)a[i]<<"  "<< a[i]<<endl;
    }

    //send->Sending(gg->encoding("add",barmi));


    return 0;
}