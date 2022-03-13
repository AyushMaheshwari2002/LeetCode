/* Write an algorithm to determine if a number n is happy.
  A happy number is a number defined by the following process:
        * Starting with any positive integer, replace the number by the sum of the squares of its digits.
        * Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
        * Those numbers for which this process ends in 1 are happy.
  Return true if n is a happy number, and false if not.

            Example 1:
            Input: n = 19
            Output: true
            Explanation:
            12 + 92 = 82
            82 + 22 = 68
            62 + 82 = 100
            12 + 02 + 02 = 1

            Example 2:
            Input: n = 2
            Output: false
*/



class Solution {
public:
    bool isHappy(int n) 
    {
        int rem , sum = 0;
        
        while(1)
        {
            while(n > 0)
            {
                rem = n % 10;
                sum += pow(rem, 2);
                n = n / 10;
            }
            
            //break if sum = 1 or if no. is of only SINGLE DIGIT and not equal to 7 b'coz 7 is the only no. which is happy from 2 to 10.
            if(sum == 1 || sum / 10 == 0 && sum != 7)              
            {
                break;
            }
            else {
                n = sum;
                sum = 0;
            }
        }
        if(sum == 1)
            return true;
        else
            return false;
    }
};


