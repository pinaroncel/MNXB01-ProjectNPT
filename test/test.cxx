
// test.cxx

#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s1 = "1863-01-20;13:00:00;3.7;G";
    string s2 = "1863-01-21;20:00:00;2.1;G";
    string s3 = "1863-01-22;07:00:00;0.5;G";
    string s4 = "1863-01-23;20:00:00;6.7;G";
    string s5 = "1863-01-24;13:00:00;2.7;G";
    string s6 = "1863-01-25;07:00:00;3.6;G";
    string s7 = "1863-01-26;20:00:00;4.9;G";
    string s8 = "1863-01-27;13:00:00;6.0;G";

    vector<string> ss = {s1, s2, s3, s4, s5, s6, s7, s8};

    for (auto s : ss) {

        cout << s << endl;

    }

    return 0;

}
