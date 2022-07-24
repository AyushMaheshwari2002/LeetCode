/*  



*/




class Solution {
public:
    vector<int> findLonely(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        vector<int> v;
        
        for(int i : nums)
            m[i]++;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(m[nums[i]] == 1 && m.count(nums[i] - 1) == 0 && m.count(nums[i] + 1) == 0)
            {
                v.push_back(nums[i]);
            }
        }
        
        return v;
    }
};



