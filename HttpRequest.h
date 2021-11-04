#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <string>

class HttpRequest
{
public:
    explicit HttpRequest(const std::string& request);
    auto method() const -> std::string;
    auto path() const -> std::string;

private:
    std::string _method;
    std::string _path;
};

#endif // HTTPREQUEST_H
