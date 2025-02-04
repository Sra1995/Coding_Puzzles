class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1 || s == string(s.rbegin(), s.rend())) return s; // Edge case: already a palindrome

        int start = 0, max_len = 1;

        // Expand around center function
        auto expand = [&](int l, int r) -> pair<int, int> {
            while (l >= 0 && r < n && s[l] == s[r]) {
                l--;
                r++;
            }
            return {l + 1, r - l - 1}; // Return new left bound and length
        };

        for (int i = 0; i < n; i++) {
            if (n - i <= max_len / 2) break; // Early exit optimization

            auto [l1, len1] = expand(i, i);     // Odd-length palindrome
            auto [l2, len2] = expand(i, i + 1); // Even-length palindrome

            if (len1 > max_len) {
                start = l1;
                max_len = len1;
            }
            if (len2 > max_len) {
                start = l2;
                max_len = len2;
            }
        }

        return s.substr(start, max_len);
    }
};
