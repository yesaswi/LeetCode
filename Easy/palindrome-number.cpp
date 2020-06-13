// Palindrome Number
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
// Note : Coud you solve it without converting the integer to a string?

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        else{
            int y = x;
            long rev = 0;
            while(y!=0){
                int d = y % 10;
                rev = rev * 10 + d;
                y/=10;
            }
            if (rev == x)
                return true;
        }
        return false;
    }
};
