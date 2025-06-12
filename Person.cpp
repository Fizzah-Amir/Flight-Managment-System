#include<iostream>
using namespace std;
#include"Person.h"
Person::Person() : name(""), email(""), phone("") {}
Person::Person( Mystring& n,Address& a,Mystring& e, Mystring& p): name(n), address(a), email(e), phone(p) {}
void Person::setName( Mystring& n) {
	name = n; 
}
void Person::setAddress( Address& a) {
	address = a;
}
void Person::setEmail( Mystring& e) { 
	email = e;
}
void Person::setPhone( Mystring& p) { 
	phone = p;
}
Mystring Person::getName()  {
	return name;
}
Mystring Person::getEmail(){
	return email;
}
Mystring Person::getPhone() {
	return phone;
}
Address Person::getAddress() {
	return address; 
}
 void Person::print(){	
	 cout << name << " " << email << " ";
}
