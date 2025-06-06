#pragma once
#ifndef FLIGHT_H
#define FLIGHT_H
class Flight{
int flightID;
Mystring flightNo;
Mystring departureCity;
Mystring arrivalCity;
int duration;
Myvector<WeeklySchedule> schedules;
Myvector<FlightInstance> instances;
}
#endif
