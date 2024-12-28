class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        return s == string(s.rbegin(), s.rend());
    }
};

// somehow my solution was 6 ms compared to my python that was 2 ms .... something ain't right with this leetcode run time..
