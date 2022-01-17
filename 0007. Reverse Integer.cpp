/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
                Example 1:
                      Input: x = 123
                      Output: 321

                Example 2:
                      Input: x = -123
                      Output: -321

                Example 3:
                      Input: x = 120
                      Output: 21
*/

class Solution {
public:
    int reverse(int x) {
        int min = INT_MIN;
        int max = INT_MAX;
        
        long int res = 0; 
            while(x != 0)
            {  
                res *= 10;
                res += (x % 10);
                x = x / 10;
            }
        if(res > max || res < min)
            res = 0;
        
        return res;
    }
};
