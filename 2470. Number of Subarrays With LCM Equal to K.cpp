/*  Given an integer array nums and an integer k, return the number of subarrays of nums where the least common multiple of the subarray's elements is k.
    A subarray is a contiguous non-empty sequence of elements within an array.
    The least common multiple of an array is the smallest positive integer that is divisible by all the array elements.

            Example 1:
                  Input: nums = [3,6,2,7,1], k = 6
                  Output: 4
                  Explanation: The subarrays of nums where 6 is the least common multiple of all the subarray's elements are:
                  - [3,6,2,7,1]
                  - [3,6,2,7,1]
                  - [3,6,2,7,1]
                  - [3,6,2,7,1]

            Example 2:
                  Input: nums = [3], k = 2
                  Output: 0
                  Explanation: There are no subarrays of nums where 2 is the least common multiple of all the subarray's elements.
*/



class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) 
    {
        int count = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            int curr = 1;
            for(int j = i; j < nums.size(); j++)
            {
                curr = lcm(curr,nums[j]);
                if(curr == k)
                    count++;

                if (curr > k)
                    break;
            }
        }

        return count;
    }
};






