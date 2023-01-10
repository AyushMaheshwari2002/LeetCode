/*  Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

            Example 1:
                  Input: haystack = "sadbutsad", needle = "sad"
                  Output: 0
                  Explanation: "sad" occurs at index 0 and 6.
                  The first occurrence is at index 0, so we return 0.

            Example 2:
                  Input: haystack = "leetcode", needle = "leeto"
                  Output: -1
                  Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/



// Two Pointer Approach
class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;
        
        while(i < haystack.size() && j < needle.size())
        {
            if(haystack[i] == needle[j])
            {
                i++;
                j++;
                
                if(j == needle.size())
                    return i - needle.size();                     
            }
            
            else {
                i = i-j+1;
                j = 0;
            }
        }
        
        return -1;
    }
};




