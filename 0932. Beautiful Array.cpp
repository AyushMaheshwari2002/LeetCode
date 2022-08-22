/*  An array nums of length n is beautiful if:
          * nums is a permutation of the integers in the range [1, n].
          * For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
    Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.

              Example 1:
                    Input: n = 4
                    Output: [2,1,4,3]

              Example 2:
                    Input: n = 5
                    Output: [3,1,2,5,4]
*/




/* 
Formula : for finding odd element's permutation --> 2 * element + 1
             for finding even element's permutation --> 2 * element
             Condition --> ans <= n
*/
                

class Solution {
public:
    vector<int> beautifulArray(int n) 
    {
        if(n == 1)
            return {1};
        
        vector<int>  ans;
        ans.push_back(1);
        
        while(ans.size() < n)
        {
            vector<int> temp;
            
            // for finding odd element's permutation
            for(auto i : ans)
            {
                if(2 * i - 1 <= n)
                    temp.push_back(2 * i - 1);
            }
            
            // for finding even element's permutation
            for(auto i : ans)
            {
                if(2 * i <= n)
                    temp.push_back(2 * i);
            }
            ans = temp;
        }
        return ans;
    }
};




