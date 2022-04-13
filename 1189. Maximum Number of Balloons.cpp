/*  Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
    You can use each character in text at most once. Return the maximum number of instances that can be formed.

              Example 1:
              Input: text = "nlaebolko"
              Output: 1

              Example 2:
              Input: text = "loonbalxballpoon"
              Output: 2

              Example 3:
              Input: text = "leetcode"
              Output: 0
*/



class Solution {
public:
    int maxNumberOfBalloons(string s) 
    {
        int freq[26] = {0};
        
        for(int i = 0; i < s.size(); i++)
        {
            freq[s[i]-'a']++;
        }
        
        return min({freq['b'-'a'], freq['a'-'a'], freq['l'-'a']/2, freq['o'-'a']/2, freq['n'-'a']});
    }
};


