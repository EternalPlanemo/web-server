#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QtCore/QObject>
#include <memory>
#include <QList>
#include "request.h"

class Controller
{
public:
    Controller(QObject* sender);
    void dispatch(Request *request);

private:
    QObject* sender;
};

#endif // CONTROLLER_H
