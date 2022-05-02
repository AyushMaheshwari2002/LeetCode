/*  Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different 
    points. Answers within 10-5 of the actual answer will be accepted.

            Example 1:
            Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
            Output: 2.00000
            Explanation: The five points are shown in the above figure. The red triangle is the largest.

            Example 2:
            Input: points = [[1,0],[0,0],[0,1]]
            Output: 0.50000
*/



class Solution {
public:
        double largestTriangleArea(vector<vector<int>>& points) 
        {
            double ans = 0;
            
            for(int i = 0; i < points.size(); i++)
            {
                for(int j = i+1; j < points.size(); j++)
                {
                    for(int k = j+1; k < points.size(); k++)
                    {
                        double d1 = sqrt(pow(points[i][0]-points[j][0],2) + pow(points[i][1]-points[j][1],2));    
                        double d2 = sqrt(pow(points[j][0]-points[k][0],2) + pow(points[j][1]-points[k][1],2));
                        double d3 = sqrt(pow(points[i][0]-points[k][0],2) + pow(points[i][1]-points[k][1],2));
                        double s = (d1 + d2 + d3) / 2;
                        
                        double area = sqrt(s * (s - d1) * (s - d2) * (s - d3));

                        if(ans < area)
                             ans = area;   
                    }
                }
            }
            return ans;
    }
};



