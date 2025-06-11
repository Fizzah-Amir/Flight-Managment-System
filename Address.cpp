#include<iostream>
using namespace std;
#include"Address.h"
Address::Address() : city(""), state(""), country(""){}
void Address::setCity(const Mystring& c) 
{ 
	city = c; 
}
void Address::setState(const Mystring& s) { 
	state = s;
}
void Address::setCountry(const Mystring& c) {
	country = c;
}

Mystring Address::getCity() {
	return city;
}
Mystring Address::getState() { 
	return state;
}
Mystring Address:: getCountry(){ 
	return country;
}

