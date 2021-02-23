#include "Sender.h"
#include <iostream>

using namespace std;

Sender::Sender(/* args */)
{
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        cout << "socket error" << endl;
        exit(1);
    }
    //	Create a hint structure for the server we're connecting with
    int port = 54000;
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(sock, (sockaddr *)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        cout << "connect error" << endl;
        exit(1);
    }
}

Sender::~Sender()
{
    close(sock);
}

bool Sender::Sending(string message)
{
    int res = send(sock, message.c_str(), message.size(), 0);
    if (!resCheck(res))
    {
        return false;
    }
    return true;
}

bool Sender::resCheck(int res)
{
    if (res < 0)
    {
        cout << "RECV error\n";
        return false;
    }
    if (res == 0)
    {
        cout << "kilepett\n";
        return false;
    }
    return true;
}
