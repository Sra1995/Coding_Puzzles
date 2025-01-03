# Divisible Sum Pairs - Explanation

## Problem Overview
Given an array `ar` of integers and an integer `k`, determine the number of pairs `(i, j)` such that:
1. \( i < j \)
2. \( (ar[i] + ar[j]) \% k = 0 \)

## Iteration Walkthrough

### Initial Setup
- Input: `ar = [1, 3, 2, 6, 1, 2]`, `k = 3`
- Initialize:
  - `remainder_count = [0, 0, 0]` (stores the frequency of remainders).
  - `count = 0` (tracks the total number of valid pairs).

### Iterations
| Iteration | Current Number | Remainder | Complement | Pairs Found | Count | Remainder Count                |
|-----------|----------------|-----------|------------|-------------|-------|--------------------------------|
| 1         | 1              | 1         | 2          | 0           | 0     | [0, 1, 0]                     |
| 2         | 3              | 0         | 0          | 0           | 0     | [1, 1, 0]                     |
| 3         | 2              | 2         | 1          | 1           | 1     | [1, 1, 1]                     |
| 4         | 6              | 0         | 0          | 1           | 2     | [2, 1, 1]                     |
| 5         | 1              | 1         | 2          | 1           | 3     | [2, 2, 1]                     |
| 6         | 2              | 2         | 1          | 2           | 5     | [2, 2, 2]                     |

### Final Output
- Total Pairs: `5`

---

## Optimization
The solution uses an \( O(n) \) approach with the following optimizations:
1. Uses a remainder array to store counts of elements modulo \( k \).
2. Complements are calculated directly, reducing redundant iterations.

---

## Example Usage
Given `ar = [1, 3, 2, 6, 1, 2]` and `k = 3`, the output is `5` as there are five valid pairs.
