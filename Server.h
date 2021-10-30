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
#include <thread>
#include <chrono>
#include <curlpp/Easy.hpp>

#include "Socket.h"

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
    char* buffer;
    std::unique_ptr<Socket> socket;
};

template <typename SocketT>
Server<SocketT>::Server(int port)
{
    socket = std::unique_ptr<SocketT>(new SocketT(port, INADDR_ANY));
    buffer_size = 1024;
    buffer = new char[buffer_size];

    std::cout << "Listening on port " << port << '\n';
}

template <typename SocketT>
void Server<SocketT>::run()
{
    int accepted_con = -1;
    sockaddr_in addr;
    socklen_t addrlen;

    const char* pong = "HTTP/1.1 200 OK"
            "Server: geo/1.0.0"
            "Date: Wed, 30 Oct 2021 10:30:07 GMT"
            "Content-Type: text"
            "Connection: keep-alive"
            "Vary: Cookie"
            "Content-Length: 2"
            "\r\n\r\n"
            "abc\n";

    while(true) {
        if ((accepted_con = accept(socket->get_sock(), (struct sockaddr *)&addr, (socklen_t*)&addrlen))<0) {
            throw new std::runtime_error("Failed to establish connection.");
        }

        memset(buffer, '\0', buffer_size);

        read(accepted_con, buffer, buffer_size);
        printf("%s\n",buffer );
        write(accepted_con, pong , strlen(pong));
        printf("------------------Hello message sent-------------------\n");
        close(accepted_con);
    }
}

#endif // SERVER_H

