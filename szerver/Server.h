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



class Szerver{
    public:
        Szerver();
        ~Szerver();
        std::string Recive();

    private:
        sockaddr_in client;
        socklen_t clientSize = sizeof(client);
        int listening;
};




#endif