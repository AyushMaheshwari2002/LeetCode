/*  Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

          Example 1:
                Input: c = 5
                Output: true
                Explanation: 1 * 1 + 2 * 2 = 5

          Example 2:
                Input: c = 3
                Output: false
*/




class Solution {
public:
    bool judgeSquareSum(int c)
    {
        long long int low = 0;
        long long int high = sqrt(c);
        
         while(low <= high)
         {
             long long int check = low * low + high * high;
             
             if(check == c)
                 return true;
             
             else if(check < c)
                 low++;
             
             else
                 high--;
        }
        
        return false;
    }
};




