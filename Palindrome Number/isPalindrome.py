class Solution:
    def isPalindrome(self, x: int) -> bool:
        # one liner yolo
        return str(x) == str(x)[::-1]


# Bascially compared the number as string  to itself but reveresed by slicing.
