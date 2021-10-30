#ifndef SOCKET_H
#define SOCKET_H

#include <cstdio>
#include <sys/socket.h>
#include <netinet/in.h>

class Socket
{
public:
    Socket(int domain, int service, int protocol, int port, ulong interface);
    virtual ~Socket();
    virtual int establish(int sock, sockaddr_in address) = 0;

    auto get_sock() -> int;
    auto get_address() -> sockaddr_in;
    auto size() const -> int;

protected:
    int sock;
    sockaddr_in address;
};

#endif // SOCKET_H
