#ifndef Sender_H
#define Sender_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

class Sender
{
private:
    int sock;
    bool resCheck(int res);
public:
    Sender();
    ~Sender();
    bool Sending(std::string message);
};





#endif