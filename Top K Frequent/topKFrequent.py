class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq_dict = Counter(nums)
        heap = []

        for num, freq in freq_dict.items():
            heapq.heappush(heap, (-freq, num))

        result = []
        for _ in range(k):
            result.append(heapq.heappop(heap)[1]) # so much heap heap heap heap

        return result

# OR this solutions but heaping is more optimal
# class Solution:
#     def topKFrequent(self, nums: List[int], k: int) -> List[int]:
#         freq_dict = Counter(nums)

#         arr = []
#         for num, cnt in freq_dict.items():
#             arr.append([cnt, num])
#         arr.sort()

#         result = []
#         while len(result) < k:
#             result.append(arr.pop()[1])
#         return result
