#include <any>
#include <iostream>
#include <vector>
#include "KregFunction.h"

using namespace std;


int main()
{
    int testip1[] = {1, 2, 563};
    float testfp1[] = {1.2, 2.5, 3.12};

    //add(3, 5);
    cout<<"vectAdd: "<<vectorAdd(testip1,3)<<endl;
    float* retf = vectScalar(testfp1,3,2);
    for(int i=0;i<3;i++){
        cout<<retf[i]<<endl;
    }
    cout<<endl;
    /*
    vector<any> barmi;
    //barmi.push_back(5);
    //barmi.push_back(5.55);
    int testip1[]={1,2,563};
    float testfp1[]={1,2,3};
    double testdp1[]={1,2,3};
    float fff = 5.525;
    any testip = testip1;
    any testdp = testfp1;
    any testfp = testdp1;
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
    cout<<"int tomb: "<< testip.type().name()<<endl;
    cout<<"float tomb: "<< testfp.type().name()<<endl;
    cout<<"double tomb: "<< testdp.type().name()<<endl;
    
    int testip1[] = {1, 2, 563};
    float testfp1[] = {1, 2, 3};
    double testdp1[] = {1, 2, 3};
    char testcp1[]={'a','b','c'};
    string testsp1[]={"alma","korte","szilva"};
    bool testbp1[]={false,true,false};

    MyIntpS tmpi{ sizeof(testip1) / sizeof(testip1[0]), testip1};
    MyFloatpS tmpf{ sizeof(testfp1) / sizeof(testfp1[0]), testfp1};
    MyDoublepS tmpd{ sizeof(testdp1) / sizeof(testdp1[0]), testdp1};
    MyCharpS tmpc{ sizeof(testcp1) / sizeof(testcp1[0]), testcp1};
    MyStringpS tmps{ sizeof(testsp1) / sizeof(testsp1[0]), testsp1};
    MyBoolpS tmpb{ sizeof(testbp1) / sizeof(testbp1[0]), testbp1};
    
    any testi=tmpi;
    any testf=tmpf;
    any testd=tmpd;
    any testc=tmpc;
    any tests=tmps;
    any testb=tmpb;

    cout<<"int: "<< testi.type().name()<<endl;
    cout<<"float: "<< testf.type().name()<<endl;
    cout<<"double: "<< testd.type().name()<<endl;
    cout<<"char: "<< testc.type().name()<<endl;
    cout<<"string: "<< tests.type().name()<<endl;
    cout<<"bool: "<< testb.type().name()<<endl;
    
    EnValues* envalue = new MyIntP;
    kodolo.testOut(envalue->getString(testi));
    */
    /*
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
    /*
    Encode* gg = new Encode;
    string a = gg->encoding("add",barmi);
    cout<<"end"<<endl;
    for(unsigned int i=0;i<a.size();i++){
        cout<<(int)a[i]<<"  "<< a[i]<<endl;
    }
*/
    //send->Sending(gg->encoding("add",barmi));

    return 0;
}