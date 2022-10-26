
#include <iostream>
#include <string>
#include <vector>

#include "Analyze.h"
#include "Plot.h"
#include "Read.h"
#include "Record.h"

using namespace std;

int main() {

	string filename = "in/uppsala_tm_1722-2020.dat";

    vector<Record> records   = readFromFile(filename);

    vector<double> temps     = tempOnDay(records, 12, 24);
    vector<double> years     = getAllYears(records);
    vector<double> aveTemps  = aveTempsPerYear(records);
    vector<double> minTemps  = minTempsPerYear(records);
    vector<double> maxTemps  = maxTempsPerYear(records);
    vector<double> diffTemps = diffTempsPerYear(records);

    // vector<vector<double>> tempss = tempPerDay(records);

    double* tempsArray     = convertVtoA(temps);
    double* yearsArray     = convertVtoA(years);
    double* aveTempsArray  = convertVtoA(aveTemps);
    double* minTempsArray  = convertVtoA(minTemps);
    double* maxTempsArray  = convertVtoA(maxTemps);
    double* diffTempsArray = convertVtoA(diffTemps);

    make_graph(yearsArray, tempsArray);
    make_graph(yearsArray, aveTempsArray);
    make_graph_min_max(yearsArray, minTempsArray, maxTempsArray, diffTempsArray);

    return 0;
}
