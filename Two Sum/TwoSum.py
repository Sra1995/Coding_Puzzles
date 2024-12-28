class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        freq = {}

        for i, num in enumerate(nums):
            complement = target - num
            if complement in freq:
                return [freq[complement],i]

            freq[num] = i

        return []


"""
the beauty of python ahhhh.....
"""
