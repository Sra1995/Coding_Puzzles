class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        unordered_set<char> charset;
        int start = 0;

        for ( int end = 0; end < s.length(); end++) 
        {
            while (charset.find(s[end]) != charset.end()) {
                charset.erase(s[start]);
                start++;
            }
        

         charset.insert(s[end]);

        max_length = max(max_length, end - start + 1);
        }
        return max_length;
    }
};

/*
 * The method `lengthOfLongestSubstring` is designed to find the length of the longest substring 
 * in a given string `s` that does not contain repeating characters.
 * 
 * Steps:
 * 1. We initialize `max_length` to 0, which will store the length of the longest substring without repeats.
 * 2. We use an unordered set `charset` to keep track of characters in the current window (substring).
 * 3. We use two pointers, `start` and `end`, to represent the window of characters. The pointer `start` 
 *    represents the beginning of the window, and `end` represents the current character in the string.
 * 4. The for-loop iterates through the string, with `end` moving through each character.
 * 5. Inside the loop, we check if the current character (`s[end]`) is already in the set `charset`. If it is, 
 *    we shrink the window from the left by removing characters from the set and advancing the `start` pointer 
 *    until `s[end]` is no longer in the set.
 * 6. Once the character is unique in the current window, we insert it into the set `charset`.
 * 7. We update `max_length` to be the maximum of the current `max_length` and the length of the window 
 *    (`end - start + 1`).
 * 8. After finishing the iteration, the method returns `max_length`, which represents the length of the 
 *    longest substring without repeating characters.
 */
