
// Analyze.h by Pinar

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "Record.h"

// -----------------------------------------------------------------------------
// Returns a vector of recorded temperatures on the given day
vector<double> tempsOnDay(const vector<Record>& records, int month, int day);

// -----------------------------------------------------------------------------
// Returns the nbr of days of the given month
int nbrDaysPerMonth(int month);

// -----------------------------------------------------------------------------
// Returns a vector of recorded temperatures on every day of the year
vector<vector<double>> tempsPerDay(const vector<Record>& records);

// -----------------------------------------------------------------------------
// Returns a vector of all recorded years
vector<double> getAllYears(const vector<Record>& records);

// -----------------------------------------------------------------------------
// Returns a vector of average temperatures of every year
vector<double> aveTempsPerYear(const vector<Record>& records);

// -----------------------------------------------------------------------------
// Returns a vector of min temperatures of every year = coldest days
vector<double> minTempsPerYear(const vector<Record>& records);

// -----------------------------------------------------------------------------
// Returns a vector of max temperatures of every year = hottest days
vector<double> maxTempsPerYear(const vector<Record>& records);

// -----------------------------------------------------------------------------
// Returns a vector of temperature differences of every year = the difference between the hottest and the coldest day of every year
vector<double> diffTempsPerYear(const vector<Record>& records);

// -----------------------------------------------------------------------------
// Converts a vector into an array
// double* convertVtoA(const vector<double>& vector);
