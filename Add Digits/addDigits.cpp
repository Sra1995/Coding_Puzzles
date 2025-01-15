class Solution {
public:
    int addDigits(int num) {
        if (num == 0 ) return 0; // if the number is 0 just return 0 
        while ( num >= 10){ // if the number is 10 or bigger since digital root has to be 9 to 1
            int remainder = 0; 
            while (num > 0){ // same steps to reversing integer
                remainder += num %10;
                num = num /10;
            }
            num = remainder; // replace the number with the sum aka remainder ( just made sense to call it this)
        }
        return num; // return the nummber once it meet all conditions of not being 2 digits and between 1 and 9
    }
};
