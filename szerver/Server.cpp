#include "Server.h"

using namespace std;

Szerver::Szerver(){
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
    // Tell Winsock the socket is for listening
    listen(listening, SOMAXCONN);
}

Szerver::~Szerver(){
    close(this->listening);
}

string Szerver::Recive(){
    int hossz;



}
