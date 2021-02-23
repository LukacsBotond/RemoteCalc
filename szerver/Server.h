#ifndef Szerver_H
#define Szerver_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <list>

#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include "../common/DeValues.h"


class Server{
    public:
        Server();
        ~Server();
        std::string Recive();
        bool resCheck(int res);
    private:
        int client;
        int listening;
        int ReciveSize();
        DeValues dekoder;

};




#endif