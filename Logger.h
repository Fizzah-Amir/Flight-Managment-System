#pragma once
#include<iostream>
#include<fstream>
#include"Mystring.h"
using namespace std;
class Logger {
	ofstream file;
	Logger();
public:
  Logger(const Logger&) = delete;
  Logger& operator=(const Logger&) = delete;
  static Logger& getInstance();
  void initialize(const char* name);
  void cleanup();
  void log(const Mystring& msg);
};
