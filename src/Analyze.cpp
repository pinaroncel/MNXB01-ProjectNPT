
// Analyze.cpp by Pinar

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../include/Analyze.h"
#include "../include/Record.h"

using namespace std;

// Returns a vector of recorded temperatures on the given day
vector<double> tempsOnDay(const vector<Record>& records, int month, int day) {
    vector<double> temps;
    for (auto record : records) {
        if (record.month() == month && record.day() == day) {
            temps.push_back(record.temp());
        }
    }
    cout << "size of temps: " << temps.size() << endl;
    return temps;
}

// Returns the nbr of days of the given month
int nbrDaysPerMonth(int month) {
    if (month == 2) {
        return 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

// Returns a vector of recorded temperatures on every day of the year
vector<vector<double>> tempPerDay(const vector<Record>& records) {
    vector<vector<double>> tempss;
    for (int m = 1; m < 13; m++) {
        int nbrDays = nbrDaysPerMonth(m);
        for (int d = 1; d < nbrDays+1; d++) {
            vector<double> temps = tempsOnDay(records, m, d);
            tempss.push_back(temps);
        }
    }
    cout << "size of tempss: " << tempss.size() << endl;
    return tempss;
}

// Returns a vector of all recorded years
vector<double> getAllYears(const vector<Record>& records) {
    vector<double> years;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        years.push_back(y);
    }
    cout << "size of years: " << years.size() << endl;
    return years;
}

// Returns a vector of average temperatures of every year
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
    cout << "size of means: " << means.size() << endl;
    return means;
}

// Returns a vector of min temperatures of every year = coldest days
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
    cout << "size of mins: " << mins.size() << endl;
    return mins;
}

// Returns a vector of max temperatures of every year = hottest days
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
    cout << "size of maxs: " << maxs.size() << endl;
    return maxs;
}

// Returns a vector of temperature differences of every year = the difference between the hottest and the coldest day of every year
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
    cout << "size of diffs: " << diffs.size() << endl;
    return diffs;
}

// Converts a vector into an array
double* convertVtoA(const vector<double>& vector) {
    cout << "size of vector: " << vector.size() << endl;
    int n = vector.size();
    double array[n];
    copy(vector.begin(), vector.end(), array);
    cout << "size of array: " << n << endl;
    return array;
}
