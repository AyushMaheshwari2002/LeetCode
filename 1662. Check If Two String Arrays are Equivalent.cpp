/*  Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
    A string is represented by an array if the array elements concatenated in order forms the string.

              Example 1:
              Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
              Output: true
              Explanation:
              word1 represents string "ab" + "c" -> "abc"
              word2 represents string "a" + "bc" -> "abc"
              The strings are the same, so return true.

              Example 2:
              Input: word1 = ["a", "cb"], word2 = ["ab", "c"]
              Output: false

              Example 3:
              Input: word1  = ["abc", "d", "defg"], word2 = ["abcddefg"]
              Output: true
*/



class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) 
    {
        string sum = " ", add = " ";
        
        for(int i = 0; i < word1.size(); i++)
            sum += word1[i];
        
        for(int i = 0; i < word2.size(); i++)
            add += word2[i];
        
        if(add == sum)
            return true;
        return false;
    }
};



