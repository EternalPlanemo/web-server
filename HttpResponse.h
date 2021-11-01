#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <string>
#include <QString>
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

    header = QString("HTTP/1.1 200 OK\n"
             "Server: geo/1.0.0\n"
             "Date: %1\n"
             "Content-Type: text\n"
             "Connection: keep-alive\n"
             "Content-Length: %2"
    ).arg(QDateTime().currentDateTimeUtc().toString().toStdString().c_str(), std::to_string(body.size()).c_str()).toStdString();

    response = QString("%1\r\n\r\n%2\n").arg(header.c_str(), body.c_str()).toStdString();
}

auto HttpResponse::get() -> std::string
{
    return response;
}

#endif // HTTPRESPONSE_H
