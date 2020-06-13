// Palindrome Number
// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
// Note : Coud you solve it without converting the integer to a string?

// Runtime: 20 ms
// Time Complexity O (log n)
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


// Revert half of the number
// Runtime: 8 ms
// Time Complexity O(log 10(n))

/*
Algorithm

First of all we should take care of some edge cases. All negative numbers are not palindrome, 

for example: -123 is not a palindrome since the '-' does not equal to '3'. So we can return false 

for all negative numbers.

Now let's think about how to revert the last half of the number. For number 1221, if we do 1221 % 10,

we get the last digit 1, to get the second to the last digit, we need to remove the last digit from 1221,

we could do so by dividing it by 10, 1221 / 10 = 122. Then we can get the 

last digit again by doing a modulus by 10, 122 % 10 = 2, and if we multiply the last digit by 10 

and add the second last digit, 1 * 10 + 2 = 12, it gives us the reverted number we want.

Continuing this process would give us the reverted number with more digits.

Now the question is, how do we know that we've reached the half of the number?

Since we divided the number by 10, and multiplied the reversed number by 10, when the original number is 

less than the reversed number, it means we've processed half of the number digits.

*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        else{
            int rev = 0;
            while(x > rev){
                int d = x % 10;
                rev = rev * 10 + d;
                x/=10;
            }
            if (rev == x || x == rev/10)
                return true;
        }
        return false;
    }
};