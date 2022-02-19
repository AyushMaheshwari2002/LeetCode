/* Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
   A subarray is a contiguous part of an array.

                Example 1:
                Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
                Output: 6
                Explanation: [4,-1,2,1] has the largest sum = 6.

                Example 2:
                Input: nums = [1]
                Output: 1

                Example 3:
                Input: nums = [5,4,-1,7,8]
                Output: 23
*/


/* Best Approach : Kadane Algorithm - TC : O(n) and SC : O(1)
Using this approach we can get the maximum sum of subarray in just O(n) time complexity.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int MAX = INT_MIN;           //or use MAX = nums[0];
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) 
        {
            sum += nums[i];
            MAX = max(sum, MAX);
            
            if(sum < 0) 
                sum = 0;
        }
        return MAX;
    }
};

// Kadane Algorithm is that : we carry a sum of sub array as long as it gives us a positive sum.


