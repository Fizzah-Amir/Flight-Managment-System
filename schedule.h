#pragma once
#include"Mystring.h"
class Schedule {
    int day;
    Mystring depart_time;
public:
    Schedule() : day(0), depart_time("00:00") {}
   Schedule(int day, Mystring t) : day(day), depart_time(t) {}
    void setDay(int d);
    void setDepartureTime(Mystring t);
    int getDay();
    Mystring getDepartureTime();
};

