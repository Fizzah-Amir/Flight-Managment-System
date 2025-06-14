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
};
