
// project.cpp

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "include/Analyze.h"
#include "include/Plot.h"
#include "include/Read.h"
#include "include/Record.h"

using namespace std;

void project() {

// -----------------------------------------------------------------------------
// STEP 0 : program start
// -----------------------------------------------------------------------------
    cout << " ... starting ProjectNPT ... " << endl;

// -----------------------------------------------------------------------------
/* STEP 1 : READ -> by Nikolei
 * read from file and store data in a vector of Record objects */
// -----------------------------------------------------------------------------
    string filename = "in/uppsala_tm_1722-2020.dat";

    vector<Record> records = readFromFile(filename);

// -----------------------------------------------------------------------------
/* STEP 2 : ANALYZE -> by Pinar
 * analyze data and create vectors to be used in plotting */
// -----------------------------------------------------------------------------
    vector<double> temps     = tempsOnDay(records, 12, 25);
    vector<double> years     = getAllYears(records);
    vector<double> aveTemps  = aveTempsPerYear(records);
    vector<double> minTemps  = minTempsPerYear(records);
    vector<double> maxTemps  = maxTempsPerYear(records);
    vector<double> diffTemps = diffTempsPerYear(records);
    vector<vector<double>> tempss = tempsPerDay(records);

// -----------------------------------------------------------------------------
/* STEP 3 : PLOT -> by Tilde
 * plot and save graphs using the processed data */
// -----------------------------------------------------------------------------
    make_graph_day(years, temps);
    make_graph_ave(years, aveTemps);
    make_graph_min_max_diff(years, minTemps, maxTemps, diffTemps);

// -----------------------------------------------------------------------------
    // STEP 4 : program end
// -----------------------------------------------------------------------------
    cout << " ... ending ProjectNPT ... " << endl;
}
