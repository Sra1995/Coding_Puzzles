# Solution to Sum of Multiples of 3 and 5

This repository contains a solution to the problem of summing all numbers below a given number `n` that are multiples of either 3 or 5. The goal is to calculate the sum efficiently, especially when the value of `n` can be very large (up to \( 10^9 \)).

## Problem Statement

Given a number `n`, find the sum of all multiples of 3 and 5 below `n`. The sum should exclude duplicates (i.e., multiples of both 3 and 5, such as 15).

## Approach

### Initial Approach

The initial solution used a simple brute force approach to iterate over all integers below `n` and check whether each number is divisible by 3 or 5. If so, it was added to a cumulative sum.

```cpp
int SumNAT(int a) {
    int sum = 0;
    for (int i = 1; i < a; ++i) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}
```

This approach works correctly but becomes inefficient for large values of `n`. The time complexity of this approach is \( O(n) \), which can lead to timeouts for very large inputs (e.g., \( n \approx 10^9 \)).

### Optimization Attempt with a Hash Set

To improve efficiency, I attempted to use a hash set (`unordered_set`) to store multiples of 3 and 5. This would allow me to check for duplicates more efficiently and reduce the number of unnecessary additions.

```cpp
unsigned int SumNAT(int a) {
    unsigned int sum = 0;
    unordered_set<int> unique_multiples;

    for (int i = 3; i < a; i += 3) {
        sum += i;
        unique_multiples.insert(i);
    }

    for (int i = 5; i < a; i += 5) {
        if (unique_multiples.find(i) == unique_multiples.end()) {
            sum += i;
        }
    }
    return sum;
}
```

While this approach is better than brute force, it still uses two loops and a hash set, leading to \( O(n) \) time complexity. This was still too slow for larger inputs and added unnecessary complexity.

### Final Optimized Solution with Arithmetic Progression Formula

The final, optimized solution leverages the arithmetic progression sum formula to calculate the sum of multiples of 3, 5, and their common multiple 15 (to avoid double-counting). The formula for the sum of multiples of `k` below `n` is:

The sum of multiples of k below n is given by:

Sum of multiples of k = k * (p * (p + 1)) / 2

Where p = floor((n - 1) / k) is the number of multiples of k below n.

![formula in picture format form cuemath](https://d138zd1ktt9iqe.cloudfront.net/media/seo_landing_files/jayshree-sum-of-natural-numbers-formula-1623053562.png)



This allows for a time complexity of \( O(1) \), making the solution extremely efficient for large values of `n`.

```cpp
long long sum_of_natural_numbers(int end, int step) {
    int count = (end - 1) / step;
    return static_cast<long long>(count) * (count + 1) * step / 2;
}

long long solution_closed_form(int n) {
    return sum_of_natural_numbers(n, 3)
         + sum_of_natural_numbers(n, 5)
         - sum_of_natural_numbers(n, 15);
}
```

### Final Thoughts

By using the closed-form formula for the sum of an arithmetic progression, we reduced the time complexity to \( O(1) \). This solution can handle very large inputs efficiently and correctly computes the sum of multiples of 3 and 5 below `n`.

### Key Insights

1. **Brute Force**: Simple but inefficient approach that works for small inputs.
2. **Hash Set**: Optimized to avoid double-counting but still inefficient for large inputs.
3. **Arithmetic Progression**: The final optimized solution uses mathematical formulas to compute the result in constant time.

## How to Run

1. Clone this repository.
2. Compile the C++ code using a C++14 compiler.
3. Run the program and provide input to see the results.

### Example Input/Output

**Input**:
```
3
10
15
20
```

**Output**:
```
23
45
78
```

## Conclusion

This journey highlights the importance of understanding mathematical patterns and leveraging them to optimize algorithms. By moving from a brute force approach to an optimized solution using arithmetic progression, we can handle very large datasets efficiently.

