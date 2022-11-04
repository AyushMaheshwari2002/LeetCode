/*  Given an m x n integers matrix, return the length of the longest increasing path in matrix.
    From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is 
    not allowed).

            Example 1:
                  Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
                  Output: 4
                  Explanation: The longest increasing path is [1, 2, 6, 9].

            Example 2:
                  Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
                  Output: 4
                  Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.

            Example 3:
                  Input: matrix = [[1]]
                  Output: 1
*/



class Solution {
public:
    int N,M;
    vector<vector<int>> dp;
    
    int dfs(int x, int y, vector<vector<int>>&matrix)
    {
        if(dp[x][y])
            return dp[x][y];
        
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int ans = 1;
        
        for(int i = 0; i < 4; i++)
        {
            int X = x + dir[i][0];
            int Y = y + dir[i][1];
            
            if(X < 0 || X >= N || Y < 0 || Y >= M)
                continue;
            if(matrix[X][Y] <= matrix[x][y])
                continue;
            ans=max(ans , 1 + dfs(X,Y,matrix));
        }
        return dp[x][y] = ans;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        int n = matrix.size();
        if(n == 0)
            return 0;
        
        int m = matrix[0].size();
        N = n;
        M = m;
        dp = vector<vector<int>>(n,vector<int>(m,0));
        int res = 0;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m ; j++)
            {
                res = max(res , dfs(i,j,matrix));
            }
        }
        return res;
    }
};




