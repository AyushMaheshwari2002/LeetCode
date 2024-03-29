/*  Given a sentence text (A sentence is a string of space-separated words) in the following format:
        * First letter is in upper case.
        * Each word in text are separated by a single space.
    Your task is to rearrange the words in text such that all words are rearranged in an increasing order of their lengths. If two words have the same length, arrange
    them in their original order.
    Return the new text following the format shown above.

            Example 1:
                  Input: text = "Leetcode is cool"
                  Output: "Is cool leetcode"
                  Explanation: There are 3 words, "Leetcode" of length 8, "is" of length 2 and "cool" of length 4.
                  Output is ordered by length and the new first word starts with capital letter.

            Example 2:
                  Input: text = "Keep calm and code on"
                  Output: "On and keep calm code"
                  Explanation: Output is ordered as follows:
                  "On" 2 letters.
                  "and" 3 letters.
                  "keep" 4 letters in case of tie order by position in original text.
                  "calm" 4 letters.
                  "code" 4 letters.

            Example 3:
                  Input: text = "To be or not to be"
                  Output: "To be or to be not"
*/



class Solution {
public:
    string arrangeWords(string text) 
    {
        text[0] = tolower(text[0]);      // convert 1st letter into lowercase
        
        map<int,vector<string>> m;
    
        for(int i = 0; i < text.size(); i++)
        {
            string str = "";
            while(i < text.length() && text[i] != ' ')
            {
                str += text[i++];
            }
            m[str.length()].push_back(str);
        }
        
        string ans = "";
        for(auto i : m)               // map will be in sorted order automatically
        {
            for(auto s : i.second)
                ans += s + " ";
        }
        
        ans[0] = toupper(ans[0]);        // convert 1st alphabet into uppercase
        ans.pop_back();                  // remove last added extra space
        
        return ans;
    }
};




