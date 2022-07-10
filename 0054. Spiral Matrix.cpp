/*  Given an m x n matrix, return all elements of the matrix in spiral order.

          Example 1:
                Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
                Output: [1,2,3,6,9,8,7,4,5]

          Example 2:
                Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
                Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/



class Solution {
public:
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        vector<int> v;       // to store the resulting array
		
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
		
	//initializing direction
        int direction = 0; 

        while(top <= bottom && left <= right)
        {	
            if(direction == 0)
            {
	          //left -> right
                for(int i = left; i <= right; i++)
                {
                    v.push_back(matrix[top][i]);
                }
                top++;
            }
            
            else if(direction == 1)
            {
		//top -> bottom
                for(int i = top; i <= bottom; i++)
                {
                    v.push_back(matrix[i][right]);
                }
                right--;
            }
            
            else if(direction == 2)
            {
		//right -> left
                for(int i = right; i >= left; i--)
                {
                    v.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            
            else if(direction == 3)
            {
		//bottom -> top
                for(int i = bottom; i >= top; i--)
                {
                    v.push_back(matrix[i][left]);
                }
                left++;
            }
			
	  //increment the value of direction
            direction = (direction + 1) % 4;
        }

        return v;
    }
};



