#ifndef SERVER_H
#define SERVER_H

#include <QtNetwork/QTcpServer>
#include <QThreadPool>
#include <QDebug>
#include <QObject>


#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(quint16 port, bool debug = false, QObject* parent = nullptr);
    ~Server();

Q_SIGNALS:
    void closed();

private Q_SLOTS:
    void onNewConnection();
    void processTextMessage(QString message);
    void processBinaryMessage(QByteArray message);
    void socketDisconnected();

private:
    QWebSocketServer* sockserver;
    QList<QWebSocket*> clients;
    bool debug;
};


#endif // SERVER_H
