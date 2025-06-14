#pragma once
#include "Person.h"
#include"logger.h"
class Pilot : public Person {
  int assignedFlight[5];
 int assignCount;
public:
    Pilot();
    Pilot( Mystring n, Address a, Mystring e,Mystring p);
    void assignFlight(int flightID);
    void printAssignedFlights();
};
