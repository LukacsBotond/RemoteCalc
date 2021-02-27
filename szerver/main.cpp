#include <iostream>
#include "../common/Server.h"
#include "Functions.h"

using namespace std;

int main()
{

    Server *szerver = new Server;
    Functions func;
    while (true)
    {
        vector<string> fuggveny;
        string message = szerver->Recive();
        cout<<"recived"<<endl;
        fuggveny = func.getBoth(message);
        cout<<"cut"<<endl;
        string ret = func.SolveFunc(fuggveny.at(0),fuggveny.at(1));
        cout<<"sending: "<<ret<<endl;
        szerver->Sending(ret);
        
        unsigned int hossz = ret.size();
        for (unsigned int i = 0; i < hossz; i++)
        {
            cout << i << " " << ret[i] << " " << (int)ret[i] << endl;
        }

    
    }

    return 0;
}