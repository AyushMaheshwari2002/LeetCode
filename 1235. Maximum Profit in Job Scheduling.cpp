/*  We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].
    You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping 
    time range.
    If you choose a job that ends at time X you will be able to start another job that starts at time X.

            Example 1:
                  Input: startTime = [1,2,3,3], endTime = [3,4,5,6], profit = [50,10,40,70]
                  Output: 120
                  Explanation: The subset chosen is the first and fourth job. 
                  Time range [1-3]+[3-6] , we get profit of 120 = 50 + 70.

            Example 2:
                  Input: startTime = [1,2,3,4,6], endTime = [3,5,10,6,9], profit = [20,20,100,70,60]
                  Output: 150
                  Explanation: The subset chosen is the first, fourth and fifth job. 
                  Profit obtained 150 = 20 + 70 + 60.

            Example 3:
                  Input: startTime = [1,1,1], endTime = [2,3,4], profit = [5,6,4]
                  Output: 6
*/



class Solution {
private: int N, memo[1000001];
private:
    int dfs(vector<vector<int>>&nums, int idx)
    {
        if(idx >= N) return 0;
        if(memo[idx]) return memo[idx];
        int lo = 0, hi = N - 1, newJobTime = N + 1;
        while(lo <= hi)
        {
            int mid = (lo + hi) >> 1;
            if(nums[mid][0] >= nums[idx][1]) newJobTime = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return memo[idx] = max(dfs(nums, idx + 1), nums[idx][2] + dfs(nums, newJobTime));
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit)
     {
        N = size(profit);
        vector<vector<int>> nums;
        for(int i = 0; i < N; ++i) nums.push_back({startTime[i], endTime[i], profit[i]});
        sort(begin(nums), end(nums));
        return dfs(nums, 0);
    }
};



