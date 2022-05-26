/*  Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

            Example 1:
                  Input: num = "1432219", k = 3
                  Output: "1219"
                  Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

            Example 2:
                  Input: num = "10200", k = 1
                  Output: "200"
                  Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

            Example 3:
                  Input: num = "10", k = 2
                  Output: "0"
                  Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/




class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        // number of operation greater than length we return an empty string
        if(num.length() <= k)   
            return "0";
        
        // k is 0 , no need of removing /  preforming any operation
        if(k == 0)
            return num;
        
        stack <char> s; // char stack
        
        s.push(num[0]); // pushing first character into stack
        
        for(int i = 1; i<num.length(); ++i)
        {
            while(k > 0 && !s.empty() && num[i] < s.top())
            {
                // run if k is greater than 0 and our stack is not empty 
                //and if the upcoming element is less than the current top in stack then we will pop the stack's top
                k--;
                s.pop();
            }
            
            s.push(num[i]);
            
            // popping preceding zeroes
            if(s.size() == 1 && num[i] == '0')
                s.pop();
        }
        
        // cases like 3333 or 1234
        // because they are already in increasing order so my left most elenent is automatically minimum
        while(k > 0 && !s.empty())
        {
            k--;
            s.pop();
        }
        
        // make string of all stack elements
        string res = "";                            // result string
        while(!s.empty())
        {
            res.push_back(s.top()); // pushing stack top to string
            s.pop(); // pop the top element
        }
        
        reverse(res.begin(),res.end()); // reverse the string 
        
        if(res.length() == 0)
            return "0";
        
        return res;        
    }
};



