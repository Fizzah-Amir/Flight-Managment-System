#include<iostream>
using namespace std;
#include"Passenger.h"
Passenger::Passenger::Passenger() : Person(), passportNumber("") {}
Passenger::Passenger(Mystring n, Address a, Mystring e, Mystring p, Mystring passp)
    : Person(n, a, e, p), passportNumber(passp) {}
void Passenger::setPassportNumber( Mystring pn) {
    passportNumber = pn; 
}
Mystring Passenger::getPassportNumber()  { 
    return passportNumber;
}
void Passenger::print() {
    Person::print(); cout << "Passport No: " << passportNumber;
}

