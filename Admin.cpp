#include<iostream>
using namespace std;
#include"Admin.h"
#include"Logger.h"
Admin::Admin() : Person() {};
Admin::Admin(Mystring n, Address a, Mystring e, Mystring p) : Person(n, a, e, p) {};
void Admin::addFlight() {
	Logger::getInstance().log("Admin added a new flight."); 
}
void Admin::cancelFlight() {
	Logger::getInstance().log("Admin cancelled a flight.");
}
void Admin::sendNoti( Mystring msg) { 
	Logger::getInstance().log(msg); 
}