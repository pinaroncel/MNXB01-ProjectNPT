
// Read.cpp by Nikolei

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../include/Record.h"

// Returns a vector of Record objects storing the data from the input file
std::vector<Record> readFromFile(std::string filename) {
    std::vector<Record> records;
    std::ifstream input(filename);

	// Check if file is opened:
	if (!input) {
		throw std::runtime_error{"The file: " + filename + "could not be opened!"};
	}

    std::string line{};
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
    
    std::cout << "size of records: " << records.size() << endl;
    return records;
}
