
// Record.cpp by Nikolei

#include <iostream>

#include "../include/Record.h"

using namespace std;

Record::Record(
            int    year,
            int    month,
            int    day,
            double temp,
            double tempUrban,
            int    dataId) {
            
            _year      = year;
            _month     = month;
            _day       = day;
            _temp      = temp;
            _tempUrban = tempUrban;
            _dataId    = dataId;
            }

void Record::print() const {
    cout << year()      << "\t"
         << month()     << "\t"
         << day()       << "\t"
         << temp()      << "\t" 
         << tempUrban() << "\t" 
         << dataId()    << endl;
}
