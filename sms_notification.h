#pragma once
#include"Notification.h"
#include"Logger.h"
#include"Mystring.h"
class SmsNotification : public Notification {
Mystring phone;
public:
SmsNotification();
SmsNotification(int id,const Mystring& c, const Mystring& ph);
void setPhone(const Mystring& p);
void send()override;
};
