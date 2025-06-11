#pragma once
#include "Mystring.h"
class Address {
public:
    Mystring city;
    Mystring state;
    Mystring country; 
    Address();
    void setCity(const Mystring& c);
    void setState(const Mystring& s);
    void setCountry(const Mystring& c);
    Mystring getCity();
    Mystring getState();
    Mystring getCountry();
};