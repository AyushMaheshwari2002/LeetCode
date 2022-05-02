/*  Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form 
    any triangle of a non-zero area, return 0.

            Example 1:
            Input: nums = [2,1,2]
            Output: 5

            Example 2:
            Input: nums = [1,2,1]
            Output: 0
*/



class Solution {
public:
    int largestPerimeter(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int sum = 0;
        
        for(int i = 0; i < nums.size()-2; i++)
        {
            if(nums[i] + nums[i+1] > nums[i+2])
            {
                sum = max(sum , nums[i] + nums[i+1] + nums[i+2]);
            }
        }
        return sum;
    }
};



