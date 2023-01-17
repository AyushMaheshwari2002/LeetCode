/*  You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
    Find the maximum profit you can achieve. You may complete at most k transactions.
    Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

          Example 1:
                Input: k = 2, prices = [2,4,1]
                Output: 2
                Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

          Example 2:
                Input: k = 2, prices = [3,2,6,5,0,3]
                Output: 7
                Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3),
                profit = 3-0 = 3.
*/



class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        vector<int> dp(2*k+1, INT_MIN);
        dp[0] = 0;
        
        for(int j = 0; j < prices.size(); j++) 
        {    
            for(int i = 0; i+2 <= 2*k; i += 2)
            {    
                dp[i+1] = max(dp[i+1], dp[i]-prices[j]);
                dp[i+2] = max(dp[i+2], dp[i+1]+prices[j]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};




