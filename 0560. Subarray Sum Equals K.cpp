/*  Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

            Example 1:
            Input: nums = [1,1,1], k = 2
            Output: 2

            Example 2:
            Input: nums = [1,2,3], k = 3
            Output: 2
*/



class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        unordered_map<int, int> m;
        int sum = 0 , count = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum == k)
                count++;
            
            if(m.find(sum - k) != m.end())
                count += m[sum - k];
            
            m[sum]++;
        }
        
        return count;
    }
};




/*   BASIC APPROACH    TC : O(N^2)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        int count = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            
            for(int j = i; j < nums.size(); j++)
            {
                sum += nums[j]; 
                
                if(sum == k)              
                    count++;
            }
        }
        return count;
    }
};
*/



