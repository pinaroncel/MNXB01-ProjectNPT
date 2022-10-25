
// Record.h
// ----------------------------------------------------------------
#ifndef RECORD_H
#define RECORD_H

using namespace std;
// ----------------------------------------------------------------
class Record {

    private:

        int    _year;
        int    _month;
        int    _day;
        double _temp;
        double _tempUrban;
        int    _dataId;

    public:

        Record(
            const int    year,
            const int    month,
            const int    day,
            const double temp,
            const double tempUrban,
            const int    dataId
        );

        int    year()      const {return _year;}
        int    month()     const {return _month;}
        int    day()       const {return _day;}
        double temp()      const {return _temp;}
        double tempUrban() const {return _tempUrban;}
        int    dataId()    const {return _dataId;}

        void print() const;
};
// ----------------------------------------------------------------
#endif // RECORD_H
// ----------------------------------------------------------------