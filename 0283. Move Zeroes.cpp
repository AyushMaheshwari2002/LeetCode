/*  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.

          Example 1:
              Input: nums = [0,1,0,3,12]
              Output: [1,3,12,0,0]

          Example 2:
              Input: nums = [0]
              Output: [0]
*/


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                continue;
            
            else
                swap(nums[i], nums[left]);
                left++;
        }
        return;
    }
};

