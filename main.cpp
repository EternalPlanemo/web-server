#include <QCoreApplication>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    // Server(quint16 port, bool debug = false, QObject* parent = nullptr);
    Server server(3000, true);

    return a.exec();
}
