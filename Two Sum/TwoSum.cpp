// feels lazy so imma just put the function it self from now on :D

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if (hash.find(complement) != hash.end()){
                return {hash[complement], i};
            }
            hash[nums[i]] = i;
        }

        return {};
    }
};

/*

Create a map to store numbers and their indices.
Iterate through the vector once:
- Calculate the complement (target - current number).
- Check if the complement exists in the map.
  - If it exists, return its index and the current index.
- Otherwise, add the current number and its index to the map.
If no solution is found, return an empty vector.

dictionaries are such nice thing in python with enumerate() huh.....
*/
