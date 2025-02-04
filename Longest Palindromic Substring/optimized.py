class Solution:
    def longestPalindrome(self, s: str) -> str:
        if len(s) <=1 or s == s[::-1]:
            return s
        start, max_len = 0,1
        def expand(l,r):
            while l >= 0 and r < len(s) and s[l] == s[r]:
                l-=1
                r+=1
            return l+1, r -l -1
        for i in range(len(s)):
            if len(s) -i <= max_len // 2:
                break
            l1, len1 = expand(i,i)
            l2, len2 = expand(i, i+1)
            if len1 > max_len:
                start, max_len = l1, len1
            if len2 > max_len:
                start, max_len = l2, len2
        return s[start: start +max_len]
