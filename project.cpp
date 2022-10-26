
// project.cpp
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Record.h"
using namespace std;
// ----------------------------------------------------------------
// ----------------------------------------------------------------
// move this function later...
vector<Record> readFromFile(string filename) {
    vector<Record> records;
    ifstream input(filename);
    string line;
    while(getline(input, line)) {
        int    year      = stoi(line.substr(0, 4));
        int    month     = stoi(line.substr(5, 3));
        int    day       = stoi(line.substr(8, 3));
        double temp      = stod(line.substr(11, 6));
        double tempUrban = stod(line.substr(17, 6));
        int    dataId    = stoi(line.substr(23, 2));
        Record record = Record(year, month, day, temp, tempUrban, dataId);
        records.push_back(record);
    }
    return records;
}
// move this function later...
vector<double> tempOnDay(vector<Record> records, int month, int day) {
    vector<double> temps;
    for (auto record : records) {
        if (record.month() == month && record.day() == day) { temps.push_back(record.temp()); }
    }
    return temps;
}

// move this function later...
vector<int> getAllYears(vector<Record> records) {
    vector<int> years;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int y = initialYear; y < finalYear+1; y++) {
        years.push_back(y);
    }
    return years;
}

// move this function later...
vector<double> aveTempsPerYear(vector<Record> records) {
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
vector<double> minTempsPerYear(vector<Record> records) {
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
vector<double> maxTempsPerYear(vector<Record> records) {
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
vector<double> diffTempsPerYear(vector<Record> records) {
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
        double thisDiff = max - min;
        diffs.push_back(thisDiff);
    }
    return diffs;
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
int main() {

	string filename = "in/uppsala_tm_1722-2020.dat";

    vector<Record> records   = readFromFile(filename);
    vector<double> temps     = tempOnDay(records, 8, 23);
    vector<int>    years     = getAllYears(records);
    vector<double> aveTemps  = aveTempsPerYear(records);
    vector<double> minTemps  = minTempsPerYear(records);
    vector<double> maxTemps  = maxTempsPerYear(records);
    vector<double> diffTemps = diffTempsPerYear(records);

    cout << endl;
    cout << "nbr of records : " << records.size() << endl;
    cout << endl;

    cout << "temps on a single day : " << endl;
    for (auto temp : temps) {cout << temp << ", "; };
    cout << endl; cout << endl;

    cout << "years : " << endl;
    for (auto year : years) {cout << year << ", "; };
    cout << endl; cout << endl;

    cout << "ave temps : " << endl;
    for (auto aveTemp : aveTemps) {cout << aveTemp << ", "; };
    cout << endl; cout << endl;

    cout << "min temps : " << endl;
    for (auto minTemp : minTemps) {cout << minTemp << ", "; };
    cout << endl; cout << endl;

    cout << "max temps : " << endl;
    for (auto maxTemp : maxTemps) {cout << maxTemp << ", "; };
    cout << endl; cout << endl;

    cout << "diff temps : " << endl;
    for (auto diffTemp : diffTemps) {cout << diffTemp << ", "; };
    cout << endl; cout << endl;

    return 0;

	// Store the path to data file here
    // const string pathToFile = "/in/uppsala_tm_1722-2020.dat";

	// Instantiate analysis object
    // tempTrender t(pathToFile);

	//t.tempOnDay(8, 23);
	//t.tempOnDay(235);
	//t.tempPerDay();
	//t.hotCold();
	//t.tempPerYear(2050);
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
