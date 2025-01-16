class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for ( int i = 1; i <= n; ++i){
            string temp = "";
            if ( i % 3 == 0) {
                temp += "Fizz";
            }
            if ( i % 5 == 0) {
                temp += "Buzz";
            }

            if (temp == "") { 
                ans.push_back(to_string(i));
            } else {
                ans.push_back(temp);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for ( int i = 1; i <= n; ++i){
            if( i % 3 == 0 && i % 5 == 0){
                ans.push_back("FizzBuzz");
            } else if ( i % 3 == 0){
                ans.push_back("Fizz");
            } else if (i % 5 == 0){
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
    }
};
*/
