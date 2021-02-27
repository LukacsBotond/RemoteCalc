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
        Server(int kliens);
        ~Server();
        std::string Recive();
        bool Sending(std::string message);
    private:
        int client;
        int listening;
        int ReciveSize();
        bool resCheck(int res);
        DeValues dekoder;

};




#endif