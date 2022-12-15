/*  There is an m x n grid with a ball. The ball is initially at the position [startRow, startColumn]. You are allowed to move the ball to one of the four adjacent
    cells in the grid (possibly out of the grid crossing the grid boundary). You can apply at most maxMove moves to the ball.
    Given the five integers m, n, maxMove, startRow, startColumn, return the number of paths to move the ball out of the grid boundary. Since the answer can be very 
    large, return it modulo 109 + 7.

            Example 1:
                  Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
                  Output: 6

            Example 2:
                  Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
                  Output: 12
*/



class Solution {
public:
    
    int dp[51][51][51];
    long int mod=1e9+7;
    
    int dfs(int m, int n, int maxMove, int r, int c)
    {
        if(r < 0 || r >= m ||c < 0 || c >= n)
            return 1;
        
        if(maxMove <= 0)
            return 0;
    
       if(dp[r][c][maxMove] !=- 1)
       {
           return dp[r][c][maxMove];
       }
        
        // for moving up, down, left and right and we do mod b'coz of large answer we get  
        return dp[r][c][maxMove] = (dfs(m,n,maxMove-1,r-1,c) % mod + dfs(m,n,maxMove-1,r+1,c) % mod + 
                                    dfs(m,n,maxMove-1,r,c-1) % mod + dfs(m,n,maxMove-1,r,c+1) % mod) % mod;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {    
        memset(dp,-1,sizeof(dp));
        
        return dfs(m,n,maxMove,startRow,startColumn);
    }
};



