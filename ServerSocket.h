#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H

#include "TcpSocket.h"

class ServerSocket : public TcpSocket
{
public:
    ServerSocket(int port, ulong interface, int backlog_length = 4);

private:
    int listening;
};

#endif // SERVERSOCKET_H
