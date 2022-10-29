/*  Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
    You must do it in place.

            Example 1:
                  Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
                  Output: [[1,0,1],[0,0,0],[1,0,1]]

            Example 2:
                  Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
                  Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/



class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<pair<int,int>> v;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                    v.push_back(make_pair(i,j));
            }
        }
        
        for(int i = 0; i < v.size(); i++)
        {
            int row = v[i].first, col = v[i].second;
            
            for(int i = 0; i < matrix[0].size(); i++)
                matrix[row][i] = 0;
            
            for(int j = 0; j < matrix.size(); j++)
                matrix[j][col] = 0;
        }
    }
};



