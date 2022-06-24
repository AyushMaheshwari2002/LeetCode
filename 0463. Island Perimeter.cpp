/* You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
   Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more 
   connected land cells).
   The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is 
   rectangular, width and height don't exceed 100. Determine the perimeter of the island.

            Example 1:
                  Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
                  Output: 16
                  Explanation: The perimeter is the 16 yellow stripes in the image above.

            Example 2:
                  Input: grid = [[1]]
                  Output: 4

            Example 3:
                  Input: grid = [[1,0]]
                  Output: 4
*/



class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid)
    {
        int ans = 0;
        int row = grid.size(), col = grid[0].size();
        
        for(int i = 0; i < row; i++)
        {
           for(int j = 0; j < col; j++)
           {
               if(grid[i][j] == 1)
               {
                  ans += 4;                 //we assume that all four sides are water
                  
                  if(i > 0)               //bound check
                      ans -= grid[i-1][j];
                   
                  if(j > 0)
                      ans -= grid[i][j-1];
                  
                  if(i < row-1)
                      ans -= grid[i+1][j]; 
                   
                  if(j < col-1)
                      ans -= grid[i][j+1]; 
               }
           } 
        }
        return ans;
    }
};



