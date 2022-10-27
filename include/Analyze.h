
// Analyze.h by Pinar

#include <iostream>
#include <string>
#include <vector>

#include "Record.h"

vector<double> tempOnDay(const vector<Record>& records, int month, int day);

int nbrDaysPerMonth(int month);

vector<vector<double>> tempPerDay(const vector<Record>& records);

vector<double> getAllYears(const vector<Record>& records);

vector<double> aveTempsPerYear(const vector<Record>& records);

vector<double> minTempsPerYear(const vector<Record>& records);

vector<double> maxTempsPerYear(const vector<Record>& records);

vector<double> diffTempsPerYear(const vector<Record>& records);

double* convertVtoA(const vector<double>& vector);
