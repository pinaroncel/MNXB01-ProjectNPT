
// main.cxx
// ----------------------------------------------------------------
// ----------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>

// #include "inc/Analyze.h"
// #include "inc/Plot.h"
// #include "inc/Read.h"
// #include "inc/Record.h"

#include "src/Analyze.cxx"
#include "src/Plot.cxx"
#include "src/Read.cxx"
#include "src/Record.cxx"
// ----------------------------------------------------------------
// ----------------------------------------------------------------
using namespace std;
// ----------------------------------------------------------------
// ----------------------------------------------------------------
int main() {
  
    vector<string> files = {"file1.dat", "file2.dat", "file3.dat"};
    
    for (auto file : files) {
  
        cout << " ... starting projectNPT ... " << endl;

        // Read data from a single file

        // Analyze data that has been read in -> Model 1

        // Plot data that has been analyzed -> Model 1

        // Analyze data that has been read in -> Model 2

        // Plot data that has been analyzed -> Model 2

        // Analyze data that has been read in -> Model 3

        // Plot data that has been analyzed -> Model 3

        cout << " ... ending projectNPT ... " << endl;
    }
    
    return 0;
}
// ----------------------------------------------------------------
// ----------------------------------------------------------------
