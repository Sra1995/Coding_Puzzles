#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void plusMinus(vector<int> arr) {
    double positives = 0;
    double negatives = 0;
    double zeros = 0;

    for (int num : arr) { // Use int since the array is of type int
        if (num > 0) {
            positives += 1;
        } else if (num < 0) {
            negatives += 1;
        } else {
            zeros += 1;
        }
    }

    // Apply the fixed and setprecision once, and it will work for all outputs
    cout << fixed << setprecision(6);
    cout << positives / arr.size() << endl;
    cout << negatives / arr.size() << endl;
    cout << zeros / arr.size() << endl;
}

int main() {
    vector<int> arr = {-4, 3, -9, 0, 4, 1};

    plusMinus(arr);

    return 0;
}
// I know I can do  the loop in less lines in c++ but I learned C first so its bit of habit :D
