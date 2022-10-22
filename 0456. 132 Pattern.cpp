/*  Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].
    Return true if there is a 132 pattern in nums, otherwise, return false.

            Example 1:
                    Input: nums = [1,2,3,4]
                    Output: false
                    Explanation: There is no 132 pattern in the sequence.

            Example 2:
                    Input: nums = [3,1,4,2]
                    Output: true
                    Explanation: There is a 132 pattern in the sequence: [1, 4, 2].

            Example 3:
                    Input: nums = [-1,3,2,0]
                    Output: true
                    Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].
*/



class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> minarr(n);
        
        minarr[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            minarr[i] = min(nums[i] , minarr[i-1]);
        }
        
        stack<int> s;
        for(int j = n-1; j >= 0; j--)
        {
            while(!s.empty() && s.top() <= minarr[j])
                s.pop();
            
            if(!s.empty() && s.top() < nums[j])
            {
                return true;
            }
            
            s.push(nums[j]);
        }
        
        return false;
    }
};




/* 
T.C : O(n^3) gives TLE
class Solution {
public:
    bool find132pattern(vector<int>& nums) 
    {
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = i + 1; j < nums.size(); j++)
            {
                for(int k = j + 1; k < nums.size(); k++) 
                {
                    if(nums[i] < nums[k] && nums[k] < nums[j]) 
                        return true;
                }
            }
        }
        return false;
    }
};
*/




