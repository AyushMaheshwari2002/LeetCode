/*  Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to 
    target.
    Each number in candidates may only be used once in the combination.
    Note: The solution set must not contain duplicate combinations.

              Example 1:
                    Input: candidates = [10,1,2,7,6,1,5], target = 8
                    Output: 
                    [
                    [1,1,6],
                    [1,2,5],
                    [1,7],
                    [2,6]
                    ]

              Example 2:
                    Input: candidates = [2,5,2,1,2], target = 5
                    Output: 
                    [
                    [1,2,2],
                    [5]
                    ]
*/



class Solution {
public:

    void Sum(vector<int> &candidates, int target, vector<vector<int>> & res, vector<int> &r, int idx)
    { 
        if(target == 0)
        {
            // if we get exact answer
            res.push_back(r);
            return;
        }
        
        for(int i = idx; i < candidates.size(); i++)
        {
            if(i > idx && candidates[i] == candidates[i-1])
                continue;
            
            if(candidates[i] > target)
                break;
            
            r.push_back(candidates[i]);                  // add them to vector
            
            // recursive call for next numbers
            Sum(candidates , target - candidates[i] , res , r , i+1);
            
            // Remove number from vector (backtracking)
            r.pop_back();
        }
}
    
     
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());                  // sort candidates array
                
        vector<int> r;
        vector<vector<int>> res;
        
        Sum(candidates , target , res , r , 0);
        
        return res;
    }
};



