/* Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i 
   is maximized. Return the maximized sum.

      Example 1:
            Input: nums = [1,4,3,2]
            Output: 4
            Explanation: All possible pairings (ignoring the ordering of elements) are:
            1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
            2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
            3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
            So the maximum possible sum is 4.

      Example 2:
            Input: nums = [6,2,6,5,1,2]
            Output: 9
            Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
*/



class Solution {
public:
    int arrayPairSum(vector<int>& nums) 
    {
        int sum = 0;
        
        sort(nums.begin(),nums.end());
        
        for(int i = 0; i < nums.size(); i+=2)
        {
            sum += nums[i];
        }
        
        return sum;
    }
};


/* EPLANATION
	nums = [6,2,6,5,1,2]
	and after sorting array becomes [1,2,2,5,6,6]
	now think of the pairs in the array [ (1,2) , (2,5) , (6,6) ]
	out of which the minimum will always be the first element of the pair 
	and that is the reason we are iterating 2 elements at the time summing 
	up the minimum of each pair and having the maximum sum;
*/ 



