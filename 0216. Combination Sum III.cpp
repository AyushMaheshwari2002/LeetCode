/*  Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
           * Only numbers 1 through 9 are used.
           * Each number is used at most once.
    Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

            Example 1:
                  Input: k = 3, n = 7
                  Output: [[1,2,4]]
                  Explanation:
                  1 + 2 + 4 = 7
                  There are no other valid combinations.

            Example 2:
                  Input: k = 3, n = 9
                  Output: [[1,2,6],[1,3,5],[2,3,4]]
                  Explanation:
                  1 + 2 + 6 = 9
                  1 + 3 + 5 = 9
                  2 + 3 + 4 = 9
                  There are no other valid combinations.

            Example 3:
                  Input: k = 4, n = 1
                  Output: []
                  Explanation: There are no valid combinations.
                  Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.
*/



class Solution {
public:
    
    void helper(vector<vector<int>>& res, vector<int>& v, int k, int n, int start)
    {
        if(k == v.size())
        {
            if(n == 0) 
                res.push_back(v);
            return;
        }
        for(int i = start; i <= 9; i++)
        {
            v.push_back(i);
            helper(res, v, k, n-i, i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> v;
        
        helper(res, v, k, n, 1);
        
        return res;
    }
};



