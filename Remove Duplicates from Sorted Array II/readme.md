[leetcode solution post](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/solutions/6280855/step-by-step-guide-to-understanding-remove-duplicates-from-sorted-array-ii)

# Introduction
<!-- Describe your first thoughts on how to solve this problem. -->
I didn't come up with this on my own, but if you looked at the solution tab you probably saw a solution titled **3-6 easy lines, C++, Java, Python, Ruby** by [Stefan Pochmann](https://leetcode.com/u/stefanpochmann/) 

However, there is no explanation and it took me bit to understand it after alot of print statements to track variables.

Also, Honorable mention to commentor [yp_parctice](https://leetcode.com/u/yp_practice/) for their comments that helped me understand it :D

# Problem gist:


We are given a sorted array <mark> nums </mark> , we need to modify it in-place so that:
1. Each number appears at most twice.
2. the Order of the numbers stays the same i.e 1,1,2,2,3,3 etc
3. Return the number of valid elemtns, "K" after modification

from the problem description:
```
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}

```

# Step-by-Step Solution:
1. Use a pointer ' i ' to indicate the position to place the next valid number.
2. Iterate through the array with a loop, using n as the current number.
3. Check if the current number n should be placed:
* Always allow the first two numbers (i < 2).
* For later numbers, check if n > nums[i-2]. This ensures that we only allow at most two occurrences of each number.
4. If the number n is valid:
Place it at position nums[i].
Increment i.
5. At the end of the loop, i will be the number of valid elements.

**input : nums [1,1,1,2,2,3]**

| step    | n  | i |  Condition Met? | Action | Modified nums|
| -------- | ------- | -------- | ------- | -------- | ------- |
| 1| 1 | 0 | Yes (i < 2) | place 1 at nums[0] & i++ | [1]
| 2| 1| 1| Yes (i < 2)| place 1 at nums[1]& i++ |[1,1] |
| 3| 1| 2| No ( 2<2 false & 1>1 false)| skip|[1,1] |
| 4| 2| 2| Yes ( 2 > nums[0]) | place 2 at nums[2]& i++  |[1,1,2|
| 5| 2| 3| Yes ( 2 > nums[1])| place 2 at nums[3]& i++ |1,1,2,2 |
| 6| 3| 4| Yes ( 3 > nums[2])| place 3 at nums[4] & i++ |[1,1,2,2,3] |

after last iteration i = 5

# Complexity
The time complexity is O(n) because we iterate through the array once, and the space complexity is O(1) because we modify the array in-place without using extra space.

# Code
```cpp []
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for ( int n : nums){
            if ( i < 2 || n > nums[i-2]){
                nums[i] = n;
                i++;
            }
        }
        return i;
    }
};
```
