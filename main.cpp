#include "dependencies.h"
#include <iostream>

auto main() -> int
{
    try {
        auto* sock = new ServerSocket(3000, INADDR_ANY);
    }  catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
