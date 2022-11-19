/*  Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

            Example 1:
                  Input: x = 2.00000, n = 10
                  Output: 1024.00000

            Example 2:
                  Input: x = 2.10000, n = 3
                  Output: 9.26100

            Example 3:
                  Input: x = 2.00000, n = -2
                  Output: 0.25000
                  Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/



class Solution {
public:
    
    double solve(double x, long n)
    {
        if(n == 0)
            return 1.0;
        
        if(n == 1)
            return x;
        
        if(n < 0)
            return solve(1/x , -n);
        
        // if n is even 
        double res = solve(x * x, n/2);
        
        // if n is odd then again multiply the number by n 
        if(n % 2 != 0)
        {
            res *= x;
        }
        
        return res;
    }
    
    
    double myPow(double x, int n) 
    {
        return solve(x , n);
    }
};



