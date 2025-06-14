#include<iostream>
using namespace std;
#include"sms_notification.h"
SmsNotification::SmsNotification() : Notification(), phone("0") {}
SmsNotification::SmsNotification(int id, const Mystring& c, const Mystring& ph):Notification(id, c),phone(ph){};
void SmsNotification::setPhone(const Mystring& p) {
        phone = p;
 }
void SmsNotification::send() { 
   Logger::getInstance().log("sms sent."); 
}
