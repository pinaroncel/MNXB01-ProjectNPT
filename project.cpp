
// project.cpp
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <TCanvas.h>
#include <TPad.h>
#include <TFrame.h>
#include <TStyle.h>
#include <TF1.h>
#include <TH1.h>

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
    vector<vector<double>> tempss = tempPerDay(records);

    TGraph  g1 = make_graph_1(years, temps);
    TCanvas c1 = new TCanvas("c1", "canvas for g1");
    g1->Draw();
    c1->SaveAs();


    TGraph  g2 = make_graph_2(years, temps);
    TCanvas c2 = new TCanvas("c2", "canvas for g2");
    g2->Draw();
    c2->SaveAs();

    TGraph  g3 = make_graph_3(years, temps);
    TCanvas c3 = new TCanvas("c3", "canvas for g3");
    g3->Draw();
    c3->SaveAs();

    cout << endl;
    cout << "nbr of records : " << records.size() << endl;
    cout << endl;

    cout << "temps on a single day : " << endl;
    for (auto temp : temps) {cout << temp << ", "; };
    cout << endl; cout << endl;
    cout << "nbr of days in temps : " << temps.size() << endl;
    cout << endl;

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

    cout << "nbr of days in tempss : " << tempss.size() << endl;
    cout << "nbr of temps in a day : " << tempss.back().size() << endl;

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
