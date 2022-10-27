
// Record.h by Nikolei

#ifndef RECORD_H
#define RECORD_H

using namespace std;

// -----------------------------------------------------------------------------
// Class definition for Record
class Record {

    // Private class members
    private:

        // Class attributes
        int    _year;
        int    _month;
        int    _day;
        double _temp;
        double _tempUrban;
        int    _dataId;

    // Public class members
    public:

        // Constructor method to instantiate a new Record object
        Record(
            int    year,
            int    month,
            int    day,
            double temp,
            double tempUrban,
            int    dataId
        );

        // Getter methods to call class attributes
        int    year()      const {return _year;}
        int    month()     const {return _month;}
        int    day()       const {return _day;}
        double temp()      const {return _temp;}
        double tempUrban() const {return _tempUrban;}
        int    dataId()    const {return _dataId;}

        // Prints the data stored in the Record object
        void print() const;
};
// -----------------------------------------------------------------------------

#endif // RECORD_H
