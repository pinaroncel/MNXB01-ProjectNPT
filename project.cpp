
// project.cpp
#include <iostream>
#include <string>
#include <vector>

#include "Record.h"
#include "Read.h"
#include "Analyze.h"
#include "Plot.h"

using namespace std;

int main() {

	string filename = "in/uppsala_tm_1722-2020.dat";

    vector<Record> records   = readFromFile(filename);

    vector<double> temps     = tempOnDay(records, 12, 24);
    vector<int>    years     = getAllYears(records);
    vector<double> aveTemps  = aveTempsPerYear(records);
    vector<double> minTemps  = minTempsPerYear(records);
    vector<double> maxTemps  = maxTempsPerYear(records);
    vector<double> diffTemps = diffTempsPerYear(records);
    vector<vector<double>> tempss = tempPerDay(records);

    make_graph(years, temps);
    make_graph(years, aveTemps);
    make_graph_min_max(years, minTemps, maxTemps, diffTemps);

    return 0;
}
