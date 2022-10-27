
// Record.cpp by Nikolei

#include <iostream>

#include "../include/Record.h"

using namespace std;

// Class implementation for Record

// Constructor method to instantiate a new Record object
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

// Prints the data stored in the Record object
void Record::print() const {
    cout << "year: "      << year()      << "\t"
         << "month: "     << month()     << "\t"
         << "day: "       << day()       << "\t"
         << "temp: "      << temp()      << "\t" 
         << "tempUrban: " << tempUrban() << "\t" 
         << "dataId: "    << dataId()    << endl;
}
