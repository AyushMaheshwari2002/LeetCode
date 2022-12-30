/*  Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
    Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

            Example 1:
                  Input: s = "abccccdd"
                  Output: 7
                  Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

            Example 2:
                  Input: s = "a"
                  Output: 1
                  Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/



class Solution {
public:
    int longestPalindrome(string s) 
    {
        int ans = 0;
        unordered_map<char,int> m;
        
        for(auto i : s)
            m[i]++;
        
        int odd_found = 0;
        for(auto i : m)
        {
            // if there is an even length palindrome
            if(i.second % 2 == 0)
                ans += i.second;
            
            else {
                // if there is an odd length palindrome
                odd_found = 1;
                ans += i.second - 1;
            }
        }
        
        if(odd_found == 1)
            ans++;
        
        return ans;
    }
};




