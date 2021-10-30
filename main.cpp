#include <cstring>
#include <memory>

#include "Server.h"
#include "ServerSocket.h"
#include "HttpResponse.h"

auto main(int argc, const char* argv[]) -> int
{
    /*
    try {
        const auto server = std::make_unique<Server<ServerSocket>>(std::stoi(argv[1]));
        server->run();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    */

    std::cout << HttpResponse("hello").get();

    return 0;
}
