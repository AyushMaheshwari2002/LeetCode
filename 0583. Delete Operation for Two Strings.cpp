/*  Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
    In one step, you can delete exactly one character in either string.

          Example 1:
                Input: word1 = "sea", word2 = "eat"
                Output: 2
                Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

          Example 2:
                Input: word1 = "leetcode", word2 = "etco"
                Output: 4
*/



//Time : O(m*n), Space : O(m*n)      MEMORIZATION

class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        
        int lcs = helper(word1, word2, m, n, memo);
        
        int steps = (m - lcs) + (n - lcs);
        
        return steps;
    }
    
    int helper(string word1, string word2, int m, int n, vector<vector<int>> &memo)
    {
        if(m == 0 || n == 0)
            return 0;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(word1[m-1] == word2[n-1])
            return memo[m][n] = 1 + helper(word1, word2, m-1, n-1, memo);
        
        else
            return memo[m][n] = max(helper(word1, word2, m-1, n, memo), helper(word1, word2, m, n-1, memo));
    }
};



