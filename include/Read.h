// Read.h by Nikolei
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Record.h"

// Reading the data file input and returns a vector of Record objects
std::vector<Record> readFromFile(std::string filename);
