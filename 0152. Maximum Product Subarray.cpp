/* Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
   The test cases are generated so that the answer will fit in a 32-bit integer.
   A subarray is a contiguous subsequence of the array.

                Example 1:
                Input: nums = [2,3,-2,4]
                Output: 6
                Explanation: [2,3] has the largest product 6.

                Example 2:
                Input: nums = [-2,0,-1]
                Output: 0
                Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int ans = nums[0];
        int max_element = nums[0];
        int min_element = nums[0];
        
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                swap(max_element, min_element);          //if we get negative no. for multiplying then replace
            }
        
            max_element = max(nums[i], max_element * nums[i]);
            min_element = min(nums[i], min_element * nums[i]);
            ans = max(ans, max_element);
        }
        return ans;
    }
};


