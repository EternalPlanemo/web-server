#ifndef ROUTER_H
#define ROUTER_H

#include <string>
#include <functional>
#include <map>

#include "HttpRequest.h"
#include "HttpResponse.h"

class Router
{
public:
    using Callback = std::function<HttpResponse(HttpRequest request)>;
    using RouterPair = std::pair<std::string, Callback>;

    Router();
    auto add(std::string url, Callback callback) -> void;
    HttpResponse dispatch(std::string url, HttpRequest request);

private:
    std::map<std::string, Callback> _map;
};

#endif // ROUTER_H
