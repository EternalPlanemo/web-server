#include "server.h"
#include "QtWebSockets/qwebsocketserver.h"
#include "QtWebSockets/qwebsocket.h"
#include <QtCore/QDebug>

QT_USE_NAMESPACE

Server::Server(quint16 port, bool debug, QObject *parent) :
    QObject(parent),
    sockserver(new QWebSocketServer(QStringLiteral("WebServer"), QWebSocketServer::NonSecureMode, this)),
    debug(debug)
{
    if (sockserver->listen(QHostAddress::Any, port)) {
        if (debug) qDebug() << "Server listening on port" << port;

        connect(sockserver, &QWebSocketServer::newConnection, this, &Server::onNewConnection);
        connect(sockserver, &QWebSocketServer::closed, this, &Server::closed);
    }
}

Server::~Server()
{
    sockserver->close();
    qDeleteAll(clients.begin(), clients.end());
}

void Server::onNewConnection()
{
    QWebSocket* pSocket = sockserver->nextPendingConnection();

    connect(pSocket, &QWebSocket::textMessageReceived, this, &Server::processTextMessage);
    connect(pSocket, &QWebSocket::binaryMessageReceived, this, &Server::processBinaryMessage);
    connect(pSocket, &QWebSocket::disconnected, this, &Server::socketDisconnected);

    clients << pSocket;
}

void Server::processTextMessage(QString message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (debug)
        qDebug() << "Message received:" << message;
    if (pClient) {
        pClient->sendTextMessage(message);
    }
}

void Server::processBinaryMessage(QByteArray message)
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (debug)
        qDebug() << "Binary Message received:" << message;
    if (pClient) {
        pClient->sendBinaryMessage(message);
    }
}

void Server::socketDisconnected()
{
    QWebSocket *pClient = qobject_cast<QWebSocket *>(sender());
    if (debug)
        qDebug() << "socketDisconnected:" << pClient;
    if (pClient) {
        clients.removeAll(pClient);
        pClient->deleteLater();
    }
}
