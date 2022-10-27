
// Analyze.cpp by Pinar

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../include/Record.h"

using namespace std;

vector<double> tempOnDay(const vector<Record>& records, int month, int day) {
    vector<double> temps;
    for (auto record : records) {
        if (record.month() == month && record.day() == day) {
            temps.push_back(record.temp());
        }
    }
    return temps;
}

int nbrDaysPerMonth(int month) {
    if (month == 2) {return 28;}
    else if (month == 4 || month == 6 || month == 9 || month == 11) {return 30;}
    else {return 31;}
}

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

vector<double> getAllYears(const vector<Record>& records) {
    vector<double> years;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        years.push_back(y);
    }
    return years;
}

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

double* convertVtoA(const vector<double>& vector) {
    int n = vector.size();
    double array[n];
    copy(vector.begin(), vector.end(), array);
    return array;
}
