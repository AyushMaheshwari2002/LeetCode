/*  Given an unsorted integer array nums, return the smallest missing positive integer.
    You must implement an algorithm that runs in O(n) time and uses constant extra space.

              Example 1:
                    Input: nums = [1,2,0]
                    Output: 3

              Example 2:
                    Input: nums = [3,4,-1,1]
                    Output: 2

              Example 3:
                    Input: nums = [7,8,9,11,12]
                    Output: 1
*/




class Solution {
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        // check for one (1 is present or not)
        bool contains_one = false;
        
        for(int x: nums)
        {
            if(x == 1)
            {
                contains_one = true;
                break;
            }
        }
        // if array is not contain 1 then return 1 b'coz it is the smallest ppositive number
        if(!contains_one) 
            return 1;
        
        // if array contains one then check for other positive numbers
        int n = nums.size();
        // if size of array is 1 and value is also 1 then return 2 
        if(n == 1) 
            return 2;
        
        for(int i = 0; i < n; i++)
        { 
            // if array contains negative no. or number which is greater than its size so convert it to 1
            if(nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }
        
        for(int i = 0; i < n; i++)
        {
            int x = abs(nums[i]);
            if(nums[x-1] > 0) 
                nums[x-1] *= -1;
        }
        
        // after that we iterate over the vector and if we find any positive value then return the index+1 of that value
        for(int i = 0; i < n; i++)
        { 
            if(nums[i] > 0) 
                return i+1;
        }
        
        // last case is if all the values is present from 1 to n
        // like vector size = 5; values = 1 2 3 4 5 ; then we have to return 6
        return n+1;
    }
};




