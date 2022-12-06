/*  Given an array nums with n integers, your task is to check if it could become non-decreasing by modifying at most one element.
    We define an array is non-decreasing if nums[i] <= nums[i + 1] holds for every i (0-based) such that (0 <= i <= n - 2).

          Example 1:
                Input: nums = [4,2,3]
                Output: true
                Explanation: You could modify the first 4 to 1 to get a non-decreasing array.

          Example 2:
                Input: nums = [4,2,1]
                Output: false
                Explanation: You cannot get a non-decreasing array by modifying at most one element.
*/



class Solution {
public:
    bool checkPossibility(vector<int>& nums) 
    {
         int violation = 0;
        
         for(int i=1;i<nums.size();i++)
         {
            // case for violation
            if(nums[i-1] > nums[i])
            {
                // at max, we can have one violation. So if it has been occured before => return false
                if(violation == 1)
                {
                    return false;
                }
                //if no prev violation, then violation++
                violation++;
               
                // fixing violation => operation 1
                if(i<2 || nums[i-2] <= nums[i])
                    nums[i-1] = nums[i];
                // fixing violation => operation 2
                else
                    nums[i] = nums[i-1];
                
            }
        }
        // if traversal of vector was successfull and return statement was not invoked then return true.
        return true;    
    }
};



