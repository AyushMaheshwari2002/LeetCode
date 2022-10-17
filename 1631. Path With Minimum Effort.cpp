/*  You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell
    (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up,
    down, left, or right, and you wish to find a route that requires the minimum effort.
    A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
    Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

          Example 1:
                Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
                Output: 2
                Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
                This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

          Example 2:
                Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
                Output: 1
                Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

          Example 3:
                Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
                Output: 0
                Explanation: This route does not require any effort.
*/



class Solution {
public:
    int minimumEffortPath(vector<vector<int>>&heights)
    {
        priority_queue<vector<int>,vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> dir = {{0,-1}, {-1,0}, {0,1}, {1,0}};
        int ans = 0;
        int n = heights.size();
        int m = heights[0].size();
        
        pq.push({0,0,0});
        
        while(pq.size())
        {
            auto res = pq.top();
            pq.pop();
            ans = max(ans,res[0]);

            int i = res[1];
            int j = res[2];

            if(heights[i][j] == -1)
                continue;

            if(i == n-1 && j == m-1)
            {
                break;
            }

            for(int k = 0; k < 4; k++)
            {
                int newi = i + dir[k][0];
                int newj = j + dir[k][1];
                
                if(newi < 0 || newj < 0 || newj == m || newi == n|| heights[newi][newj] == -1)
                {
                    continue;
                }
                
                pq.push({abs(heights[i][j] - heights[newi][newj]) , newi , newj});
            }
            
            heights[i][j] = -1;
        }
        
        return ans;
    }
};




