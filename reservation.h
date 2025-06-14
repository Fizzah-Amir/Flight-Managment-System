#pragma once
#include"Myvector.h"
#include "Mystring.h"
#include "Logger.h"
#include"Flight.h"
class Reservation {
    int r_Id;
    int flightId;
    int instanceId;
    Mystring passen_name;
public:
    Reservation();
    Reservation(int rid, int fid, int iid, Mystring pname);
    int get_reservation_Id();
    int getFlightId();
    int getInstanceId();
    Mystring getpassen_name();
    void print();
    static void Modify_Cancel_Reservation(MyVector<Flight>flights, MyVector<Reservation>reservations);
    static void search_Passenger_name(MyVector<Reservation>& reservations);
};
        
