#ifndef SERVER_H
#define SERVER_H

#include <memory>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#include "socket.h"

template <typename SocketT>
class Server
{
public:
    Server() {}
    explicit Server(int port);
    auto run() -> void;
    auto set_buffer_size(int size) -> void;

private:
    int buffer_size;
    const char* buffer;
    std::unique_ptr<Socket> socket;
};

template <typename SocketT>
Server<SocketT>::Server(int port)
{
    socket = std::unique_ptr<SocketT>(new SocketT(port, INADDR_ANY));
    buffer_size = 1024;
    buffer = new char[buffer_size];
}

template <typename SocketT>
void Server<SocketT>::run()
{
    int accepted_con = -1;
    sockaddr_in addr;

    while (true) {
        addr = socket->get_address();
        socklen_t addrlen = sizeof (addr);

        accepted_con = accept(
                    socket->get_sock(),
                    (sockaddr*)&addr,
                    &addrlen
        );

        std::cout << "Connected with "
                  << socket->get_address().sin_addr.s_addr
                  << " on port "
                  << socket->get_address().sin_port << '\n';

        read(socket->get_sock(), &buffer, buffer_size);

        std::cout << "Message: " << buffer << '\n';

        send(accepted_con, &buffer, sizeof (buffer), 0);
    }
}

#endif // SERVER_H
