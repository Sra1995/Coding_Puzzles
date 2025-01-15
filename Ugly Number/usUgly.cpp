class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0){
            return false;
        }
        vector<int> divisor = {2,3,5};
        for ( int i : divisor){
            while (n % i == 0){
                n /= i;
            }
        }
        return n == 1;
    }
};

/*
just keep diving by 2, 3 , 5 until we reach 1 meaning has no prime factors
since they are looking for bool output just compare it to 1


*/
