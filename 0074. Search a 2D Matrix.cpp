/*  Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
            * Integers in each row are sorted from left to right.
            * The first integer of each row is greater than the last integer of the previous row.
 
          Example 1:
                  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
                  Output: true

          Example 2:
                  Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
                  Output: false
*/



// BINARY SEARCH
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




/* NAIVE APPROACH
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == target)
                    return true;
            }
        }
        
        return false;
    }
};
*/




