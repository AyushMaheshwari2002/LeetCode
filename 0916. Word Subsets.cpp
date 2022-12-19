/*  You are given two string arrays words1 and words2.
    A string b is a subset of string a if every letter in b occurs in a including multiplicity.
         * For example, "wrr" is a subset of "warrior" but is not a subset of "world".
    A string a from words1 is universal if for every string b in words2, b is a subset of a.
    Return an array of all the universal strings in words1. You may return the answer in any order.

          Example 1:
                Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
                Output: ["facebook","google","leetcode"]

          Example 2:
                Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
                Output: ["apple","google","leetcode"]
*/



class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> freq(26,0);
        
        for(auto itr : words2)
        {
            vector<int> temp(26,0);
            for(auto x : itr)
            {
                ++temp[x - 'a'];
                freq[x - 'a'] = max(temp[x - 'a'],freq[x - 'a']);
            }
        }
        
        vector<string> ans;
        
        for(auto itr : words1)
        {
            vector<int> temp(26,0);
            for(auto x : itr)
                ++temp[x - 'a'];
            
            bool flag = true;
            
            for(int i = 0; i<26; ++i)
            {
                if(freq[i] > temp[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
                ans.push_back(itr);
        }
        return ans;
    }
};




