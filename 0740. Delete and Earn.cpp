/* You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:
        * Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.
   Return the maximum number of points you can earn by applying the above operation some number of times.

            Example 1:
                    Input: nums = [3,4,2]
                    Output: 6
                    Explanation: You can perform the following operations:
                    - Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
                    - Delete 2 to earn 2 points. nums = [].
                    You earn a total of 6 points.

            Example 2:
                    Input: nums = [2,2,3,3,3,4]
                    Output: 9
                    Explanation: You can perform the following operations:
                    - Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
                    - Delete a 3 again to earn 3 points. nums = [3].
                    - Delete a 3 once more to earn 3 points. nums = [].
                    You earn a total of 9 points.
*/



class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        int mx = *max_element(nums.begin(), nums.end());
        int dp[100001];
        vector<int> freq(100001);
        
        for(int i : nums)
        {
            freq[i]++;
        }
        
        dp[1] = freq[1];
        dp[2] = max(dp[1] , freq[2]*2);
        
        for(int i = 3; i <= mx; i++)
        {
            dp[i] = max(dp[i-1] , dp[i-2]+freq[i]*i);
        }
        
        return dp[mx];
    }
};



/* OR BUT TAKES MORE MEMORY
class Solution {
public:
    int deleteAndEarn(vector<int>& nums)
    {
        vector<int> freq(100001,0);
        vector<int> t(100001,0);
        
        for(auto i : nums)
            ++freq[i];
        
        t[1] = freq[1];
        
        
        for(int i = 2; i<100001; ++i)
        {
            t[i] = max(t[i-2]+i*freq[i], t[i-1]);
        }
        
        return t[10000];
    }
};
*/


