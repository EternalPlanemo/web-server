#include "runnable.h"

#include <QWebSocket>

Runnable::Runnable()
{

}

void Runnable::run()
{
    if(!socket_descriptor) return;

    QWebSocket socket;
    socket.setSocketDescriptor(socket_descriptor);

    socket.write("From server: hello world");
    socket.flush();
    socket.waitForBytesWritten();
    socket.close();
}
