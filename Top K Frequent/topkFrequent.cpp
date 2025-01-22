class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq_dict;
        for ( int num : nums){
            freq_dict[num]++;
        }

        priority_queue<pair<int, int>> max_heap;
        for ( const auto& pair: freq_dict) {
            max_heap.push({pair.second, pair.first});
        }

        vector<int> result;
        for ( int i = 0; i < k ; ++i){
            result.push_back(max_heap.top().second);
            max_heap.pop();
        }

        return result;
    }
};

// low key doign heap in C++ is so much easy to follow compared to having to do -1 since it behave like min heap by default in python
