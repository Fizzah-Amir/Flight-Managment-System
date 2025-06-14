#include <ctime>
#include"Logger.h"
#include <iomanip>
Logger::Logger() {};
Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}
void Logger::initialize(const char* filename) {
    file.open(filename, ios::app);
 if (!file.is_open()) {
    cout << "could not open";
    }
}
void Logger::cleanup() {
if (file.is_open()) {}
    file.close();
}
void Logger::log(const char* msg) {
    if (rdr.is_open()) {
    time_t now = time(0);
    tm* tm_now = localtime(&now);
    rdr << put_time(tm_now, "%Y-%m-%d %H:%M:%S") << msg;
      cout << endl;
    }
}
