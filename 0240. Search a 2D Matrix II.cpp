/*  Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
            * Integers in each row are sorted in ascending from left to right.
            * Integers in each column are sorted in ascending from top to bottom.
 

              Example 1:
                      Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
                      Output: true

              Example 2:
                      Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
                      Output: false
*/



class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int i = 0;                              // placed at first row of the matrix
        int j = matrix[0].size() - 1;           // placed at last column of the matrix
        
        while(i < matrix.size() && j >= 0)          // check for out of bound
        {
            if(matrix[i][j] == target)
                return true;
            
            else if(matrix[i][j] > target)
                j--;
            
            else if(matrix[i][j] < target)
                i++;
        }
        
        return false;
    }
};



