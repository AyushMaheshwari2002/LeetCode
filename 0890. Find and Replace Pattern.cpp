/*  Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.
    A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x), we get the desired word.
    Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

            Example 1:
                  Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
                  Output: ["mee","aqq"]
                  Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
                  "ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

            Example 2:
                  Input: words = ["a","b","c"], pattern = "a"
                  Output: ["a","b","c"]
*/



class Solution {
public:
    
    vector<int> found_Pattern(string pattern)
    {
        if(pattern.size() == 0)
            return {};
        
        vector<int> v;
        int ind = 0;
        unordered_map<char,int> mp;
        for(int i = 0; i < pattern.size(); ++i)
        {
           if(mp.find(pattern[i]) == mp.end())
           {
               mp.insert({pattern[i],ind++});
               v.push_back(mp[pattern[i]]);
           }
            else
            {
                v.push_back(mp[pattern[i]]);
            }
        }
        return v;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) 
    {   
        vector<int> v = found_Pattern(pattern);
        
        int n = words.size();
        vector<string> ans;
        
        for(int i = 0; i<n; ++i)
        {
            vector<int> pattern_word = found_Pattern(words[i]);
            
            if(v == pattern_word)
                ans.push_back(words[i]);
        }
        
        return ans;
    }
};




