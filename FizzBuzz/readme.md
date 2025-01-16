# 412 Fizz Buzz

Given an integer `n`, return a string array `answer` (1-indexed) where:

- `answer[i] == "FizzBuzz"` if `i` is divisible by 3 and 5.
- `answer[i] == "Fizz"` if `i` is divisible by 3.
- `answer[i] == "Buzz"` if `i` is divisible by 5.
- `answer[i] == i` (as a string) if none of the above conditions are true.

### Example 1:
**Input:** `n = 3`  
**Output:** `["1","2","Fizz"]`

### Example 2:
**Input:** `n = 5`  
**Output:** `["1","2","Fizz","4","Buzz"]`

### Example 3:
**Input:** `n = 15`  
**Output:** `["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]`

### Constraints:
- `1 <= n <= 10^4`


### Solution

- to tree structure if condition first both meets then either only the 5 or 3 then an else to append the index
- second approach which is easier to modifiy in the future make temp string and if the index % 3 add fizz and if index % 5 add buzz to the tmp word and before you append it to the answer vector check if its empty or not if so add the index as string.
