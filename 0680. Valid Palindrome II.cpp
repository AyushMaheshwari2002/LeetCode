/*  Given a string s, return true if the s can be palindrome after deleting at most one character from it.

            Example 1:
                  Input: s = "aba"
                  Output: true

            Example 2:
                  Input: s = "abca"
                  Output: true
                  Explanation: You could delete the character 'c'.

            Example 3:
                  Input: s = "abc"
                  Output: false
*/


class Solution {
public:
    bool validPalindrome(string s) 
    {
        int start = 0;
        int end = s.length()-1;
        int count1 = 0, count2 = 0;
        
        while(start < end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else                   //for case like a b f e e b a  
            {                      //skip from start side(f) and count1++
                start++;
                count1++;
            }
        }
        
        start = 0, end= s.length()-1;
        while(start < end)
        {
            if(s[start] == s[end])
            {
                start++;
                end--;
            }
            else                   //for case like a b e e f b a  
            {                      //skip from end side(f) and count2++
                end--;
                count2++;
            }
        }
        
        if(count1 == 1 || count2 == 1)       //we skip only for one time then this is Palindrome
            return true;
        if(count1 == 0 || count2 == 0)       //if we will not skip then this is already a palindrome
            return true;
        
        return false;                        //if we have to skip more than one time then return false
    }
};

