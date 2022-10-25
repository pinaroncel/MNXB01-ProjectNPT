
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
int main() {

    cout << " ... starting projectNPT ... " << endl;

    vector<Record> records;
    cout << "initial size : " << records.size() << endl;

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

    cout << "final size : " << records.size() << endl;

	// Store the path to data file here
    // const string pathToFile = "/in/uppsala_tm_1722-2020.dat";

	// Instantiate analysis object
    // tempTrender t(pathToFile);

	//t.tempOnDay(8, 23);
	//t.tempOnDay(235);
	//t.tempPerDay();
	//t.hotCold();
	//t.tempPerYear(2050);

    cout << " ... ending projectNPT ... " << endl;

    return 0;
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
