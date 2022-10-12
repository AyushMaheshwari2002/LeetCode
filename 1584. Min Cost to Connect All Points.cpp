/*  You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
    The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.
    Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

          Example 1:
                Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
                Output: 20
                Explanation: 
                We can connect the points as shown above to get the minimum cost of 20.
                Notice that there is a unique path between every pair of points.

          Example 2:
                Input: points = [[3,12],[-2,5],[-4,1]]
                Output: 18
*/



class Solution {
public:
    
    int dis(vector<int>&point1,vector<int>&point2)
    {
        return abs(point1[0]-point2[0]) + abs(point1[1]-point2[1]);
    }
    
    int minCostConnectPoints(vector<vector<int>> &points)
    {
       int n = points.size();
        vector<int> visited(n,0);
        vector<int> minCost(n,INT_MAX);
        int currpoint = 0;
        minCost[0] = 0;
        int ans = 0;
        
        while(currpoint >= 0)
        {
            visited[currpoint] = 1;
            int nextpoint = -1;
            int mincurr = INT_MAX;
            
            for(int i = 0; i < n; i++)
            {
                if(visited[i] || currpoint == i)
                {
                    continue;
                }
                
                minCost[i] = min(dis(points[currpoint],points[i]) , minCost[i]);
                if(minCost[i] < mincurr)
                {
                    mincurr = minCost[i];
                    nextpoint = i;
                }
            }
            if(mincurr == INT_MAX)
            {
                ans += 0;
            }
            else
            {
                ans += mincurr;
            }
            currpoint = nextpoint;   
        }
        
        return ans;
    }
};




