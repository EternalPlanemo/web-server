#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include <fmt/format.h>
#include <QDateTime> // JavaScript-like time format

class HttpResponse
{
public:
    explicit HttpResponse(const std::string& body);
    auto get() -> std::string;

private:
    std::string header;
    std::string response;
};

HttpResponse::HttpResponse(const std::string& body)
{
    header = fmt::format("HTTP/1.1 200 OK"
             "Server: geo/1.0.0"
             "Date: {}"
             "Content-Type: text"
             "Connection: keep-alive"
             "Content-Length: {}",
             QDateTime().currentDateTimeUtc().toString().toStdString().c_str(),
             body.size()
    );

    response = header + fmt::format("\r\n\r\n{}\n", body);
}

auto HttpResponse::get() -> std::string
{
    return response;
}

#endif // HTTPRESPONSE_H
