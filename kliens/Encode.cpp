#include "Encode.h"

using namespace std;

Encode::Encode()
{
    EncodeMap.insert(pair<string,EnValues*>("i",new MyInt));
}

Encode::~Encode()
{
    for(auto i=EncodeMap.begin();i!=EncodeMap.end();i++){
        delete(i->second);
    }
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
    cout<<"SendSize: "<<send.size()<<endl;
    string sendFin=tmp.IntToString(send.size());
    sendFin+=send;
    cout<<sendFin<<endl;
    return sendFin;
}
