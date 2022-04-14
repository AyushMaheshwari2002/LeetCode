/*  An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
    Given an integer n, return the nth ugly number.

          Example 1:
          Input: n = 10
          Output: 12
          Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

          Example 2:
          Input: n = 1
          Output: 1
          Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
*/



class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int> res(1, 1);
        int i = 0, j = 0, k = 0;
        
        while(res.size() < n)
        {
            res.push_back(min(res[i] * 2, min(res[j] * 3, res[k] * 5)));
            
            if(res.back() == res[i] * 2)
                i++;
            if(res.back() == res[j] * 3)
                j++;
            if(res.back() == res[k] * 5)
                k++;
        }
        
        return res[n - 1];
    }
};


