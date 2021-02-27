#include "Server.h"
#include "../common/DeValues.h"

using namespace std;

Server::Server()
{
    // Create a socket
    listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cout << "Can't create a socket! Quitting" << endl;
        exit(1);
    }
    int opt = 1;
    if (setsockopt(listening, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) < 0)
    {
        cout << "Failed to set SO_REUSEADDR option. " << strerror(errno) << "\n";
        exit(1);
    }
    if (setsockopt(listening, SOL_SOCKET, SO_REUSEPORT, &opt, sizeof(opt)) < 0)
    {
        cout << "Failed to set SO_REUSEPORT option. " << strerror(errno) << "\n";
        exit(1);
    }

    // Bind the ip address and port to a socket
    sockaddr_in hint = {0};
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);
    if ((bind(listening, (sockaddr *)&hint, sizeof(hint))) == -1)
    {
        cout << "bind failed\n";
        exit(-1);
    }
    cout<<"the server is wating for the klient"<<endl;
    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);
    sockaddr_in clientsock;
    socklen_t clientSize = sizeof(clientsock);
    client = accept(listening, (sockaddr *)&client, &clientSize);
}

Server::Server(int kliens){
    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client == -1)
    {
        cout << "socket error" << endl;
        exit(1);
    }
    //	Create a hint structure for the server we're connecting with
    string ipAddress = "127.0.0.1";

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

    //	Connect to the server on the socket
    int connectRes = connect(client, (sockaddr *)&hint, sizeof(hint));
    if (connectRes == -1)
    {
        cout << "connect error" << endl;
        exit(1);
    }
}

Server::~Server()
{
    close(this->listening);
    close(this->client);
}

string Server::Recive()
{
    int hossz = ReciveSize();
    vector<char> buf(hossz);
    int res = recv(this->client, buf.data(), hossz, 0);
    if (!resCheck(res))
    {
        cout << "EXIT RES\n";
        exit(1);
    }
    while (res < hossz)
    {
        vector<char> bufextra(hossz);
        int extra = recv(client, bufextra.data(), hossz - res, 0);
        if (!resCheck(res))
        {
            cout << "EXIT RES\n";
            exit(1);
        }
        for (int i = 0; i < extra; i++)
            buf.at(i + res) = bufextra.at(i);
        res += extra;
    }
    string csomag(buf.begin(), buf.end());
    //cout << csomag << endl;
    return csomag;
}

bool Server::Sending(string message)
{
    int res = send(client, message.c_str(), message.size(), 0);
    if (!resCheck(res))
    {
        return false;
    }
    return true;
}


int Server::ReciveSize()
{
    vector<char> buf(2);
    int hossz;
    int res = recv(this->client, buf.data(), 2, 0);
    if (!resCheck(res))
    {
        cout << "EXIT RES\n";
        exit(1);
    }
    while (res < 2)
    {
        vector<char> bufextra(2);
        int extra = recv(client, bufextra.data(), 2 - res, 0);
        if (!resCheck(res))
        {
            cout << "EXIT RES\n";
            exit(1);
        }
        for (int i = 0; i < extra; i++)
            buf.at(i + res) = bufextra.at(i);
        res += extra;
    }
    string csomag(buf.begin(), buf.end());

    hossz = dekoder.Decode255(csomag);
    //cout << "hossz: " << hossz << endl;

    return hossz;
}

bool Server::resCheck(int res)
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
