#pragma once
#include "Myvector.h"
#include "Mystring.h"
#include"flight_inst.h"
#include "schedule.h"
#include "Logger.h"
#include "Reservation.h"
class Flight {
    int flightId;
    Mystring flightNumber;
    Mystring from;
       Mystring to;
    int duration;
    MyVector<Schedule> schedules;
  MyVector<FlightInstance> instances;
public:
    Flight(int id,Mystring num, Mystring dep,  Mystring arr, int dur) : flightId(id), flightNumber(num), from(dep), to(arr), duration(dur) {};
    Mystring getFlightNumber();
      int getFlightId();
      MyVector<FlightInstance>& get_instances();
      void addSchedule(const Schedule& s);
       void addInstance(const FlightInstance& fi);
      void print()const;
      Mystring get_from_city()const;
      Mystring get_to_city()const;
      static void show_schedule(const MyVector<Flight>& flights, MyVector<Reservation>& reservations);
       static void bookTicket(MyVector<Flight>&flights, MyVector<Reservation>&reservations);
       static void searchFlights(MyVector<Flight>&flights);
        static void update_schedule(MyVector<Flight>&flights);
    void save(fstream &f);
    void load(fstream &f);
};
