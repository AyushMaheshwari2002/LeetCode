/*  Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

            Example 1:
                  Input: n = 5
                  Output: true
                  Explanation: The binary representation of 5 is: 101

            Example 2:
                  Input: n = 7
                  Output: false
                  Explanation: The binary representation of 7 is: 111.

            Example 3:
                  Input: n = 11
                  Output: false
                  Explanation: The binary representation of 11 is: 1011.
*/



class Solution {
public:
    bool hasAlternatingBits(int n)
    {
        string s;
        
        while(n != 0)
        {
            s += to_string(n % 2);
            n /= 2;
        }
        
        for(int i = 0; i < s.length()-1; i++)
        {
            if (s[i] == s[i + 1])
                return false;
        }
        
        return true;
    }
};



