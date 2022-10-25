
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
    const string pathToFile = "/in/uppsala_tm_1722-2020.dat";

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
