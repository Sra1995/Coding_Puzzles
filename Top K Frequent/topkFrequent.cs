public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        Dictionary<int, int> freqMap = new Dictionary<int, int>();
        foreach ( int num in nums){
            if ( freqMap.ContainsKey(num)) {
                freqMap[num]++;
            } else {
                freqMap[num] = 1;
            }
        }

        PriorityQueue<int, int> minHeap = new PriorityQueue<int, int>();
        foreach( var entry in freqMap) {
            minHeap.Enqueue(entry.Key, entry.Value);
            if (minHeap.Count > k) {
                minHeap.Dequeue();
            }
        }

        int[] result = new int[k];
        for ( int i = 0; i < k ; ++i){
            result[i] = minHeap.Dequeue();
        }

        return result;
    }
}
