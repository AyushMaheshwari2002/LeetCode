/*  Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

          Example 1:
                Input: n = 3
                Output: ["((()))","(()())","(())()","()(())","()()()"]

          Example 2:
                Input: n = 1
                Output: ["()"]
*/



class Solution {
public:
    vector<string> res;
    
    void helper(int open, int close, int n, string current)
    {
        /* OR WE CAN USE THIS CONDITION TO STOP RECURSION
        if(open == n && close == n)
        {
            result.push_back(current);
            return;
        }
        */
        
        if(current.length() == n*2)
        {
            res.push_back(current);
            return;
        }
        
        if(open < n)  
            helper(open+1 , close , n , current+"(");
        
        if(close < open)
            helper(open , close+1 , n , current+")");
    }
    
    vector<string> generateParenthesis(int n)
    {
        helper(0 , 0 , n , "");
        
        return res;
    }
};




