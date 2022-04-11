/*  You are given an integer array nums where the largest integer is unique.
    Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest 
    element, or return -1 otherwise.

            Example 1:
            Input: nums = [3,6,1,0]
            Output: 1
            Explanation: 6 is the largest integer.
            For every other number in the array x, 6 is at least twice as big as x.
            The index of value 6 is 1, so we return 1.

            Example 2:
            Input: nums = [1,2,3,4]
            Output: -1
            Explanation: 4 is less than twice the value of 3, so we return -1.

            Example 3:
            Input: nums = [1]
            Output: 0
            Explanation: 1 is trivially at least twice the value as any other number because there are no other numbers.
*/



class Solution {
public:
    int dominantIndex(vector<int> &nums)
    {           
        int mx = *max_element(nums.begin(),nums.end()); 
        int ans;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == mx) 
            {
                ans = i; 
                continue;
            }
            
            if(nums[i] * 2 > mx) 
                return -1;
        }
        return ans;
    }
};



/* USING STL
class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int mx = *max_element(nums.begin(), nums.end());               // returns max element

        for (int i = 0; i < nums.size(); i++)
        {
            if (mx < nums[i] * 2 && mx != nums[i])               // as we donot have to check the max element therefor mx != nums[i]
                return -1;
        }
        return max_element(nums.begin(), nums.end()) - nums.begin();           // returns max element index
    }
};
*/



