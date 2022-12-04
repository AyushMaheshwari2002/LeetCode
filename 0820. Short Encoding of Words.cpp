/*  A valid encoding of an array of words is any reference string s and array of indices indices such that:
          words.length == indices.length
          The reference string s ends with the '#' character.
          For each index indices[i], the substring of s starting from indices[i] and up to (but not including) the next '#' character is equal to words[i].
    Given an array of words, return the length of the shortest reference string s possible of any valid encoding of words.

            Example 1:
                  Input: words = ["time", "me", "bell"]
                  Output: 10
                  Explanation: A valid encoding would be s = "time#bell#" and indices = [0, 2, 5].
                  words[0] = "time", the substring of s starting from indices[0] = 0 to the next '#' is underlined in "time#bell#"
                  words[1] = "me", the substring of s starting from indices[1] = 2 to the next '#' is underlined in "time#bell#"
                  words[2] = "bell", the substring of s starting from indices[2] = 5 to the next '#' is underlined in "time#bell#"

            Example 2:
                  Input: words = ["t"]
                  Output: 2
                  Explanation: A valid encoding would be s = "t#" and indices = [0].

*/



class Solution {
public:
    int minimumLengthEncoding(vector<string>& words)
    {
        unordered_set<string> s(words.begin() , words.end());
        
        for(auto word : s)
        {
            // the will create substrings from index 1
            // like time = ime , me , e and bell = ell , ll , l
            // then then if it found any substring in set then erase thet string
            for(int i = 1; i < word.length(); i++)
            {
                s.erase(word.substr(i));
            }
        }
        
        // then find the length of characters which are left in set
        int ans = 0;
        
        for(auto i : s)
            ans += i.length() + 1;        // +1 is for "#" symbol
        
        return ans;
    }
};




