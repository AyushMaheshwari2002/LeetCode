/*  Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.
    In one shift operation:
           * Element at grid[i][j] moves to grid[i][j + 1].
           * Element at grid[i][n - 1] moves to grid[i + 1][0].
           * Element at grid[m - 1][n - 1] moves to grid[0][0].
    Return the 2D grid after applying shift operation k times.

              Example 1:
                    Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
                    Output: [[9,1,2],[3,4,5],[6,7,8]]

              Example 2:
                    Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
                    Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

              Example 3:
                    Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
                    Output: [[1,2,3],[4,5,6],[7,8,9]]
*/




class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k)
    {
        vector<int> v;
        
        int row = grid.size();
        int col = grid[0].size();
    
        // push all the elements of 2D matrix into vector
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                v.push_back(grid[i][j]);  
            }
        }
        
        int idx = v.size()-1;
        // this will pick the last element from vector and put it in the beginning and remove from last
        while(k--)
        {
            v.insert(v.begin() , v[idx]);
        
        }
        
        // convert 1D vector into 2D vector
        int p = 0;
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                grid[i][j] = v[p];
                p++;
            }
        }
        
        return grid;
    }
};




