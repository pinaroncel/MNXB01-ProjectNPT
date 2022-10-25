
// Record.cxx

#include <iostream>
#include <string>

#include "Record.h"

using namespace std;

Record::Record(string dateTime, double temperature) {
    _dateTime = dateTime;
    _temperature = temperature;
}

void Record::print() const {
    cout << "Date(" << Record::dateTime() << ") Temperature(" << Record::temperature() << " °C)" << endl;
}
