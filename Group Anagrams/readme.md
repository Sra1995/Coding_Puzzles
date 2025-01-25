# Group Anagrams - LeetCode Problem 49

## Problem Description
Given an array of strings `strs`, group the **anagrams** together. You can return the answer in any order.

An **anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

### Example 1:
**Input:**  
```plaintext
strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
```

**Output:**  
```plaintext
[["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
```

### Example 2:
**Input:**  
```plaintext
strs = [""]
```

**Output:**  
```plaintext
[[""]]
```

### Example 3:
**Input:**  
```plaintext
strs = ["a"]
```

**Output:**  
```plaintext
[["a"]]
```

### Constraints:
- 1 <= strs.length <= 10^4
- 0 <= strs[i].length <= 100
- strs[i] consists of lowercase English letters

---

## My Initial Thoughts

When I first attempted this problem, I thought of comparing each string with every other string in the input array to check if they are anagrams. My approach was as follows:
1. Iterate through the input array.
2. For each string, sort its characters alphabetically.
3. Compare the sorted version of the current string with all other sorted strings.
4. Group strings that matched into a list.

### Initial Code Snippet (Python)
```python
def groupAnagrams(strs):
    result = []
    used = [False] * len(strs)
    
    for i in range(len(strs)):
        if not used[i]:
            group = [strs[i]]
            sorted_i = ''.join(sorted(strs[i]))
            used[i] = True
            
            for j in range(i + 1, len(strs)):
                if not used[j] and sorted_i == ''.join(sorted(strs[j])):
                    group.append(strs[j])
                    used[j] = True
            
            result.append(group)
    
    return result
```

---

## Why My Initial Solution Was Wrong

### **Problem: Inefficient Comparison**
My initial approach involved sorting each string multiple times and performing nested comparisons. This resulted in:
- **Time Complexity:** \(O(n^2 \cdot k \log k)\) due to double iteration over the array and sorting each string repeatedly.
- **Space Complexity:** Higher due to storing and re-sorting strings repeatedly.

### **Failed Test Case**
**Input:**  
```plaintext
strs = ["", "", "abc", "bca", "cab"]
```

**Expected Output:**  
```plaintext
[["", ""], ["abc", "bca", "cab"]]
```

**My Output:**  
```plaintext
[[""], [""], ["abc", "bca", "cab"]]
```

**Reason for Failure:**  
I failed to handle duplicate empty strings correctly, as I treated each empty string as a unique anagram group.

---

## New Solution

To optimize the solution, I used a **hash map (dictionary)** where the key is the **sorted version of the string** and the value is a list of anagrams corresponding to that key.

### Optimized Python Code
```python
from collections import defaultdict

def groupAnagrams(strs):
    anagrams = defaultdict(list)
    
    for word in strs:
        key = ''.join(sorted(word))  # Sort the string to create the key
        anagrams[key].append(word)  # Append the word to its corresponding group
    
    return list(anagrams.values())
```

### Why This Works
1. **Efficient Sorting:** Each string is sorted once, resulting in a unique key for anagram groups.
2. **Hash Map for Grouping:** The hash map allows for efficient lookups and insertions, ensuring linear grouping after sorting.

### Complexity:
- **Time Complexity:** \(O(n \cdot k \log k)\), where \(n\) is the number of strings, and \(k\) is the average string length.
- **Space Complexity:** \(O(n \cdot k)\) to store the input strings and their groups.

---

## Key Learning Points
1. Sorting is a powerful technique for problems involving comparison of permutations.
2. Using a hash map or dictionary can significantly reduce unnecessary comparisons and improve efficiency.
3. Always consider edge cases, such as empty strings, single-character strings, and duplicate inputs, when designing your solution.

---

## Sample Test Case Walkthrough

### Input: `["eat", "tea", "tan", "ate", "nat", "bat"]`

1. **Initialization:** Create an empty hash map `anagrams = {}`.
2. **Iterate Through Strings:**
   - "eat": Sort → Key = "aet", Group = ["eat"].
   - "tea": Sort → Key = "aet", Group = ["eat", "tea"].
   - "tan": Sort → Key = "ant", Group = ["tan"].
   - "ate": Sort → Key = "aet", Group = ["eat", "tea", "ate"].
   - "nat": Sort → Key = "ant", Group = ["tan", "nat"].
   - "bat": Sort → Key = "abt", Group = ["bat"].
3. **Result Extraction:** Convert hash map values to a list of lists:  
   ```
   [["eat", "tea", "ate"], ["tan", "nat"], ["bat"]]
   ```
