#pragma once
#include "Mystring.h"
class FlightInstance {
int instanceId;
Mystring date;
bool cancel;
int reserve_seat;
public:
   FlightInstance(int iid, Mystring d) : instanceId(iid), date(d), cancel(false), reserve_seat(0) {}
   int getInstanceID();
   Mystring getDate();
   bool isCancel();
   void cancelled();
   void reserveSeat(int s_n);
   void unreserveSeat(int s_n);
   int getReservedSeats();
   void print_seat();
   bool ava_seat(int i);
   void print();
   FlightInstance(const FlightInstance& other);
    void save(fstream& f);
 void load(fstream& f);
};
