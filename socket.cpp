#include "socket.h"

#include <stdexcept>
#include <unistd.h>

Socket::Socket(
        int domain,
        int service,
        int protocol,
        int port,
        ulong interface
)
{
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);

    sock = socket(domain, service, protocol);

    if (sock < 0) {
        throw new std::runtime_error("Socket initialization failed.");
    }
}

auto Socket::get_sock() -> int
{
    return sock;
}

auto Socket::get_address() -> sockaddr_in
{
    return address;
}

Socket::~Socket()
{
    close(sock);
}
