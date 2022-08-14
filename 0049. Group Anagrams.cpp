/*  Given an array of strings strs, group the anagrams together. You can return the answer in any order.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

            Example 1:
                  Input: strs = ["eat","tea","tan","ate","nat","bat"]
                  Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

            Example 2:
                  Input: strs = [""]
                  Output: [[""]]

            Example 3:
                  Input: strs = ["a"]
                  Output: [["a"]]
*/




class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        // we take sorted string as a string and original string as a vector string
        // aet -----> eat
        unordered_map<string , vector<string>> m;
        
        for(auto x : strs)
        {
            string temp = x;
            sort(x.begin() , x.end());
            
            // aet -----> eat
            m[x].push_back(temp);
        }
        
        for(auto x : m)
        {
            // we use "dot" in place of "->" b'coz of unordered map
            ans.push_back(x.second);
        }
        
        return ans;
    }
};



