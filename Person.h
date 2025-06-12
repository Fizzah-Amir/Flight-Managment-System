#pragma once
#include"Mystring.h"
#include "Address.h"
class Person {
protected:
    Mystring name;
    Mystring email;
    Mystring phone;
    Address address;
public:
    Person();
    Person(Mystring& n,  Address& a, Mystring& e,Mystring& p);
    void setName(Mystring& n);
    void setAddress( Address& a);
    void setEmail( Mystring& e);
    void setPhone( Mystring& p);
    Mystring getName() ;
    Mystring getEmail() ;
    Mystring getPhone() ;
    Address getAddress();
    virtual void print();
};
