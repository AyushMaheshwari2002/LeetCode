/*  You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.
    For each index i, names[i] and heights[i] denote the name and height of the ith person.
    Return names sorted in descending order by the people's heights.

            Example 1:
                  Input: names = ["Mary","John","Emma"], heights = [180,165,170]
                  Output: ["Mary","Emma","John"]
                  Explanation: Mary is the tallest, followed by Emma and John.

            Example 2:
                  Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
                  Output: ["Bob","Alice","Bob"]
                  Explanation: The first Bob is the tallest, followed by Alice and the second Bob.
*/



// USING PAIR
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<pair<int,string>> v;    
        
        for(int i = 0; i < names.size(); i++)
        {
            v.push_back({heights[i],names[i]});
        }
        
        sort(v.rbegin(),v.rend());       
        
        vector<string> ans;
        for(auto i : v)
            ans.push_back(i.second);
        
        return ans;
    }
};



/* USING MAP
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<string> v;
        map<int, string> m;
        
        for(int i = 0; i < names.size(); i++)
        {
            m[heights[i]] = names[i];
        }
        
        for(auto it = m.rbegin(); it != m.rend(); it++)                   
            v.push_back(it->second);
        
        return v;
    }
};
*/



