/*  The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.
           * For example, "ACGAATTCCG" is a DNA sequence.
    When studying DNA, it is useful to identify repeated sequences within the DNA.
    Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return
    the answer in any order.

              Example 1:
                    Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
                    Output: ["AAAAACCCCC","CCCCCAAAAA"]
              
              Example 2:
                    Input: s = "AAAAAAAAAAAAA"
                    Output: ["AAAAAAAAAA"]
*/



class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> ans;
        unordered_map<string,int> m;
        
        if(s.length() <= 10)
            return ans;
        
        for(int i = 0; i <= s.length()-10; i++)
        {
            string a = s.substr(i , 10);     // create a substring of 10 characters long.
            m[a]++;
        }
        
        for(auto i : m)
        {
            if(i.second > 1)
                ans.push_back(i.first);
        }
        
        return ans;    
    }
};




