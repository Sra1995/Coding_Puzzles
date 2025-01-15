class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX; // smallest number
        int second = INT_MAX; // second smallest number

        for ( int num : nums){
            if ( num <=first) { 
                first = num; // update the smallest number if there is smaller value
            } else if ( num <= second){
                second = num; // update second num if there is smaller value that is bigger than first num
            } else {
                return true; // if we went through all of it then last numb is bigger than the other 2 which means true
            }
        }
        return false; // if we looped and didn't return true meaning we didn't find triplet pairs that fit it
    }
};


/*
initially I was thinking of solving it like 3sum but this solution only passed 73 testcases
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        for ( int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() -1;
            while ( j <k){
                if ( nums[i] < nums[j]  && nums[j] < nums[k]){
                    return true;
                }
                j++;
            }
        }
        return false;
    }
};

I knew the approach was wrong when I can either do j++ or k-- and pass different test cases and fail others


*/
