class Solution {
public:
    int maxSum(vector<vector<int>>& arr) {
        int max_sum = INT_MIN; // set the maximum variable to int min 
        int rows = arr.size(); // get the amount of rows
        int columns = arr[0].size(); // get the amount of columns

        for ( int i = 0; i <rows-2; ++i) { // loop through rows
        for ( int j = 0; j <columns-2;++j) { // loop through columns 
        int sum = (arr[i][j]+arr[i][j+1]+arr[i][j+2])+(arr[i+1][j+1])+ (arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]); // get the sum of hourglass shape

        max_sum = max(max_sum, sum); // compare it to the maximum sum if its bigger then set it as the maximum
        }
        }
        return max_sum; // return that value
    }
};
