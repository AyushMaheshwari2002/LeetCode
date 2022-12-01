/*  Given a triangle array, return the minimum path sum from top to bottom.
    For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or 
    index i + 1 on the next row.

              Example 1:
                    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
                    Output: 11
                    Explanation: The triangle looks like:
                       2
                      3 4
                     6 5 7
                    4 1 8 3
                    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

              Example 2:
                    Input: triangle = [[-10]]
                    Output: -10
*/



class Solution {
public:
    
    int solve(int i, int j, int n, vector<vector<int>>&triangle, vector<vector<int>>&dp)
    {
		if(i == n - 1)
			return triangle[i][j];
        
		if(dp[i][j] != -1)
			return dp[i][j];
        
		int bottom = triangle[i][j] + solve(i+1, j, n, triangle, dp);
		int  bottom_right = triangle[i][j] + solve(i+1, j+1, n, triangle, dp);
        
		return dp[i][j] = min(bottom, bottom_right);
	}
    
	int minimumTotal(vector<vector<int>>& triangle)
    {
		int n = triangle.size();
		vector<vector<int>>dp(n, vector<int>(n, -1));
        
		return solve(0, 0, n, triangle, dp);
	}
};



