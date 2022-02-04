/*  Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    
    An input string is valid if:
     1. Open brackets must be closed by the same type of brackets.
     2. Open brackets must be closed in the correct order.
 
              Example 1:
                      Input: s = "()"
                      Output: true

              Example 2:
                      Input: s = "()[]{}"
                      Output: true

              Example 3:
                      Input: s = "(]"
                      Output: false
*/


class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                stack.push(s[i]);
            
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(stack.empty())
                    return false;
                else if(s[i] == ')' && stack.top() != '(')
                    return false;
                else if(s[i] == '}' && stack.top() != '{')
                    return false;
                else if(s[i] == ']' && stack.top() != '[')
                    return false;
                else
                    stack.pop();
            }
        }
        
        if(stack.empty())
            return true;
        else
            return false;
    }
};


