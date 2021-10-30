#include "serversocket.h"

ServerSocket::ServerSocket(
        int port,
        ulong interface,
        int backlog_length
) : TcpSocket(port, interface)
{
    listening = listen(sock, backlog_length);
}
