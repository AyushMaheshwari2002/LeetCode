/*  Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

            Example 1:
            Input: rowIndex = 3
            Output: [1,3,3,1]

            Example 2:
            Input: rowIndex = 0
            Output: [1]

            Example 3:
            Input: rowIndex = 1
            Output: [1,1]
*/



class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
     vector<vector<int>> ans;
        
     for(int i = 0; i <= rowIndex; i++)
     {
         vector<int> v(i+1,1);
         
         for(int j = 1; j < i; j++)
         {
             v[j] = ans[i-1][j] + ans[i-1][j-1];
         } 
         ans.push_back(v);
     }
     return ans[rowIndex];
    }
};


