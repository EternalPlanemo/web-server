#include <string.h>
#include <memory>

#include "server.h"
#include "serversocket.h"

auto main(int argc, const char* argv[]) -> int
{
    try {
        const auto server = std::make_unique<Server<ServerSocket>>(std::stoi(argv[1]));
        server->run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
