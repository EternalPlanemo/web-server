#include "controller.h"

#include <memory>
#include <iostream>

Controller::Controller(QObject* sender) :
    sender(sender)
{

}

void Controller::dispatch(Request* request)
{

    request->set_sender(sender);
    request->run();
}
