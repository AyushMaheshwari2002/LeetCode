/* 



*/




class Solution {
public:
    int scoreOfParentheses(string s)
    {    
        stack<int> st;
        int score = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
			      // if we find open parenthesis
			      // push the current score into the stack
            if(s[i] == '(')
            {
                st.push(score);
				        // reset the score to 0
                score = 0;
            }
            else                              // if we find close parenthesis
            {
                score = st.top() + max(score * 2 , 1);
                st.pop();
            }          
        }
        
        return score;        
    }
};



