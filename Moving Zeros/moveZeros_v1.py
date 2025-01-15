class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i = 0
        while i < n:
            if nums[i] == 0:
                nums.append(0) # add zero to end
                nums.pop(i) # remove zero from curr position
                n-= 1 # reduce 
            else:
                i += 1 # only increase if no zero is removed in case of trailing zeros


# same concept as the v1 in C++
