#include "Socket.h"

#include <stdexcept>
#include <unistd.h>
#include <cstring>

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

    memset(address.sin_zero, '\0', sizeof (address.sin_zero));

    sock = socket(domain, service, protocol);

    if (sock < 0) {
        throw new std::runtime_error("Socket initialization failed.");
    }
}

Socket::~Socket()
{
    close(sock);
}

auto Socket::get_sock() -> int
{
    return sock;
}

auto Socket::get_address() -> sockaddr_in
{
    return address;
}

auto Socket::size() const -> int
{
    return sizeof (address);
}
