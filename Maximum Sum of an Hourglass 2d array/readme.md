
# Maximum Sum of an Hourglass

## Problem Statement

You are given an `m x n` integer matrix `grid`.

An **hourglass** is defined as a part of the matrix with the following structure:

```
a b c
  d
e f g
```

The goal is to find the **maximum sum** of the elements of any hourglass in the matrix. Note that an hourglass cannot be rotated and must fit entirely within the matrix.

### Constraints
- `m == grid.length`
- `n == grid[i].length`
- `3 <= m, n <= 150`
- `0 <= grid[i][j] <= 10^6`

---

## Examples

### Example 1
**Input:**
```plaintext
grid = [[6,2,1,3],
        [4,2,1,5],
        [9,2,8,7],
        [4,1,2,9]]
```

**Output:** 
```plaintext
30
```

**Explanation:** 
The hourglass with the maximum sum is:
```
6 2 1
  2
9 2 8
```
The sum is `6 + 2 + 1 + 2 + 9 + 2 + 8 = 30`.

---

### Example 2
**Input:**
```plaintext
grid = [[1,2,3],
        [4,5,6],
        [7,8,9]]
```

**Output:** 
```plaintext
35
```

**Explanation:** 
There is only one hourglass in the matrix:
```
1 2 3
  5
7 8 9
```
The sum is `1 + 2 + 3 + 5 + 7 + 8 + 9 = 35`.

---

## Algorithm Explanation

### Approach
1. **Iterate Through the Grid:** 
   - Use two nested loops to traverse all possible top-left corners of hourglasses. 
   - The hourglass must be fully contained in the matrix, so the loops iterate up to `rows - 2` and `columns - 2`.

2. **Calculate Hourglass Sum:**
   - For each valid top-left corner `(i, j)`, compute the sum of the hourglass:
     - Top row: `grid[i][j] + grid[i][j+1] + grid[i][j+2]`
     - Middle element: `grid[i+1][j+1]`
     - Bottom row: `grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]`

3. **Update Maximum Sum:**
   - Compare the current hourglass sum with the maximum sum found so far and update accordingly.

4. **Return the Maximum Sum:**
   - After iterating through all possible hourglasses, return the maximum sum.

---

### C++ Solution
```cpp
class Solution {
public:
    int maxSum(vector<vector<int>>& arr) {
        int max_sum = INT_MIN;
        int rows = arr.size();
        int columns = arr[0].size();

        for (int i = 0; i < rows - 2; ++i) {
            for (int j = 0; j < columns - 2; ++j) {
                int sum = (arr[i][j] + arr[i][j+1] + arr[i][j+2]) + 
                          (arr[i+1][j+1]) + 
                          (arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2]);
                max_sum = max(max_sum, sum);
            }
        }
        return max_sum;
    }
};
```

---

### Python Solution
```python
class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        max_sum = -999999

        rows = len(grid)
        columns = len(grid[0])

        for i in range(rows - 2):
            for j in range(columns - 2):
                SUM = (grid[i][j] + grid[i][j+1] + grid[i][j+2]) + \
                      (grid[i+1][j+1]) + \
                      (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2])
                if SUM > max_sum:
                    max_sum = SUM

        return max_sum
```

---

## Complexity Analysis

### Time Complexity
- **C++ and Python solutions:** `O(m * n)`
  - Outer loop iterates through `m-2` rows.
  - Inner loop iterates through `n-2` columns.
  - Calculating the sum of one hourglass involves a constant number of operations (`O(1)`).
  - Therefore, the total complexity is proportional to the size of the grid.

### Space Complexity
- **C++ and Python solutions:** `O(1)`
  - Only a few integer variables are used (`max_sum`, `sum`, etc.).
  - No additional space is required proportional to the input size.

---

## Why This Algorithm Works
The algorithm directly computes the sum for every possible hourglass in the matrix, ensuring that all configurations are checked. By maintaining a running maximum, it efficiently finds the maximum hourglass sum in a single pass through all valid hourglass positions. You can also change the shape from hourglass for instead to X or A and you would only need to adjust the indexs for the sum in the inner loop.
```
