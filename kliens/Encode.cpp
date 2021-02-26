#include "Encode.h"

using namespace std;

Encode::Encode()
{
    EncodeMap.insert(pair<string,EnValues*>("i",new MyInt));
    EncodeMap.insert(pair<string,EnValues*>("f",new MyFloat));
    EncodeMap.insert(pair<string,EnValues*>("d",new MyDouble));
    EncodeMap.insert(pair<string,EnValues*>("c",new MyChar));
    EncodeMap.insert(pair<string,EnValues*>("PKc",new MyString));
    EncodeMap.insert(pair<string,EnValues*>("b",new MyBool));

    EncodeMap.insert(pair<string,EnValues*>("7MyIntpS",new MyIntP));
    EncodeMap.insert(pair<string,EnValues*>("9MyFloatpS",new MyFloatP));
    EncodeMap.insert(pair<string,EnValues*>("10MyDoublepS",new MyDoubleP));
    EncodeMap.insert(pair<string,EnValues*>("8MyCharpS",new MyCharP));
    EncodeMap.insert(pair<string,EnValues*>("10MyStringpS",new MyStringP));
    EncodeMap.insert(pair<string,EnValues*>("8MyBoolpS",new MyBoolP));
}

Encode::~Encode()
{
    for(auto i=EncodeMap.begin();i!=EncodeMap.end();i++){
        delete(i->second);
    }
}

vector<any> Encode::parameters(){
    vector<any> ret;
    return ret;
}

vector<any> Encode::parameters(any a){
    vector<any> ret;
    ret.push_back(a);
    return ret;
}


vector<any> Encode::parameters(any a,any b){
    vector<any> ret;
    ret.push_back(a);
    ret.push_back(b);
    return ret;
}

string Encode::encoding(string fuggvenyNev,vector<any> parameter){
    EnValues tmp;
    string send=tmp.IntToString(fuggvenyNev.size());
    send+=fuggvenyNev;
    string parm="";
    unsigned int darab=parameter.size();
    for(unsigned int i=0;i<darab;i++){
        any element = parameter.at(i);
        string type(element.type().name());
        auto item = EncodeMap.find(type);
        if(item != EncodeMap.end()){
            send += item->second->getString(element);
        }
        else{
            throw invalid_argument("nincs ilyen parameter tipus implementalva");
        }
    }
    string sendFin=tmp.IntToString(send.size());
    sendFin+=send;
    return sendFin;
}

void Encode::testOut(string coded){
    unsigned int hossz = coded.size();
    for(unsigned int i=0;i<hossz;i++){
        cout<<i<<" "<<coded[i]<<" "<<(int)coded[i]<<endl;
    }
}
