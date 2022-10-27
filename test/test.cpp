
#include <algorithm>
#include <iostream>
#include <vector>
 
using namespace std;

int main() {

    vector<int> vector({ 1, 2, 3, 4, 5 });

    cout << "vector : " << endl;
    for (auto element : vector) {
        cout << element << ", ";
    }
    cout << endl;

    int n = vector.size();

    int array[n];

    std::copy(vector.begin(), vector.end(), array);
 
    cout << "array : " << endl;
    for (auto element : array) {
        cout << element << ", ";
    }
    cout << endl;
 
    return 0;
}