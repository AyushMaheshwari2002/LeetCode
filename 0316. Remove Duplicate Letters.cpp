/*  Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical
    order among all possible results.

            Example 1:
                  Input: s = "bcabc"
                  Output: "abc"

            Example 2:
                  Input: s = "cbacdcbc"
                  Output: "acdb"
*/




class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> last(26);    // this will store the last occurrence of every character
        vector<bool> visited(26);     // this will check that we visit that character or not
        
        string ans = "";
        
        // this loop will count the last occurrence
        for(int i = 0; i < s.size(); i++)
        {
            last[s[i] - 'a'] = i;
        }
        
        for(int i = 0; i < s.size(); i++)
        {
            // if we already visited that character then we will continue the loop without adding it.
            if(visited[s[i] - 'a'])
                continue;
            
            while(!ans.empty() && ans.back() > s[i] && last[ans.back() - 'a'] > i)
            {
                visited[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            
            ans.push_back(s[i]);
            visited[s[i] - 'a'] = true;
        }
        
        return ans;
    }
};




