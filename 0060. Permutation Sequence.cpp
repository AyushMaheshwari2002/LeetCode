/*  The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
    By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
             1. "123"
             2. "132"
             3. "213"
             4. "231"
             5. "312"
             6. "321"
    Given n and k, return the kth permutation sequence.

                  Example 1:
                        Input: n = 3, k = 3
                        Output: "213"

                  Example 2:
                        Input: n = 4, k = 9
                        Output: "2314"

                  Example 3:
                        Input: n = 3, k = 1
                        Output: "123"
*/




class Solution {
public:
    string getPermutation(int n, int k)
    {
       int num = 0;
       
        // using this loop we get the 1st permutation of n
       for(int i = 1; i <= n; ++i)
           num = num * 10 + i;
    
        string s = to_string(num);
      
        while(--k)
        {
            next_permutation(s.begin(),s.end());
        }
        
       return s;
    }
};



