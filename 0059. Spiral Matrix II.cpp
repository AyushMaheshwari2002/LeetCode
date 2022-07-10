/*  Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

          Example 1:
                Input: n = 3
                Output: [[1,2,3],[8,9,4],[7,6,5]]

          Example 2:
                Input: n = 1
                Output: [[1]]
*/



class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        // create n * n vector of vectors we will populate and return at the end
        vector<vector<int>> v(n, vector<int>(n));
        
        int top = 0 , bottom = n - 1 , left = 0 , right = n - 1;
		
	//initializing direction
        int direction = 0; 
        int val = 1;

        while(top <= bottom && left <= right)
        {	
            if(direction == 0)
            {
		//left -> right
                for(int i = left; i <= right; i++)
                {
                    v[top][i] = val++;
                }
                top++;
            }
            
            else if(direction == 1)
            {
		//top -> bottom
                for(int i = top; i <= bottom; i++)
                {
                    v[i][right] = val++;
                }
                right--;
            }
            
            else if(direction == 2)
            {
		//right -> left
                for(int i = right; i >= left; i--)
                {
                    v[bottom][i] = val++;
                }
                bottom--;
            }
            
            else if(direction == 3)
            {
		//bottom -> top
                for(int i = bottom; i >= top; i--)
                {
                    v[i][left] = val++;
                }
                left++;
            }
			
		//increment the value of direction
            direction = (direction + 1) % 4;
        }

        return v;
    }
};



