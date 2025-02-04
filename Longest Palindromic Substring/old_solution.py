class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        longest_substring = ""

        for i in range(n):
            for j in range(i+2, n +1):
                substring = s[i:j]

                if substring == substring[::-1]:
                    if len(substring) > len(longest_substring):
                        longest_substring = substring
                    elif len(substring) == len(longest_substring) and substring < longest_substring:
                        longest_substring = substring

        if longest_substring == "":
            return "None"
        else:
            return longest_substring


"""
I was asked similar question to this leetcode problem before I tried to solve it on leetcode and try optimize solution/research better ways.
This was what I submitted for the online assessment
they has bit of different things like printing None when there is no palindromic substring etc
"""
