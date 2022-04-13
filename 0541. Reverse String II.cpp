/*  Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
    If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k 
    characters and leave the other as original.

              Example 1:
              Input: s = "abcdefg", k = 2
              Output: "bacdfeg"

              Example 2:
              Input: s = "abcd", k = 2
              Output: "bacd"
*/



class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int l = 0;
        int r = min(k, (int)s.length());
        
        while(l < s.length())
        {
            reverse(s.begin() + l , s.begin() + r);
            l += 2 * k;
            
            r = min(l + k, (int)s.length());
        }
        return s;
    }
};


