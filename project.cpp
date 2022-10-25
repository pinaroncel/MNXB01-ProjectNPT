
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
vector<double> tempOnDay(vector<Record> records, int month, int day) {
    vector<double> temps;
    for (auto record : records) {
        if (record.month() == month && record.day() == day) { temps.push_back(record.temp()); }
    }
    return temps;
}

vector<int> getAllYears(vector<Record> records) {
    vector<int> allYears;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int thisYear = initialYear; thisYear < finalYear+1; thisYear++) {
        allYears.push_back(thisYear);
    }
    return allYears;
}

vector<double> aveTempsPerYear(vector<Record> records) {
    vector<double> allMeans;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int thisYear = initialYear; thisYear < finalYear+1; thisYear++) {
        double thisSum = 0;
        int nbrDays = 0;
        for (auto record : records) {
            if (thisYear == record.year()) {
                thisSum += record.temp();
                nbrDays++;
            }
        }
        double thisMean = thisSum / nbrDays;       
        allMeans.push_back(thisMean);
    }
    return allMeans;
}

vector<double> minTempsPerYear(vector<Record> records) {
    vector<double> allMins;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int thisYear = initialYear; thisYear < finalYear+1; thisYear++) {
        double thisMin = 0;
        for (auto record : records) {
            if (thisYear == record.year()) {
                if (record.temp() < thisMin) {
                    thisMin = record.temp();
                }
            }
        }
        allMins.push_back(thisMin);
    }
    return allMins;
}

vector<double> maxTempsPerYear(vector<Record> records) {
    vector<double> allMaxs;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int thisYear = initialYear; thisYear < finalYear+1; thisYear++) {
        double thisMax = 0;
        for (auto record : records) {
            if (thisYear == record.year()) {
                if (record.temp() > thisMax) {
                    thisMax = record.temp();
                }
            }
        }
        allMaxs.push_back(thisMax);
    }
    return allMaxs;
}

vector<double> diffTempsPerYear(vector<Record> records) {
    vector<double> allDiffs;
    int initialYear = records.front().year();
    int finalYear   = records.back().year();
    for (int thisYear = initialYear; thisYear < finalYear+1; thisYear++) {
        double thisMin = 0;
        double thisMax = 0;
        for (auto record : records) {
            if (thisYear == record.year()) {
                if (record.temp() < thisMin) {
                    thisMin = record.temp();
                }
                if (record.temp() > thisMax) {
                    thisMax = record.temp();
                }
            }
        }
        double thisDiff = thisMax - thisMin;
        allDiffs.push_back(thisDiff);
    }
    return allDiffs;
}

// ----------------------------------------------------------------
// ----------------------------------------------------------------
int main() {

    vector<Record> records;

	string filename = "in/uppsala_tm_1722-2020.dat";
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

    vector<double> temps = tempOnDay(records, 8, 23);
    vector<int>    years = getAllYears(records);
    vector<double> aveTemps = aveTempsPerYear(records);
    vector<double> minTemps = minTempsPerYear(records);
    vector<double> maxTemps = maxTempsPerYear(records);
    vector<double> diffTemps = diffTempsPerYear(records);

    cout << "TEMPS : "; for (auto temp : temps) {cout << temp << ", "; }; cout << endl; cout << endl;
    cout << "YEARS : "; for (auto year : years) {cout << year << ", "; }; cout << endl; cout << endl;
    cout << "aveTemps : "; for (auto aveTemp : aveTemps) {cout << aveTemp << ", "; }; cout << endl; cout << endl;
    cout << "minTemps : "; for (auto minTemp : minTemps) {cout << minTemp << ", "; }; cout << endl; cout << endl;
    cout << "maxTemps : "; for (auto maxTemp : maxTemps) {cout << maxTemp << ", "; }; cout << endl; cout << endl;
    cout << "diffTemps : "; for (auto diffTemp : diffTemps) {cout << diffTemp << ", "; }; cout << endl; cout << endl;

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
