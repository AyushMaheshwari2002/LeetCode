/*  Given a balanced parentheses string s, return the score of the string.
    The score of a balanced parentheses string is based on the following rule:
						* "()" has score 1.
						* AB has score A + B, where A and B are balanced parentheses strings.
						* (A) has score 2 * A, where A is a balanced parentheses string.
 
									Example 1:
												Input: s = "()"
												Output: 1

									Example 2:
												Input: s = "(())"
												Output: 2

									Example 3:
												Input: s = "()()"
												Output: 2
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



