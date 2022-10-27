
#include <iostream>
#include <string>
#include <vector>

#include "include/Analyze.h"
#include "include/Plot.h"
#include "include/Read.h"
#include "include/Record.h"

using namespace std;

int main() {

    cout << " ... starting ProjectNPT ... " << endl;

	string filename = "in/uppsala_tm_1722-2020.dat";

    vector<Record> records   = readFromFile(filename);

    vector<double> temps     = tempsOnDay(records, 12, 24);
    vector<double> years     = getAllYears(records);
    vector<double> aveTemps  = aveTempsPerYear(records);
    vector<double> minTemps  = minTempsPerYear(records);
    vector<double> maxTemps  = maxTempsPerYear(records);
    vector<double> diffTemps = diffTempsPerYear(records);
    vector<vector<double>> tempss = tempPerDay(records);

    // double* tempsArray     = convertVtoA(temps);
    // double* yearsArray     = convertVtoA(years);
    // double* aveTempsArray  = convertVtoA(aveTemps);
    // double* minTempsArray  = convertVtoA(minTemps);
    // double* maxTempsArray  = convertVtoA(maxTemps);
    // double* diffTempsArray = convertVtoA(diffTemps);

    make_graph_day(years, temps);
    make_graph_ave(years, aveTemps);
    make_graph_min_max_diff(years, minTemps, maxTemps, diffTemps);

    cout << " ... ending ProjectNPT ... " << endl;
    return 0;
}
