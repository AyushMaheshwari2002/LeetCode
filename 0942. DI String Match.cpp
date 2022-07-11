/*  A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:
              * s[i] == 'I' if perm[i] < perm[i + 1], and
              * s[i] == 'D' if perm[i] > perm[i + 1].
    Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.

                  Example 1:
                        Input: s = "IDID"
                        Output: [0,4,1,3,2]

                  Example 2:
                        Input: s = "III"
                        Output: [0,1,2,3]

                  Example 3:
                        Input: s = "DDI"
                        Output: [3,2,0,1]
*/



class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        int a = 0 , b = s.length();
        vector<int> v;
        
        for(int i = 0; i <= s.length(); i++)
        {
            if(s[i] == 'I')
            {
                v.push_back(a);
                a++;
            }
            else if(s[i] == 'D')
            {
                v.push_back(b);
                b--;
            }
        }
        
        v.push_back(a);  ////at last only one element is left so we can push any one out of a or b 
        return v;
    }
};



