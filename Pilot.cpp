#include"Pilot.h"
#include<iostream>
using namespace std;
Pilot::Pilot() : Person() { 
    assignCount = 0;
}
Pilot::Pilot( Mystring n,  Address a, Mystring e,  Mystring p) : Person(n, a, e, p) {
    assignCount = 0;
}
void Pilot::assignFlight(int flightID) {
    if (assignCount <5) {
        assignedFlight[assignCount] = flightID;
        assignCount++;
        Logger::getInstance().log("pilot has been assigned to flight");
    }
}
void Pilot::printAssignedFlights() {
    cout << "pilot" << name << " assigned  flights";
    for (int i = 0; i < assignCount; i++) {
        cout << assignedFlight[i];
    }
    cout << endl;
}
void Pilot::save(fstream& f) {
    int l = name.length();
    f.write((char*)&l, sizeof(l));
    f.write((const char*)name, l);
    int l1 = email.length();
    f.write((char*)&l1, sizeof(l1));
    f.write((const char*)email,l1);
}
void Pilot::load(fstream& f) {
    int l = name.length();
    f.read((char*)&l, sizeof(l));
    char* temp = new char[l + 1];
    f.read(temp, l);
    temp[l] = '\0';
    delete[] temp;
    int l1 = email.length();
    f.read((char*)&l1, sizeof(l1));
    char* temp1 = new char[l1 + 1];
    f.read(temp1, l1);
    temp[l1] = '\0';
    delete[] temp1;
}

