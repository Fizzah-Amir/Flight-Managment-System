#include <iostream>
using namespace std;
#include"flight_inst.h"
FlightInstance::FlightInstance(const FlightInstance& other) {
  date = other.date;
  instanceId = other.instanceId;
   reserve_seat = other.reserve_seat;
   cancel = other.cancel;
}
    FlightInstance::FlightInstance(int iid,  Mystring d): instanceId(iid), date(d), cancel(false), reserve_seat(0){};
    int FlightInstance::getInstanceID() {
        return instanceId;
    }
    Mystring FlightInstance::getDate() {
        return date;
    }
    bool FlightInstance::isCancel(){ 
        return cancel;
    }
    void FlightInstance::cancelled() {
        cancel = true;
             }
   void FlightInstance::reserveSeat(int s_n) {
      if (seats[s_n] == 0) {
          seats[s_n] =1;
          reserved_seat++;
     }
  }
  void FlightInstance::unreserveSeat(int s_n) {
      if (reserved_seat > 0) {
          if (seats[s_n] == 1) {
              seats[s_n] = 0;
              reserved_seat--;
          }
      }
  }
  FlightInstance::FlightInstance(int iid, const Mystring& d): instanceId(iid), date(d), cancel(false), reserved_seat(0) {};
  void FlightInstance::print_seat() {
      for (int i = 0; i < seats.size(); i++) {
          if (seats[i] == 0) {
              cout << "free";
          }
          else {
              cout << "booked";
          }
      }
  }
  bool FlightInstance::ava_seat(int idx) {
      if (seats[idx] == 0) {
          return true;
      }
      return false;
  }
    void FlightInstance::print() {
        cout << "instance ID" << instanceId << "date" << date;
        if (cancel){
           cout << "cancelled";
        cout << " reservations" << reserveSeat;
    } 
        void Reservation::search_Passenger_name(MyVector<Reservation>& reservations) {
      Mystring n;
      cout << "enter passenger name";
      cin >> n;
      for (int i = 0; i < reservations.size();i++) {
          if (reservations[i].getpassen_name() == n) {
              reservations[i].print();
          }
      }
  }
  void FlightInstance::save(fstream & f) {
      int l = date.length();
      f.write((char*)&l, sizeof(l));
      f.write((const char*)date, l);
      f.write((char*)&instanceId, sizeof(instanceId));
      f.write((char*)&reserved_seat, sizeof(reserved_seat));
}
  void FlightInstance::load(fstream& f) {
      int l = date.length();
      f.read((char*)&l, sizeof(l));
      char* temp = new char[l + 1];
      f.read(temp, l);
      temp[l] = '\0';
      delete[] temp;
      f.read((char*)&instanceId, sizeof(instanceId));
      f.read((char*)&reserved_seat, sizeof(reserved_seat));
  }

