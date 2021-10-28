#ifndef REQUEST_H
#define REQUEST_H

#include <QString>
#include <QtCore/QObject>

class Request
{
public:
    Request(QString data);
    void run();
    void set_sender(QObject* sender);

private:
    QString data;
    qintptr socket_descriptor;
    QObject* sender;
};

#endif // REQUEST_H
