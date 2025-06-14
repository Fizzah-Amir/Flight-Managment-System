#include<iostream>
using namespace std;
#include"Notification.h"
Notification::Notification() : notiId(0), msg("") {};
Notification::Notification(int id,  Mystring m) : notiId(id),msg(m) {};
 void Notification:: send() { 
   Logger::getInstance().log(msg);
}
