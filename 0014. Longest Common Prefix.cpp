/*  Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

                Example 1:
                Input: strs = ["flower","flow","flight"]
                Output: "fl"

                Example 2:
                Input: strs = ["dog","racecar","car"]
                Output: ""
                Explanation: There is no common prefix among the input strings.
*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0) 
            return "";
        
        string ans  = "";
        sort(begin(strs), end(strs));
        
        string first_String = strs[0];
        string last_String = strs[strs.size()-1];
        
        for(int i = 0; i < first_String.size(); i++)
        {
            if(first_String[i] == last_String[i])
            {
                ans = ans + first_String[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};


