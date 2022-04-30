/*  Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
    
              Example 1:
              Input: s = "cbaebabacd", p = "abc"
              Output: [0,6]
              Explanation:
              The substring with start index = 0 is "cba", which is an anagram of "abc".
              The substring with start index = 6 is "bac", which is an anagram of "abc".

              Example 2:
              Input: s = "abab", p = "ab"
              Output: [0,1,2]
              Explanation:
              The substring with start index = 0 is "ab", which is an anagram of "ab".
              The substring with start index = 1 is "ba", which is an anagram of "ab".
              The substring with start index = 2 is "ab", which is an anagram of "ab".
*/



class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        if(s.size() < p.size())
            return {};                    //return empty vector
        
        vector<int> s_freq(26, 0);
        vector<int> p_freq(26, 0);
        vector<int> ans;
      
        for(int i = 0; i < p.size(); i++)
        {
            s_freq[s[i] - 'a']++;
            p_freq[p[i] - 'a']++;
        }
        
        if(s_freq == p_freq)
            ans.push_back(0);
        
        for(int i = p.size(); i < s.size(); i++)
        {
            s_freq[s[i - p.size()] - 'a']--;              //remove the previous value
            s_freq[s[i] - 'a']++;                    // add the current value
            
            if(s_freq == p_freq)
                ans.push_back(i+1-p.size());            //if equal then you have to return the starting index
        }
        
        return ans;
    }
};


