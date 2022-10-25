
// Record.h
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#ifndef RECORD_H
#define RECORD_H

using namespace std;
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// Class definition for Record
class Record {

    private:

        int    _year;
        int    _month;
        int    _day;
        double _temp;
        double _tempUrban;
        int    _dataId;

    public:

        // Constructor function -> Creates a new instance
        Record(
            int    year,
            int    month,
            int    day,
            double temp,
            double tempUrban,
            int    dataId
        );

        // Getter functions -> Returns attributes
        int    year()      const {return _year;}
        int    month()     const {return _month;}
        int    day()       const {return _day;}
        double temp()      const {return _temp;}
        double tempUrban() const {return _tempUrban;}
        int    dataId()    const {return _dataId;}

        // Prints data stored in this object
        void print() const;
};
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#endif // RECORD_H
// ----------------------------------------------------------------
// ----------------------------------------------------------------
