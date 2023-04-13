/*  Given the integers zero, one, low, and high, we can construct a string by starting with an empty string, and then at each step perform either of the following:
        * Append the character '0' zero times.
        * Append the character '1' one times.
    This can be performed any number of times.
    A good string is a string constructed by the above process having a length between low and high (inclusive).
    Return the number of different good strings that can be constructed satisfying these properties. Since the answer can be large, return it modulo 109 + 7.

            Example 1:
                  Input: low = 3, high = 3, zero = 1, one = 1
                  Output: 8
                  Explanation: 
                  One possible valid good string is "011". 
                  It can be constructed as follows: "" -> "0" -> "01" -> "011". 
                  All binary strings from "000" to "111" are good strings in this example.

            Example 2:
                  Input: low = 2, high = 3, zero = 1, one = 2
                  Output: 5
                  Explanation: The good strings are "00", "11", "000", "110", and "011".
*/



class Solution {
public:
    int mod=1e9+7;
    int solve(int i, int zero, int one, vector<int> &v)
    {
        if(i == 0)
            return 1;
        
        if(i < 0)
            return 0;

        if(v[i] != -1)
            return v[i];

        return v[i] = (solve(i-one, zero, one, v) + solve(i-zero, zero, one, v)) % mod;
    }

    int countGoodStrings(int low, int high, int zero, int one) 
    {
        vector<int> v(1e5+1, -1);
        int count = 0;

        for(int i = low; i <= high; i++)
        {
            count = (count + solve(i, zero, one, v)) % mod;
        }

        return count;
    }
};



