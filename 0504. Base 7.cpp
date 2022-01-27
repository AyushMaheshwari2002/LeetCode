/*  Given an integer num, return a string of its base 7 representation.

          Example 1:
                Input: num = 100
                Output: "202"

          Example 2:
                Input: num = -7
                Output: "-10"
*/


class Solution {
public:
    string convertToBase7(int num) 
    {
        int n = num;
        string ans;
        
        if(num == 0)
            return "0";
    
        if(num < 0)
            num = abs(num);     //abs() function returns the absolute value of a number. That is, it returns x if x is positive or zero, and the negation of x if x is negative.
        while(num)
        {
            ans += to_string(num % 7);          //The to_string() method accepts a single integer and converts the integer value or other data type value into a string.
            num /= 7;
        }
        
        reverse(ans.begin(), ans.end());
        if(n < 0)
            ans =  "-" + ans;
        
        return ans;
    }
};


