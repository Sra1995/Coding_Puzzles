#include <iostream>
#include <vector>
using namespace std;

/*
 * Complete the 'divisibleSumPairs' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER k
 *  3. INTEGER_ARRAY ar
 */

int divisibleSumPairs(int n, int k, vector<int> ar) {
    vector<int> remainder_count(k, 0);
    int count = 0;
    
    for (int num : ar)
    {
        int remainder = num % k;
        int complement = (k - remainder) % k;
        
        count += remainder_count[complement];
        remainder_count[remainder]++;
    }
    
    return count;
}

int main() {
    vector<int> ar = {1, 3, 2, 6, 1, 2};
    int k = 3;
    int n = ar.size();
    cout << divisibleSumPairs(n, k, ar) << endl; // Output: 5
    return 0;
}
