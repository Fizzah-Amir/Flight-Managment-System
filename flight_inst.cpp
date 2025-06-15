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
    void FlightInstance::reserveSeat() {
        reserve_seat++;   
    }
    void FlightInstance::unreserveSeat() {
        if (reserve_seat > 0) {
            reserve_seat--;
        }
    }
    int FlightInstance::getReservedSeats()  {
        return reserve_seat;
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
  void Reservation::save(fstream &f) {
     
      
      int l = passen_name.length();
      f.write((char*) & l, sizeof(l));
      f.write((const char*)passen_name, l);
      f.write((char*)&r_Id, sizeof(r_Id));
      f.write((char*)&flightId, sizeof(flightId));
  }
  void Reservation::load(fstream& f) {
      int l = passen_name.length();
      f.read((char*)&l, sizeof(l));
      char* temp = new char[l + 1];
      f.read(temp, l);
      temp[l] = '\0';
      delete[] temp;
      f.read((char*)&r_Id, sizeof(r_Id));
      f.read((char*)&flightId, sizeof(flightId));
  }
       
          
