#include <iostream>
#include <vector>
#include <algorithm>  // For std::min_element and std::max_element

using namespace std;

void miniMaxSum(vector<int> arr) {
    long long total = 0;
    
    // Sum all elements in the array
    for (int i = 0; i < arr.size(); ++i) {
        total += arr[i];
    }
    
    // Find the minimum and maximum elements using iterators
    auto lowest = min_element(arr.begin(), arr.end());
    auto highest = max_element(arr.begin(), arr.end());
    
    // Calculate the output values
    long long output1 = total - *highest;  // Total minus the maximum element
    long long output2 = total - *lowest;   // Total minus the minimum element
    
    // Print the results
    cout << output1 << " " << output2;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    miniMaxSum(arr);

    return 0;
}

// out put was : 16 24
/*
they were some cases that i initially failed that I couldn't see the input on hackerrank.
However, by changing variable type from int to long long I passed all the cases.

easier and shorter for loop would be like
    for (int num: arr){
        total += num;
    }
    
*/
