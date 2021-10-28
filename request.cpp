#include "request.h"

#include <QWebSocket>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonParseError>

Request::Request(QString data) :
    data(data)
{

}

void Request::run()
{
    QWebSocket* pClient = qobject_cast<QWebSocket*>(sender);

    auto error = QJsonParseError();
    auto jdoc = QJsonDocument::fromJson(data.toLocal8Bit(), &error);
    auto json = jdoc.object();

    qDebug() << json.value("name").toString() << '\n';

    if (pClient) {
        qDebug() << pClient->sendTextMessage(json.value("name").toString());
    }
}

void Request::set_sender(QObject* sender)
{
    this->sender = sender;
}
