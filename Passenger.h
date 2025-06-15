#pragma once
#include "Person.h"

class Passenger : public Person {
    Mystring passportNumber;
public:
    Passenger();
    Passenger(Mystring n, Address a, Mystring e, Mystring p, Mystring passp);
    void setPassportNumber(Mystring pn);
    Mystring getPassportNumber();
    void print() override;
};