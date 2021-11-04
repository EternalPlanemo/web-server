#include "Router.h"

#include <stdexcept>
#include <iostream>

Router::Router()
{

}

auto Router::add(std::string url, Callback callback) -> void
{
    _map.insert({url, callback});
}

auto Router::dispatch(std::string url, HttpRequest request) -> HttpResponse
{
    try {
        const auto f = _map.at(url);
        return f(request);
    }  catch (std::out_of_range& e) {
        std::cerr << "Route `" << url << "` is undefined.\n";
        return HttpResponse("Route `" + url + "` is undefined.\n");
    }
}
