/*  Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the
    answer in any order.
    Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.

            Example 1:
                  Input: n = 3, k = 7
                  Output: [181,292,707,818,929]
                  Explanation: Note that 070 is not a valid number, because it has leading zeroes.

            Example 2:
                  Input: n = 2, k = 1
                  Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
*/



class Solution {
public:
    vector<int> ans;
    
    void Solve(int len , int &k , int num, int digit)
    {
        if(len == 0 )
        {
                ans.push_back(num);
           return ;
        }
        for(int i = 0 ; i<10 ; i++)
        {
            if(abs(i-digit) == k)
                Solve(len-1 , k, num*10 + i, i);
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int n, int k) 
    {
        for(int i = 1 ; i<=9 ; i++)
        {
             Solve(n-1 , k, i, i);
        }
        
        return ans;
    }
};




