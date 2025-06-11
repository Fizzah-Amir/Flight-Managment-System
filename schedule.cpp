#include<iostream>
using namespace std;
#include"schedule.h"
Schedule::Schedule() : day(0), depart_time("00:00") {}
Schedule::Schedule(int day,  Mystring t) : day(day), depart_time(t) {}
void Schedule::setDay(int d) { 
        day= d; 
    }
void Schedule::setDepartureTime(Mystring t) {
        depart_time = t;
    }
 int Schedule::getDay(){
        return day;
    }
  Mystring Schedule::getDepartureTime() {
        return depart_time;
    }
