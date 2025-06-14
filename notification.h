#pragma once
#include "Mystring.h"
#include"Logger.h"
class Notification {
protected:
int notiId;
 Mystring msg;
public:
    Notification();
    Notification(int id, Mystring m);
    virtual void send();
};
