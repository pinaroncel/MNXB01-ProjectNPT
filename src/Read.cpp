
// Read.cpp by Nikolei

#include <fstream>
#include <string>
#include <vector>

#include "../include/Read.h"
#include "../include/Record.h"

using namespace std;

// Returns a vector of Record objects storing the data from the input file
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
