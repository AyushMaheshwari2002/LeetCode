/*  Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.
    Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

          Example 1:
          Input: s = "1 + 1"
          Output: 2

          Example 2:
          Input: s = " 2-1 + 2 "
          Output: 3

          Example 3:
          Input: s = "(1+(4+5+2)-3)+(6+8)"
          Output: 23

*/



class Solution {
public:
    int calculate(string s) 
    {
        int n = s.size();
        stack<int> st;
        int sign =  1, sum = 0;
        
        for(int i =0 ; i<n; ++i)
        {
            if(s[i] >= '0' and s[i] <= '9')
            {
                int num = 0;
                while(s.size() > i and s[i] >= '0' and s[i] <= '9')
                {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                sum += num * sign;
                --i;
            }
            else if(s[i] == '+')
                sign = 1;
            else if(s[i] == '-')
                sign = -1;
            else if(s[i] == '(')
            {
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 1;
            }
            else if(s[i] == ')')
            {
                sum = st.top() * sum;
                st.pop();
                sum += st.top();
                st.pop();
            }
        }
        return sum;
    }
};



