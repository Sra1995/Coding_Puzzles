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
