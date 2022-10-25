
// Record.h

#ifndef RECORD_H
#define RECORD_H

#include <string>

using namespace std;

class Record {

    private:

        string _dateTime;
        double _temperature;

    public:

        Record(const string dateTime, const double temperature);
        string dateTime() const { return _dateTime; }
        double temperature() const { return _temperature; }
        void print() const;
};

#endif // RECORD_H
