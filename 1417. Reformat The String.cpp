/*  You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
    You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two 
    adjacent characters have the same type.
    Return the reformatted string or return an empty string if it is impossible to reformat the string.

          Example 1:
                Input: s = "a0b1c2"
                Output: "0a1b2c"
                Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.

          Example 2:
                Input: s = "leetcode"
                Output: ""
                Explanation: "leetcode" has only characters so we cannot separate them by digits.

          Example 3:
                Input: s = "1229857369"
                Output: ""
                Explanation: "1229857369" has only digits so we cannot separate them by characters.
*/


class Solution {
public:
    string reformat(string s) 
    {
        string alpha , num;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] >= 'a' && s[i] <= 'z')           //for checking that the characters are in small or not.
                alpha.push_back(s[i]);
            else
                num.push_back(s[i]);
        }
        
        int n = alpha.size();
        int m = num.size();
        
        if(abs(n - m) > 1)
            return "";                            //return empty string
        if(alpha.size() > num.size())
            alpha.swap(num);
        
        string ans;
        for(int i = 0; i < s.size(); i++)
        {
            if(i % 2 == 0)
                ans.push_back(num[i/2]);
            else
                ans.push_back(alpha[i/2]);
        }
        return ans;
    }
};

