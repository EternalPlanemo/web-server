#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <QRunnable>

class Runnable : public QRunnable
{
public:
    Runnable();

protected:
    void run();

public:
    qintptr socket_descriptor;
};

#endif // RUNNABLE_H
