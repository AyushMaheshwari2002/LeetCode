/*  Given an array points where points[i] = [xi, yi] represents a point on the X-Y plane, return true if these points are a boomerang.
    A boomerang is a set of three points that are all distinct and not in a straight line.

            Example 1:
                  Input: points = [[1,1],[2,3],[3,2]]
                  Output: true

            Example 2:
                  Input: points = [[1,1],[2,2],[3,3]]
                  Output: false
*/



class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) 
    {
        //Calculate the area of the triangle: x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2) and compare it to zero.
        
        return (p[0][0] * (p[1][1] - p[2][1]) + p[1][0] * (p[2][1] - p[0][1]) + p[2][0] * (p[0][1] - p[1][1])) != 0;
    }
};




