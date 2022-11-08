/*  Given a string s, return the number of palindromic substrings in it.
    A string is a palindrome when it reads the same backward as forward.
    A substring is a contiguous sequence of characters within the string.

            Example 1:
                  Input: s = "abc"
                  Output: 3
                  Explanation: Three palindromic strings: "a", "b", "c".

            Example 2:
                  Input: s = "aaa"
                  Output: 6
                  Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/



class Solution {
public:
	int countSubstrings(string s) 
    {
		int ans = 0;

		for(int i = 0; i < s.size(); i++)
        {
            // for odd
			int left = i, right = i;
			while(left >= 0 && right < s.size() && s[left] == s[right])
            {
				ans++;
				left--;
				right++;
			}
            
            // for even
			left = i, right = i + 1;
			while(left >= 0 && right < s.size() && s[left] == s[right]) 
            {
				ans++;
				left--;
				right++;
			}
		}

		return ans;
	}
};



