/*  Given an integer array nums of unique elements, return all possible subsets (the power set).
    The solution set must not contain duplicate subsets. Return the solution in any order.

            Example 1:
            Input: nums = [1,2,3]
            Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

            Example 2:
            Input: nums = [0]
            Output: [[],[0]]
*/



class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int x, vector<int> &nums, vector<int> curr)
    {
        ans.push_back(curr);
        for(int i = x; i < nums.size(); i++)
        {
            curr.push_back(nums[i]);
            solve(i+1, nums, curr);
            curr.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<int> curr;
        solve(0 , nums , curr);
            
        return ans;
    }
};


