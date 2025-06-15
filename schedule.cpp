#include<iostream>
using namespace std;
#include"schedule.h"
Schedule::Schedule() : day(0), depart_time("12:00") {}
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
Mystring Schedule::get_departure_time() {
return depart_time;
    }
 void Schedule::save(fstream& f) {
     
     int l = depart_time.length();
     f.write((char*)&l, sizeof(l));
     f.write((const char*)depart_time, l);

}
 void Schedule::load(fstream& f) {
         
       int l;
      f.read((char*)&l, sizeof(l));
        char* temp = new char[l + 1];
        f.read(temp, l);
         temp[l] = '\0';
         delete[] temp;
     }



