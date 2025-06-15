#pragma once
#include <iostream>
using namespace std;
#include"Flight.h"
Flight::Flight(int id, Mystring num, Mystring dep, Mystring arr, int dur) : flightId(id), flightNumber(num), from(dep), to(arr), duration(dur) {};
Mystring Flight::getFlightNumber() {
	return flightNumber;
}
int Flight::getFlightId() {
	return flightId;
}
MyVector<FlightInstance>&Flight:: get_instances() {
	return instances;
}
void Flight::addSchedule(const Schedule& s) {
	schedules.push(s);
}
void Flight::addInstance(const FlightInstance& fi) {
	instances.push(fi);
}
void Flight::print()const {
	cout << "flight no" << from << "->" << to << "in duration" << time;
	for (int i = 0; i < schedules.size(); i++) {
		cout << "day" << schedules[i].getDay();
		cout << "time" << schedules[i].getDepartureTime();
	}
	for (int i = 0; i < instances.size(); i++) {
		 instances[i].print();
	}
}
static void showFlightSchedule(const MyVector<Flight>& flights, const MyVector<Reservation>& reservations) {
    std::cout << "=Flight Schedule =";
    for (int i = 0; i < flights.size();i++) {
        flights[i].print();
    }
}
Mystring Flight::get_from_city()const {
    return from;
}
Mystring Flight::get_to_city() const{
    return to;
}

static void bookTicket(MyVector<Flight>& flights, MyVector<Reservation>& reservations) {
    cout << "Enter flight no";
    Mystring num;
    cin >> num;
    Flight* f1 = nullptr;
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].getFlightNumber() == num)
            f1 = &flights[i];
    }
    if (!f1) {
        cout << "fliht not found";
        return;
    }
    cout << "Available Instances";
    for (int i = 0; i < f1->get_instances().size(); i++) {
        f1->get_instances()[i].print();
    }

  cout << "enter Instance ID to book: ";
    int iid;
    cin >> iid;
    FlightInstance* f2 = nullptr;
    for (int i = 0; i < f1->get_instances().size(); i++) {
        if (f1->get_instances()[i].getInstanceID() == iid)
            f2 = &f1->get_instances()[i];
    } 
}
 void Flight::save(fstream& f) {
     int l2= from.length();
         f.write((char*)&l2, sizeof(l2));
         f.write((const char*)from, l2);

         int l3= to.length();
         f.write((char*)&l3, sizeof(l3));
         f.write((const char*)to, l3);
     int l = schedules.size();
     f.write((char*)&l, sizeof(l));
     for (int i = 0; i < l; i++) {
         schedules[i].save(f);
     }
   int l1 = instances.size();
   f.write((char*)&l1, sizeof(l1));
   for (int i = 0; i < l1; i++) {
         instances[i].save(f);
     }
     f.write((char*)&flightId, sizeof(flightId));
    
 }
 void Flight::load(fstream& f) {
     int l, l1, l2,l3;
     f.read((char*)&l3, sizeof(l3));
     char* temp2 = new char[l3 + 1];
     f.read(temp2, l3);
     temp2[l3] = '\0';
     delete[] temp2;

     f.read((char*)&l2, sizeof(l2));
     char* temp1 = new char[l2 + 1];
     f.read(temp1, l2);
     temp1[l2] = '\0';
     delete[] temp1;

     f.read((char*)&l, sizeof(l));
     for (int i = 0; i < l; i++) {
         schedules[i].load(f);
     }
     f.write((char*)&l1, sizeof(l1));
     for (int i = 0; i < l1; i++) {
         instances[i].save(f);
     }
     f.read((char*)&flightId, sizeof(flightId));
     
 }
