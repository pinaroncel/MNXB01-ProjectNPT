
// Record.cpp
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#include <iostream>

#include "Record.h"

using namespace std;
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// Class implementation for Record

// Constructor function -> Creates a new instance
Record::Record(
            int    year,
            int    month,
            int    day,
            double temp,
            double tempUrban,
            int    dataId
        )
{
        _year      = year;
        _month     = month;
        _day       = day;
        _temp      = temp;
        _tempUrban = tempUrban;
        _dataId    = dataId;
}
// ----------------------------------------------------------------
// Prints data stored in this object
void Record::print() const {
    cout << year()      << "\t"
         << month()     << "\t"
         << day()       << "\t"
         << temp()      << "\t" 
         << tempUrban() << "\t" 
         << dataId()    << endl;
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
