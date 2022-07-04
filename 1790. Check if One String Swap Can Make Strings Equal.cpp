/*  You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap
    the characters at these indices.
    Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.
    
          Example 1:
                Input: s1 = "bank", s2 = "kanb"
                Output: true
                Explanation: For example, swap the first character with the last character of s2 to make "bank".

          Example 2:
                Input: s1 = "attack", s2 = "defend"
                Output: false
                Explanation: It is impossible to make them equal with one string swap.

          Example 3:
                Input: s1 = "kelb", s2 = "kelb"
                Output: true
                Explanation: The two strings are already equal, so no string swap operation is required.
*/



class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        // find the number of diff positions
        vector<int> v;
        
        for(int i = 0; i < s1.size(); i++) 
        {
            if(s1[i] != s2[i])
                v.push_back(i);
        }
        
        // when the chars are exactly the same
        if(v.empty())
            return true;
        
        // only one pair of diff positions, check if swapping makes them equal
        if(v.size() == 2) 
            swap(s1[v[0]], s1[v[1]]);
        
        return s1 == s2;
    }
};


