
#include <iostream>
#include <string>
#include <vector>

#include "Record.h"

// move this function later...
vector<double> tempOnDay(const vector<Record>& records, int month, int day) {
    vector<double> temps;
    for (auto record : records) {
        if (record.month() == month && record.day() == day) {
            temps.push_back(record.temp());
        }
    }
    return temps;
}

// move this function later...
int nbrDaysPerMonth(int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {return 31;}
    if (month == 4 || month == 6 || month == 9 || month == 11) {return 30;}
    else {return 28;}
}

// move this function later...
vector<vector<double>> tempPerDay(const vector<Record>& records) {
    vector<vector<double>> tempss;
    for (int m = 1; m < 13; m++) {
        int nbrDays = nbrDaysPerMonth(m);
        for (int d = 1; d < nbrDays+1; d++) {
            vector<double> temps = tempOnDay(records, m, d);
            tempss.push_back(temps);
        }
    }
    return tempss;
}

// move this function later...
vector<int> getAllYears(const vector<Record>& records) {
    vector<int> years;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        years.push_back(y);
    }
    return years;
}

// move this function later...
vector<double> aveTempsPerYear(const vector<Record>& records) {
    vector<double> means;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double sum = 0;
        int nbrDays = 0;
        for (auto record : records) {
            if (y == record.year()) {
                sum += record.temp();
                nbrDays++;
            }
        }
        double mean = sum / nbrDays;       
        means.push_back(mean);
    }
    return means;
}

// move this function later...
vector<double> minTempsPerYear(const vector<Record>& records) {
    vector<double> mins;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double min = 0;
        for (auto record : records) {
            if (y == record.year()) {
                if (record.temp() < min) {
                    min = record.temp();
                }
            }
        }
        mins.push_back(min);
    }
    return mins;
}

// move this function later...
vector<double> maxTempsPerYear(const vector<Record>& records) {
    vector<double> maxs;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double max = 0;
        for (auto record : records) {
            if (y == record.year()) {
                if (record.temp() > max) {
                    max = record.temp();
                }
            }
        }
        maxs.push_back(max);
    }
    return maxs;
}

// move this function later...
vector<double> diffTempsPerYear(const vector<Record>& records) {
    vector<double> diffs;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        double min = 0;
        double max = 0;
        for (auto record : records) {
            if (y == record.year()) {
                if (record.temp() < min) {
                    min = record.temp();
                }
                if (record.temp() > max) {
                    max = record.temp();
                }
            }
        }
        double diff = max - min;
        diffs.push_back(diff);
    }
    return diffs;
}
