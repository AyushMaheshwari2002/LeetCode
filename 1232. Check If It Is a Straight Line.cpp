/*  You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in 
    the XY plane.

              Example 1:
                    Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
                    Output: true

              Example 2:
                    Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
                    Output: false
*/



class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates)
    {
        int xdiff = coordinates[1][0] - coordinates[0][0];          // (x2 - x1)
        int ydiff = coordinates[1][1] - coordinates[0][1];          // (y2 - y1)
        
        for(int i = 2; i < coordinates.size(); i++) 
        {
            int curr_xdiff = coordinates[i][0] - coordinates[0][0];       // (x3 - x2)
            int curr_ydiff = coordinates[i][1] - coordinates[0][1];       // (y3 - y2)
            
            if(curr_xdiff * ydiff != curr_ydiff * xdiff) 
                return false; 
        }
        
        return true;
    }
};



