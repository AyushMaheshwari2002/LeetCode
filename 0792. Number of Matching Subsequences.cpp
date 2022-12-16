/*  Given a string s and an array of strings words, return the number of words[i] that is a subsequence of s.
    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the
    remaining characters.
    For example, "ace" is a subsequence of "abcde".
 
          Example 1:
                Input: s = "abcde", words = ["a","bb","acd","ace"]
                Output: 3
                Explanation: There are three strings in words that are a subsequence of s: "a", "acd", "ace".

          Example 2:
                Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
                Output: 2
*/



class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) 
    {
        map <char,vector<int>> m;
        int count = 0;
        int ind = 0;
        
        for( auto i : s)
        {
            m[i].push_back(ind++);      //char and its ocurence in vector
        }
        
        for(int i = 0; i<words.size(); i++)
        {
            string knock = words[i];
            int c = -1;   //latest value
            for(int j = 0; j<knock.size(); j++)
            {
                auto it =  upper_bound(m[knock[j]].begin(),m[knock[j]].end(),c);
                if(it == m[knock[j]].end())
                    break;
                c = *it;    //position
                if(j == knock.size() - 1)   //means string end and all character of susequnce are present
                    count++;
            }
        }
        return count;
    }
};



