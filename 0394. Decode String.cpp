/*  Given an encoded string, return its decoded string.
    The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be
    a positive integer.
    You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the
    original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
    The test cases are generated so that the length of the output will never exceed 105.

              Example 1:
                    Input: s = "3[a]2[bc]"
                    Output: "aaabcbc"

              Example 2:
                    Input: s = "3[a2[c]]"
                    Output: "accaccacc"

              Example 3:
                    Input: s = "2[abc]3[cd]ef"
                    Output: "abcabccdcdcdef"
*/



// USING TWO STACK
class Solution {
public:
    string decodeString(string s)
    {
        stack<string> st;
        stack<int> num;
        
        string str;
        int n = 0;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                n = n * 10 + s[i] - '0';
            }
            else if(isalpha(s[i]))
            {
                str += s[i];
            }
            else if(s[i] == '[')
            {
                num.push(n);
                st.push(str);
                str = "";
                n = 0;
            }
            else if(s[i] == ']')
            {
                int times = num.top();
                num.pop();
                
                string a = st.top();
                st.pop();
                
                for(int i = 0; i < times; i++)
                {
                    a += str;
                }
                str = a;
            }
        }
        return str;
    }
};




/* USING SINGLE STACK
class Solution {
public:
    string decodeString(string s) 
    {
        stack<string> st;
        string str = "";
        string n = "";
        
        for(int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i])) {
                n += s[i];
            }
            
            else if(isalpha(s[i]))
                str += s[i];
            
            else if(s[i] == '[') {
                st.push(str);
                st.push(n);
                str = "";
                n = "";
            }
            
            else if(s[i] == ']')
            {   
                int times = stoi(st.top());
                st.pop();
                
                string curr_str = st.top();
                st.pop();
                
                for(int i = 0; i < times; i++)
                {
                    curr_str += str;
                }
                str = curr_str;
            }
        }
        
        return str;
    }
};
*/




