/* Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the
   integers that appears twice.
   You must write an algorithm that runs in O(n) time and uses only constant extra space.

            Example 1:
                  Input: nums = [4,3,2,7,8,2,3,1]
                  Output: [2,3]

            Example 2:
                  Input: nums = [1,1,2]
                  Output: [1]

            Example 3:
                  Input: nums = [1]
                  Output: []
*/



// USING MAP
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        for(auto i : mp)
        {
            if(i.second == 2)
                ans.push_back(i.first);
        }
        return ans;
    }
};



/*
// USING SIMPLE SORT
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
            {
                ans.push_back(nums[i]);
            }
        }
        
        return ans;
    }
};
*/



