/* An integer array is called arithmetic if it consists of at least three elements and if the difference between any two consecutive elements is the same.
            * For example, [1,3,5,7,9], [7,7,7,7], and [3,-1,-5,-9] are arithmetic sequences.
   Given an integer array nums, return the number of arithmetic subarrays of nums.
   A subarray is a contiguous subsequence of the array.

          Example 1:
                Input: nums = [1,2,3,4]
                Output: 3
                Explanation: We have 3 arithmetic slices in nums: [1, 2, 3], [2, 3, 4] and [1,2,3,4] itself.

          Example 2:
                Input: nums = [1]
                Output: 0
*/



// Time Complexity : O(N^2)     Space Complexity : O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        if(A.size() < 3)
            return 0;
        
        int ans = 0;
        
        for(int i = 0; i < A.size()-1; i++)
        {
            int diff = A[i+1] - A[i];
            
            for(int j = i+2; j < A.size(); j++)
            {
                if(A[j] - A[j-1] == diff)
                {
                    ans++;
                }
                else 
                {
                    break;
                }
            }
        }
        return ans;
    }
};



// Time Complexity : O(N)     Space Complexity : O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        if(A.size() < 3)
            return 0;
        
        int ans = 0, count = 0;
        int prev_diff = A[1] - A[0];
        
        for(int i = 1; i < A.size()-1 ; i++)
        {
            int diff = A[i+1] - A[i];
            
            if(diff ==  prev_diff)
                count++;
            
            else
            {
                prev_diff = diff;
                count = 0;
            }
            ans += count;
        }
        
        return ans;
    }
};



// Time Complexity : O(N)     Space Complexity : O(1)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) 
    {
        int ans = 0, count = 0;
        
        for (int i = 2; i < A.size(); i++) 
        {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2])
            {
                count++;
            }
            else
            {
                count = 0;
            }
            ans += count;
        }
        
        return ans;
    }
};


