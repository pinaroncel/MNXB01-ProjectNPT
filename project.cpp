
// project.cpp
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

#include "Record.h"
#include "Read.h"
#include "Analyze.h"
#include "Plot.h"

using namespace std;
// ----------------------------------------------------------------
// ----------------------------------------------------------------





// ----------------------------------------------------------------
// ----------------------------------------------------------------
int main() {

	string filename = "in/uppsala_tm_1722-2020.dat";

    vector<Record> records   = readFromFile(filename);
    vector<Double_t> temps     = ( vector<Double_t> )tempOnDay(records, 8, 23);
    vector<Double_t> years     = ( vector<Double_t> )getAllYears(records);
    vector<Double_t> aveTemps  = ( vector<Double_t> )aveTempsPerYear(records);
    vector<Double_t> minTemps  = ( vector<Double_t> )minTempsPerYear(records);
    vector<Double_t> maxTemps  = ( vector<Double_t> )maxTempsPerYear(records);
    vector<Double_t> diffTemps = ( vector<Double_t> )diffTempsPerYear(records);
    vector<vector<Double_t>> tempss = ( vector<vector<Double_t>> )tempPerDay(records);

    // TString title1 = "temp on a given day";
    make_graph(years, temps);

    // TString title2 = "ave temp on every day";
    make_graph(years, aveTemps);

    make_graph_min_max(years, minTemps, maxTemps, diffTemps);

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
