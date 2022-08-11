/*  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover 
    all the intervals in the input.

            Example 1:
                  Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
                  Output: [[1,6],[8,10],[15,18]]
                  Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

            Example 2:
                  Input: intervals = [[1,4],[4,5]]
                  Output: [[1,5]]
                  Explanation: Intervals [1,4] and [4,5] are considered overlapping.
*/



class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;
        int start = intervals[0][0] , end = intervals[0][1];
        
        for(auto i : intervals)
        {
            // no overlapping
            // here i contains 2 values like [1,3] so we use i[0] and i[1]
            if(i[0] > end)
            {
                ans.push_back({start,end});
                // update start and end
                start = i[0];
                end = i[1];
            }
            // overlapping
            else
            {
                end = max(end , i[1]);
            }
        }
        ans.push_back({start,end});
            
        return ans;
    }
};



