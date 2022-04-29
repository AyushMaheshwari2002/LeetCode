/*  Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
    In other words, return true if one of s1's permutations is the substring of s2.

            Example 1:
            Input: s1 = "ab", s2 = "eidbaooo"
            Output: true
            Explanation: s2 contains one permutation of s1 ("ba").

            Example 2:
            Input: s1 = "ab", s2 = "eidboaoo"
            Output: false
*/



class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size())
            return false;
        
        vector<int> s1_freq(26, 0), s2_freq(26, 0);
        
        // check if the frequency of s1 is there in s2 with a window size equal to s1
        int i;
        for(i = 0; i < s1.size(); i++) 
        {
            // compute the frequency of each char for the first window
            s1_freq[s1[i] - 'a']++;
            s2_freq[s2[i] - 'a']++;
        }
        
        if(s1_freq == s2_freq)
            return true;
        
        // search the remaining windows
        for(; i < s2.size(); i++)                         // here i will start from 2nd index
        {
            // remove the first char of current window and add the current char
            s2_freq[s2[i - s1.size()] - 'a']--;
            s2_freq[s2[i] - 'a']++;
            
            if(s1_freq == s2_freq)
                return true;
        }
        return false;
    }
};


