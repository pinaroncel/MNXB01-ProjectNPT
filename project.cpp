
// project.cpp
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

#include "tempTrender.h"

using namespace std;
// ----------------------------------------------------------------
// ----------------------------------------------------------------
void project() {

    cout << " ... starting projectNPT ... " << endl;

	// Store the path to data file here
    const string pathToFile = "/home/path/to/file/";

	// Instantiate analysis object
    tempTrender t(pathToFile);
	
	//t.tempOnDay(8, 23);

	//t.tempOnDay(235);

	//t.tempPerDay();

	//t.hotCold();

	//t.tempPerYear(2050);

    cout << " ... ending projectNPT ... " << endl;

}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
