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
