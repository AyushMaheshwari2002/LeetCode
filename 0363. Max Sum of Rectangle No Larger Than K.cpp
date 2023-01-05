/*  Given an m x n matrix matrix and an integer k, return the max sum of a rectangle in the matrix such that its sum is no larger than k.
    It is guaranteed that there will be a rectangle with a sum no larger than k.

            Example 1:
                  Input: matrix = [[1,0,1],[0,-2,3]], k = 2
                  Output: 2
                  Explanation: Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number no larger than k (k = 2).

            Example 2:
                  Input: matrix = [[2,2,-1]], k = 3
                  Output: 3
*/



class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) 
    {
        int r = matrix.size(), c = matrix[0].size();
        
        int prefix[r+1][c+1];
        memset(prefix,0,sizeof(prefix));
        
        for(int i=1; i<=r; ++i) 
            prefix[i][1] = prefix[i-1][1] + matrix[i-1][0];
        for(int i=1; i<=c; ++i) 
            prefix[1][i] = prefix[1][i-1] + matrix[0][i-1];
        
        for(int i=2; i<=r; ++i)
        {
            for(int j=2; j<=c; ++j)
            {
                prefix[i][j] = prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
        
        int ans = INT_MIN;
        for (int x1 = 1; x1 <= r; ++x1) 
        {
			for (int y1 = 1; y1 <= c; ++y1) 
            {
				for (int x2 = x1; x2 <= r; ++x2) 
                {
					for (int y2 = y1; y2 <= c; ++y2) 
                    {
						int sum = prefix[x2][y2] - prefix[x1-1][y2] - prefix[x2][y1-1] + prefix[x1-1][y1-1];
						if (sum <= k) 
                        {
							ans = max(ans, sum);
						}
					}
				}
			}
		}

        return ans;
    }
};



