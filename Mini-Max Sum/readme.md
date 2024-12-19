# Plus-Minus Problem: Minimum and Maximum Sums

## Problem Statement
Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers. Then print the respective minimum and maximum values as a single line of two space-separated integers.

### Example
For the input array `arr = [1, 3, 5, 7, 9]`, the function should compute:
- The sum of the four smallest integers for the minimum sum.
- The sum of the four largest integers for the maximum sum.

### Input:
An array of exactly five positive integers.

### Output:
Two space-separated long integers:
1. The minimum sum of four integers.
2. The maximum sum of four integers.

### Example:
For `arr = [1, 3, 5, 7, 9]`, the output should be:
```
16 24
```
Where:
- 16 is the minimum sum (1 + 5 + 7 + 9).
- 24 is the maximum sum (5 + 7 + 9 + 13).

---

## Solution

### Languages:
This solution is implemented in Python and C++, with plans to implement it in C# later.

### Python Implementation:
In Python, we can solve the problem by:
1. Summing all the numbers in the list.
2. Finding the maximum and minimum values and subtracting them from the total sum.

The time complexity of this solution is O(n), where `n` is the size of the array.

### C++ Implementation:
In C++, the solution follows a similar approach:
1. Calculate the total sum of the array.
2. Find the minimum and maximum values.
3. Subtract the minimum value for the maximum sum and the maximum value for the minimum sum.

### C# Implementation (Coming Soon):
In C#, the solution follows a similar approach:
1. Calculate the total sum of the array.
2. Find the minimum and maximum values.
3. Subtract the minimum value for the maximum sum and the maximum value for the minimum sum.



---

## License

This repository is licensed under the MIT License.

---

Feel free to modify this template based on your project and future plans. Let me know if you need further adjustments!
