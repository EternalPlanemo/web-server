#include "tcpsocket.h"

#include <stdexcept>

TcpSocket::TcpSocket(
        int port,
        ulong interface
) : Socket(AF_INET, SOCK_STREAM, 0, port, interface)
{
    connection = establish(sock, address);

    if (connection < 0) {
        throw new std::runtime_error("Establishing connection failed.");
    }
}

auto TcpSocket::establish(int sock, struct sockaddr_in address) -> int
{
    return bind(sock, (struct sockaddr*)&address, sizeof (address));
}
