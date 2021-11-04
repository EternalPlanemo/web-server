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
#include "ftos.h"
#include "HttpResponse.h"
#include "HttpRequest.h"
#include "Router.h"

template <typename SocketT>
class Server
{
public:
    Server() {}
    explicit Server(int port);
    auto run() -> void;
    auto set_buffer_size(int size) -> void;
    auto route(std::string url, Callback callback) -> void;

private:
    int buffer_size;
    char* buffer;
    std::unique_ptr<Socket> socket;
    Router router;
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
auto Server<SocketT>::run() -> void
{
    int accepted_con = -1;
    sockaddr_in addr;
    socklen_t addrlen;

    const auto response = HttpResponse(ftos("test.html")).get();

    while(true) {
        if ((accepted_con = accept(socket->get_sock(), (struct sockaddr *)&addr, (socklen_t*)&addrlen))<0) {
            throw new std::runtime_error("Failed to establish connection.");
        }

        memset(buffer, '\0', buffer_size);

        read(accepted_con, buffer, buffer_size);

        write(accepted_con, response.c_str(), response.size());
        close(accepted_con);
    }
}

template <typename SocketT>
auto Server<SocketT>::route(std::string url, Callback callback) -> void
{
    router.add(url, callback);
}

#endif // SERVER_H

