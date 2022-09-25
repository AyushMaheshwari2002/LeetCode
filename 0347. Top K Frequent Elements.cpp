/*  Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

          Example 1:
                Input: nums = [1,1,1,2,2,3], k = 2
                Output: [1,2]

          Example 2:
                Input: nums = [1], k = 1
                Output: [1]
*/



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        map<int , int> m;
        
        for(int i = 0; i < nums.size(); i++)
            m[nums[i]]++;
        
        vector<pair<int , int>> v;
        for(auto i : m)
        {
            // in vector we have first store the frequency then no. b'coz we have to sort the vector on the basis of increasing frequency
            v.push_back({i.second , i.first});    
        }
        
        sort(v.begin() , v.end());
        reverse(v.begin() , v.end());         // the element which has largest frequency comes first
        
        vector<int> ans(k);
        for(int i = 0; i < k; i++)
        {
            ans[i] = v[i].second;
        }
        
        return ans;
    }
};



