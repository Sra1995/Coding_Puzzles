# LeetCode Problem: Top K Frequent Elements

## Problem Statement
Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in any order.

### Example
**Input:** `nums = [1,1,1,2,2,3], k = 2`  
**Output:** `[1,2]`

### Constraints
1. `1 <= nums.length <= 10^5`
2. `k` is in the range `[1, the number of unique elements in nums]`
3. The answer is guaranteed to be unique.

---

## My Initial (Incorrect) Approach

I started by attempting to solve the problem using basic loops and dictionaries. The idea was to first count the frequency of each number and then collect the most frequent elements by iterating through the dictionary. Here is the code:

### Initial Python Code
```python
def topKFrequent(self, nums: List[int], k: int) -> List[int]:
    freq_dict = {}
    result = []

    for num in nums:
        if num in freq_dict:
            freq_dict[num] += 1
        else:
            freq_dict[num] = 1

    for key in freq_dict:
        if freq_dict[key] >= k:  # This logic is incorrect
            result.append(key)

    return result
```

### Issues with the Initial Code
1. **Incorrect logic for adding elements to the result:** The condition `freq_dict[key] >= k` checks whether the frequency of the element is greater than or equal to `k`, but it should instead find the `k` most frequent elements.
2. **No Sorting or Priority Mechanism:** The code does not sort or prioritize elements based on their frequency, leading to incorrect results for cases where more than `k` elements meet the condition.
3. **Fails Specific Test Cases:** For example, for `nums = [1,2]` and `k = 2`, the code does not handle the logic to extract exactly `k` elements, resulting in an empty or incorrect output.

---

## Optimized Solution Using Heaps
To efficiently solve this problem, I implemented a solution using a heap (priority queue). The idea is:

1. Count the frequency of each number using a dictionary.
2. Use a max-heap (Python's `heapq` with negative frequencies) to keep track of the top `k` frequent elements.
3. Extract the `k` elements from the heap.

### Python Heap Solution
```python
from collections import Counter
import heapq

def topKFrequent(nums: List[int], k: int) -> List[int]:
    # Step 1: Count frequencies
    freq_dict = Counter(nums)

    # Step 2: Create a max-heap based on frequencies
    heap = []
    for num, freq in freq_dict.items():
        heapq.heappush(heap, (-freq, num))

    # Step 3: Extract top k elements from the heap
    result = []
    for _ in range(k):
        result.append(heapq.heappop(heap)[1])

    return result
```

### C++ Heap Solution
```cpp
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    // Step 1: Count frequencies
    unordered_map<int, int> freq_map;
    for (int num : nums) {
        freq_map[num]++;
    }

    // Step 2: Create a max-heap based on frequencies
    priority_queue<pair<int, int>> max_heap;
    for (const auto& pair : freq_map) {
        max_heap.push({pair.second, pair.first});
    }

    // Step 3: Extract top k elements from the heap
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        result.push_back(max_heap.top().second);
        max_heap.pop();
    }

    return result;
}
```

---

## Complexity Analysis

### Python Heap Solution
- **Time Complexity:**
  - Building the frequency dictionary: `O(n)` where `n` is the length of `nums`.
  - Pushing `n` elements into the heap: `O(n log n)`.
  - Extracting `k` elements from the heap: `O(k log n)`.
  - Overall: `O(n log n)`.
- **Space Complexity:** `O(n)` for the frequency dictionary and heap.

### C++ Heap Solution
- **Time Complexity:**
  - Building the frequency map: `O(n)`.
  - Pushing elements into the heap: `O(n log n)`.
  - Extracting `k` elements: `O(k log n)`.
  - Overall: `O(n log n)`.
- **Space Complexity:** `O(n)` for the frequency map and heap.

---

## Test Case Walkthrough

**Input:** `nums = [1,1,1,2,2,3], k = 2`  
**Expected Output:** `[1, 2]`

### Python Heap Solution Walkthrough
1. **Frequency Dictionary:** `freq_dict = {1: 3, 2: 2, 3: 1}`.
2. **Heap Contents:** `heap = [(-3, 1), (-2, 2), (-1, 3)]` (max-heap simulated with negative frequencies).
3. **Result Extraction:**
   - First pop: `(-3, 1)` → Add `1` to result.
   - Second pop: `(-2, 2)` → Add `2` to result.
4. **Final Result:** `[1, 2]`.

### C++ Heap Solution Walkthrough
1. **Frequency Map:** `freq_map = {1: 3, 2: 2, 3: 1}`.
2. **Heap Contents:** `max_heap = [(3, 1), (2, 2), (1, 3)]`.
3. **Result Extraction:**
   - First pop: `(3, 1)` → Add `1` to result.
   - Second pop: `(2, 2)` → Add `2` to result.
4. **Final Result:** `[1, 2]`.

---

## Lessons Learned
1. **Understand the Problem:** Ensure the solution logic aligns with the requirements (e.g., finding the top `k` elements vs. elements with a frequency threshold).
2. **Use the Right Tools:** Heaps are excellent for extracting the most or least frequent elements efficiently.
3. **Write Readable Code:** Avoid overly concise expressions that may obscure logic, especially when learning.

---

## References
- [Python `heapq` Documentation](https://docs.python.org/3/library/heapq.html)
- [C++ STL Priority Queue](https://cplusplus.com/reference/queue/priority_queue/)
