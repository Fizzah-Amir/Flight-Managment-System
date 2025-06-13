pragma once
#include <iostream>
using namespace std;
#include"Flight.h"
Flight::Flight() : flightId(0), flightNumber(""), from(""), to(""), duration(0) {};
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
 void Flight::show_schedule(const MyVector<Flight>& flights, MyVector<Reservation>& reservations) {
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
//remove reservations
 void Flight::bookTicket(MyVector<Flight>& flights, MyVector<Reservation>& reservations) {
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

    std::cout << "enter Instance ID to book: ";
    int iid;
    cin >> iid;
    FlightInstance* f2 = nullptr;
    for (int i = 0; i < f1->get_instances().size(); i++) {
        if (f1->get_instances()[i].getInstanceID() == iid)
            f2 = &f1->get_instances()[i];
    }
    if (!f2 || f2->isCancel()) {
        cout << "Instance not found ";
        return;
    }
    //assumption:more that 5 seats cannot be reserved 
    if (f2->getReservedSeats() >= 5) {
        cout << "Max reservations reached,no more can be reserved";
        return;
    }
    cout << "Enter passenger name: ";
    Mystring pname;
    cin >> pname;
    int newResId;
    if (reservations.empty()) {
        newResId = 1;
    }
    else {
        Reservation r1 = reservations.back();
        int lastId = r1.get_reservation_Id();
        newResId = lastId + 1;
    }
    reservations.push(Reservation(newResId, f1->getFlightId(), iid, pname));
    f2->reserveSeat();
    Logger::getInstance().log("reservation done.");
    cout << "Booking successful with r_id " << newResId << endl;
}



  void Flight::searchFlights(const MyVector<Flight>& flights) {
    std::cout << "Enter departure city: ";
    Mystring dep; std::cin >> dep;
    std::cout << "Enter arrival city: ";
    Mystring arr; std::cin >> arr;
    std::cout << "Matching Flights:\n";
    for (int i = 0; i < flights.size(); ++i) {
        if (flights[i].get_from_city() == dep && flights[i].get_to_city() == arr) {
            flights[i].print();
        }
    }
}
 void Flight::update_schedule(MyVector<Flight>& flights) {
    cout << " press 1 add flight" ;
   cout << " press 2  remove flight";
   cout << "press 0 to exit";
    int choice;
    cin >> choice;
    if (choice== 1) {
        int id;
        int  dur;
        Mystring num;
        Mystring dep;
        Mystring arr;
        cout << "enter new flight id ";
        cin >> id;
        cout << "flight number ";
        cin >> num;
        cout << "departure city";
        cin >> dep;
        cout << "arrival city";
        cin >> arr;
        cout << "time in(min)"; 
        cin >> dur;
        Flight f1(id, num, dep,arr, dur);
        flights.push(f1);
        cout << "Flight added";
    }
   else if (choice== 2) {
        cout << "Enter flight no to remove: ";
        Mystring num;
      cin >> num;
        for (int i = 0; i < flights.size();i++) {
            if (flights[i].getFlightNumber() == num) {
                flights.delete_at(i);
               cout << "fight deleted";
                return;
            }
        }
        cout << "flight not found";
    }
}

