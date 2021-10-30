#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include "Socket.h"

class TcpSocket : public Socket
{
public:
    TcpSocket(int port, ulong interface);
    virtual int establish(int sock, struct sockaddr_in address) override;
};

#endif // TCPSOCKET_H
