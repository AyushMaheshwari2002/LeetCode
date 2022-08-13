/*  The numeric value of a lowercase character is defined as its position (1-indexed) in the alphabet, so the numeric value of a is 1, the numeric value of b is 2, the
    numeric value of c is 3, and so on.
    The numeric value of a string consisting of lowercase characters is defined as the sum of its characters' numeric values. For example, the numeric value of the 
    string "abe" is equal to 1 + 2 + 5 = 8.
    You are given two integers n and k. Return the lexicographically smallest string with length equal to n and numeric value equal to k.
    Note that a string x is lexicographically smaller than string y if x comes before y in dictionary order, that is, either x is a prefix of y, or if i is the first
    position such that x[i] != y[i], then x[i] comes before y[i] in alphabetic order.

            Example 1:
                  Input: n = 3, k = 27
                  Output: "aay"
                  Explanation: The numeric value of the string is 1 + 1 + 25 = 27, and it is the smallest string with such a value and length equal to 3.

            Example 2:
                  Input: n = 5, k = 73
                  Output: "aaszz"
*/




class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        //make a string of lenght n which contains all 'a'
        string s(n , 'a');
        
        k = k - n;
        
        while(k > 0)
        {
            s[--n] += min(25 , k);
            k -= min(25 , k);
        }
        
        return s;
    }
};


/*
DRY RUN
if n = 5 , k = 73

Step 1 : aaaaa    (make a string of lenght n with all 'a')
Step 2 : 68        (k = k - n)
Step 3 : while(k > 0) run the loop

        1st Iteration
             s[4] += 25                       (s[4] += min(25 , 68)
             s[4] = 'z'                       (s[4] = 'a' + min(25,68) = 'a' + 25 = 26 ==> 'z') 
             k = 43                           (k = k - min(25,68) => 68 - 25 ==> 43) 
        String becomes aaaaz  and k = 43
                                    
        2nd Iteration
             s[3] += 25                       (s[3] += min(25 , 43)
             s[3] = 'z'                       (s[3] = 'a' + min(25,43) = 'a' + 25 = 26 ==> 'z')
             k = 18                           (k = k - min(25,43) => 43 - 25 ==> 18) 
        String becomes aaazz  and k = 18
                                               
        3rd Iteration
             s[2] += 18                       (s[2] += min(25 , 18)
             s[3] = 's'                       (s[2] = 'a' + min(25,18) = 'a' + 18 = 19 ==> 's')
             k = 0                            (k = k - min(25,18) => 18 - 18 ==> 0) 
        String becomes aaszz  and k = 0
        
Step 4: Output : aaaszz                        (return s)
*/




