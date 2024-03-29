/*  Given a matrix and a target, return the number of non-empty submatrices that sum to target.
    A submatrix x1, y1, x2, y2 is the set of all cells matrix[x][y] with x1 <= x <= x2 and y1 <= y <= y2.
    Two submatrices (x1, y1, x2, y2) and (x1', y1', x2', y2') are different if they have some coordinate that is different: for example, if x1 != x1'.

          Example 1:
                Input: matrix = [[0,1,0],[1,1,1],[0,1,0]], target = 0
                Output: 4
                Explanation: The four 1x1 submatrices that only contain 0.

          Example 2:
                Input: matrix = [[1,-1],[-1,1]], target = 0
                Output: 5
                Explanation: The two 1x2 submatrices, plus the two 2x1 submatrices, plus the 2x2 submatrix.

          Example 3:
                Input: matrix = [[904]], target = 0
                Output: 0
*/



class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size(), m = matrix[0].size(), count = 0;
        
        vector<vector<int>>temp(n+1 , vector<int>(m));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                temp[i+1][j] = temp[i][j] + matrix[i][j];
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j <= n; j++)
            {
                for(int k = 0; k < m; k++)
                {
                    int sum = 0;
                    for(int l = k; l < m; l++)
                    {
                        sum += temp[j][l] - temp[i][l];
                        if(sum == target)
                        {
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};



