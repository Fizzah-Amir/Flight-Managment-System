#pragma once
#include"Mystring.h"
class Schedule {
    int day;
    Mystring depart_time;
public:
Schedule() : day(0), depart_time("12:00") {}
Schedule(int day, Mystring t) : day(day), depart_time(t) {}
void setDay(int d);
 void setDepartureTime(const Mystring &t);
int getDay();
Mystring get_departure_time();
};

