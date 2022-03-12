/* Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.

            Example 1:
            Input: nums = [3,10,5,25,2,8]
            Output: 28
            Explanation: The maximum result is 5 XOR 25 = 28.

            Example 2:
            Input: nums = [14,70,53,83,49,91,36,80,92,51,66,70]
            Output: 127
*/



// TC : O(N)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
         int ans = 0, prefix = 0;

         for(int i = 31; i >= 0; i--)
         {
             prefix = prefix | (1 << i);
			
			 unordered_set<int> s;
			 
             for(int n : nums) 
                 s.insert(n & prefix); 
				 
             int c = ans | (1 << i);  
             for(int a : s)
             {
                 int b = c ^ a;
                 if(s.find(b) != s.end()) // if b exists
                 {
                     ans = c;
                     break;
                 }
             }
         }
        return ans; 
    }
};




/* BASIC APPROACH       TC : O(N^2)
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        int result = 0;                     //max. number after XOR
        
        for(int i = 0; i < nums.size() - 1; i++)
        {
            for(int j = i+1; j < nums.size(); j++)
            {
                result = max(result, nums[i] ^ nums[j]);
            }
        }
        return result;
    }
};
*/


