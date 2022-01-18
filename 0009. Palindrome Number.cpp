/* Given an integer x, return true if x is palindrome integer.
          Example 1:
                Input: x = 121
                Output: true
                Explanation: 121 reads as 121 from left to right and from right to left.

          Example 2:
                Input: x = -121
                Output: false
                Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        int n = x;
        long int rev = 0, rem;
        
        while(x > 0)
        {
            rem = x % 10;
            rev = rev * 10 + rem;
            x = x / 10;
        }
        return n == rev;
    }
};
