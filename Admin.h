#pragma once
#include "Person.h"
#include"Mystring.h"
class Admin : public Person {
public:
 Admin();
Admin(Mystring n,  Address a, Mystring e,  Mystring p);
  void addFlight();
  void cancelFlight();
  void sendNoti(Mystring msg);
};
