#include <iostream>
#include "Server.h"

using namespace std;

int main(){

    Server* szerver = new Server;
    while (true)
    {
        szerver->Recive();
    }
    
    

    return 0;
}