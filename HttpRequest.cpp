#include "HttpRequest.h"

#include <sstream>

HttpRequest::HttpRequest(const std::string& request)
{
    std::stringstream ss(request);

    ss >> _method;
    ss >> _path;
}

auto HttpRequest::method() const -> std::string
{
    return _method;
}

auto HttpRequest::path() const -> std::string
{
    return _path;
}
