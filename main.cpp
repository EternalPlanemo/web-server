#include <iostream>

#include <server.h>
#include <serversocket.h>

auto main() -> int
{
    // const Server<ServerSocket>* server = new Server<ServerSocket>(3000);
    //server->run();

    auto s = new Server<ServerSocket>(3000);
    s->run();

    return 0;
}
