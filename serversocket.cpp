#include "serversocket.h"

ServerSocket::ServerSocket(
        int port,
        ulong interface,
        int backlog_length
) : TcpSocket(port, interface)
{
    listening = listen(connection, backlog_length);
}
