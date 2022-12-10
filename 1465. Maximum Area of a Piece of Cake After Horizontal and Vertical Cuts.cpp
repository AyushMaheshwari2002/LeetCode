/*  You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:
         * horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
         * verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
    Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the
    answer can be a large number, return this modulo 109 + 7.

          Example 1:
                Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
                Output: 4 
                Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green
                piece of cake has the maximum area.

          Example 2:
                Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
                Output: 6
                Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green
                and yellow pieces of cake have the maximum area.

          Example 3:
                Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
                Output: 9

*/



class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int hmax = 0;
        int vmax = 0;
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        for(int i = 1; i < horizontalCuts.size(); i++)
        {
            hmax = max(hmax , horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        for(int i = 1; i < verticalCuts.size(); i++)
        {
            vmax = max(vmax , verticalCuts[i] - verticalCuts[i-1]);
        }
        
        return (1LL * vmax * hmax) % (1000000007);     //1LL used to make the product long long or integer sign overflow will occur.

    }
};



