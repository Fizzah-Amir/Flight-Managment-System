#pragma once
#include"Notification.h"
#include"Logger.h"
class EmailNotification : public Notification {
    Mystring email;
public:
    EmailNotification();
    EmailNotification(int id, Mystring c, Mystring e);
    void setEmail(const Mystring& e);
    void send();
};
