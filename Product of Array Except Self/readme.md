
# Product of Array Except Self

## Problem Description
Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

### Constraints:
- The product of any prefix or suffix of `nums` is guaranteed to fit in a 32-bit integer.
- You must write an algorithm that runs in **O(n)** time and **without using the division operation**.

### Example 1:
**Input:** `nums = [1, 2, 3, 4]`  
**Output:** `[24, 12, 8, 6]`

### Example 2:
**Input:** `nums = [-1, 1, 0, -3, 3]`  
**Output:** `[0, 0, 9, 0, 0]`

### Additional Requirements:
- **Constraints:** `2 <= nums.length <= 10^5`, `-30 <= nums[i] <= 30`.
- **Follow-up Challenge:** Solve the problem in O(1) extra space complexity. (The output array does not count as extra space for space complexity analysis.)

---

## Solution in C++
Below is my solution to the problem using C++. This approach involves constructing prefix (`left_product`) and suffix (`right_product`) arrays and combining them to compute the result. The solution achieves **O(n)** time complexity.

### Code:
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> left_product(n);
        vector<int> right_product(n);

        // Initialize the leftmost and rightmost products
        left_product[0] = 1;
        right_product[n-1] = 1;

        // Compute prefix products
        for (int i = 1; i < n; i++) {
            left_product[i] = left_product[i-1] * nums[i-1];
        }

        // Compute suffix products
        for (int j = n-2; j >= 0; j--) {
            right_product[j] = right_product[j+1] * nums[j+1];
        }

        // Compute the result by multiplying prefix and suffix products
        for (int i = 0; i < n; i++) {
            answer[i] = left_product[i] * right_product[i];
        }

        return answer;
    }
};
```

---

## How It Works
1. **Prefix Product Array:**  
   The `left_product` array is built such that each element at index `i` contains the product of all elements to the left of `nums[i]`.

2. **Suffix Product Array:**  
   The `right_product` array is built such that each element at index `i` contains the product of all elements to the right of `nums[i]`.

3. **Combining Prefix and Suffix Products:**  
   The result is calculated by multiplying corresponding elements from `left_product` and `right_product`.

---

## Complexity Analysis
- **Time Complexity:** `O(n)`  
  The algorithm traverses the array three times: once for the prefix product, once for the suffix product, and once for the result computation.

- **Space Complexity:** `O(n)`  
  This implementation uses three arrays: `left_product`, `right_product`, and `answer`.

