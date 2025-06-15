#pragma once
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
void Flight::add_schedule(const Schedule& s) {
	schedules.push(s);
}
void Flight::add_instance(const FlightInstance& fi) {
	instances.push(fi);
}
void Flight::print()const {
	cout << "flight no" <<flightNumber<< from << "->" << to << "in duration" << time;
	for (int i = 0; i < schedules.size(); i++) {
        cout << "day" << schedules[i].getDay() << endl;
        cout << "time" << schedules[i].getDepartureTime() << endl;
	}
	for (int i = 0; i < instances.size(); i++) {
		 instances[i].print();
         cout << endl;
	}
}
 void Flight::show_schedule(const MyVector<Flight>& flights, MyVector<Reservation>& reservations) {
   cout << "=Flight Schedule =";
    for (int i = 0; i < flights.size();i++) {
        flights[i].print();
    }
    cout << endl;
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

    cout << "enter Instance ID to book: ";
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
        throw Mystring("reservatin limit ");
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
    cout << "Enter departure city: ";
    Mystring dep; 
   cin >> dep;
   cout << "Enter arrival city: ";
    Mystring arr; 
    cin >> arr;
    for (int i = 0; i < flights.size();i++) {
        if (flights[i].get_from_city() == dep && flights[i].get_to_city() == arr) {
            flights[i].print();
        }
        else {
            throw Mystring("flight not found");
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
            }
        }
        cout << "flight not found";
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
