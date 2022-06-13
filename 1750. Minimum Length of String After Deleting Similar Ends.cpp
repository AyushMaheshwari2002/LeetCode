/* Given a string s consisting only of characters 'a', 'b', and 'c'. You are asked to apply the following algorithm on the string any number of times:
            1. Pick a non-empty prefix from the string s where all the characters in the prefix are equal.
            2. Pick a non-empty suffix from the string s where all the characters in this suffix are equal.
            3. The prefix and the suffix should not intersect at any index.
            4. The characters from the prefix and suffix must be the same.
            5. Delete both the prefix and the suffix.
   Return the minimum length of s after performing the above operation any number of times (possibly zero times).

          Example 1:
                Input: s = "ca"
                Output: 2
                Explanation: You can't remove any characters, so the string stays as is.

          Example 2:
                Input: s = "cabaabac"
                Output: 0
                Explanation: An optimal sequence of operations is:
                - Take prefix = "c" and suffix = "c" and remove them, s = "abaaba".
                - Take prefix = "a" and suffix = "a" and remove them, s = "baab".
                - Take prefix = "b" and suffix = "b" and remove them, s = "aa".
                - Take prefix = "a" and suffix = "a" and remove them, s = "".

          Example 3:
                Input: s = "aabccabba"
                Output: 3
                Explanation: An optimal sequence of operations is:
                - Take prefix = "aa" and suffix = "a" and remove them, s = "bccabb".
                - Take prefix = "b" and suffix = "bb" and remove them, s = "cca".
*/



// TC : o(N)      SC : O(1)
class Solution {
public:
    int minimumLength(string s) 
    {
        int left = 0, right = s.length()-1;
        
        while (left < right && s[left] == s[right]) 
        {
            char ch = s[left];
            
            while (left < right && s[left] == ch) 
                left++;
            
            while (left <= right && s[right] == ch) 
                right--;
        }
        
        return right - left + 1;
    }
};



