#include "tcpsocket.h"

#include <stdexcept>

TcpSocket::TcpSocket(
        int port,
        ulong interface
) : Socket(AF_INET, SOCK_STREAM, 0, port, interface)
{
    if (bind(sock, (sockaddr*)&address, sizeof (address)) < 0) {
        throw new std::runtime_error("Establishing connection failed.");
    }
}

auto TcpSocket::establish(int sock, sockaddr_in address) -> int
{
    return bind(sock, (sockaddr*)&address, sizeof (address));
}
