class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();

        for ( int i = 0; i < n;){
            if ( nums[i] == 0){
                nums.push_back(0); // push 0 at end
                nums.erase(nums.begin() + i); // erase at location begin() + index
                n--; // adjust the length after moving zero to end
            } else {
                i++; // increase i only if its not zero
            }
        }
    }
};
