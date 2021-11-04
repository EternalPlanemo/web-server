#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include <QString>
#include <QDateTime> // JavaScript-like time format

class HttpResponse
{
public:
    explicit HttpResponse(const std::string& body);
    auto get() const -> std::string;
    auto size() const -> ulong;

private:
    std::string header;
    std::string response;
    ulong _size;
};

HttpResponse::HttpResponse(const std::string& body)
{
    header = QString("HTTP/1.1 200 OK\r\n"
             "Server: geo/1.0.0\r\n"
             "Date: %1\r\n"
             "Content-Type: text/html; charset=UTF-8\r\n"
             "Connection: keep-alive\r\n"
             "Content-Length: %2"
    ).arg(QDateTime().currentDateTimeUtc().toString().toStdString().c_str(), std::to_string(body.size()).c_str()).toStdString();

    response = QString("%1\r\n\r\n%2\r\n").arg(header.c_str(), body.c_str()).toStdString();

    _size = body.size();
}

auto HttpResponse::get() const -> std::string
{
    return response;
}

auto HttpResponse::size() const -> ulong
{
    return _size + 1;
}

#endif // HTTPRESPONSE_H
