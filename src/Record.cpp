
// Record.cpp
// ----------------------------------------------------------------
#include <iostream>

#include "Record.h"

using namespace std;
// ----------------------------------------------------------------
Record::Record(
            const int    year,
            const int    month,
            const int    day,
            const double temp,
            const double tempUrban,
            const int    dataId
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
void Record::print() const {
    cout << year()      << "\t"
         << month()     << "\t"
         << day()       << "\t"
         << temp()      << "°C\t" 
         << tempUrban() << "°C\t" 
         << dataId()    << endl;
}
// ----------------------------------------------------------------