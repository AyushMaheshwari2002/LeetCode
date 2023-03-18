/*  You are given an m x n integer matrix grid.
    We define an hourglass as a part of the matrix with the following form:
    Return the maximum sum of the elements of an hourglass.
    Note that an hourglass cannot be rotated and must be entirely contained within the matrix.

          Example 1:
                  Input: grid = [[6,2,1,3],[4,2,1,5],[9,2,8,7],[4,1,2,9]]
                  Output: 30
                  Explanation: The cells shown above represent the hourglass with the maximum sum: 6 + 2 + 1 + 2 + 9 + 2 + 8 = 30.

          Example 2:
                  Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
                  Output: 35
                  Explanation: There is only one hourglass in the matrix, with the sum: 1 + 2 + 3 + 5 + 7 + 8 + 9 = 35.
*/



// Direction Array Approach

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        
        int dx[7] = {-1,-1,-1,0,1,1,1};   // x co-ordinates
        int dy[7] = {-1,0,1,0,-1,0,1};    // y co-ordinates
        
        for(int i = 1; i < n-1; i++)
        {
            for(int j = 1; j < m-1; j++)
            {
                int sum = 0;
                for(int k = 0; k < 7; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    
                    sum += grid[x][y];
                }
                
                ans = max(sum , ans);
            }
        }
        
        return ans;
    }
};



