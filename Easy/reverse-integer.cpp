// Given a 32-bit signed integer, reverse digits of an integer.
/*
Note:
Assume we are dealing with an environment which could only 
store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(long x) {
        long result = 0;
        int d;
        if(x > 0 ){
            while(x){
                d = x % 10;
                result = (result * 10) + d;
                x/= 10;
            }
            if(result > INT_MAX)
                return 0;
            return result;
        }
        else if( x < 0 ){
            x = abs(x);
            while(x){
                d = x % 10;
                result = (result * 10) + d;
                x/= 10;
            }
            result = result * -1;
            if(result <= INT_MIN)
                return 0;
            return result;
        }
        return 0;
    }
};