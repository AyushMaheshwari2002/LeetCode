/*  Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

            Example 1:
                  Input: n = 3
                  Output: 5

            Example 2:
                  Input: n = 1
                  Output: 1
*/




class Solution {
public:
    int numTrees(int n)
    {
        if(n < 2) 
            return 1;
        
        // take n+1 b'coz there will be a possibility of n = 0
        vector<int> v(n+1, 0);
        v[0] = 1, v[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                // Catalan's Number Formula
                v[i] += v[j] * v[i-j-1];
            }
        }
        return v[n];
    }
};



