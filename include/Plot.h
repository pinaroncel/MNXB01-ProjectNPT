
// Plot.h by Tilde

#include <iostream>
#include <string>
#include <vector>

// Saves a graph of all recorded temperatures on the given day
void make_graph_day(const vector<double>& years, const vector<double>& temps);

// Saves a graph of averages temperatures for every year
void make_graph_ave(const vector<double>& years, const vector<double>& aveTemps);

// Saves a graph of the hottest, the coldest, and the difference between the two for every year
void make_graph_min_max_diff(const vector<double>& years, const vector<double>& minTemps, const vector<double>& maxTemps, const vector<double>& diffTemps);
