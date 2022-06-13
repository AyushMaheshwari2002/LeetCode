/* Given a string s, return true if s is a good string, or false otherwise.
   A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

        Example 1:
              Input: s = "abacbc"
              Output: true
              Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

        Example 2:
              Input: s = "aaabb"
              Output: false
              Explanation: The characters that appear in s are 'a' and 'b'.
              'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
*/



class Solution {
public:
    bool areOccurrencesEqual(string s) 
    {
        vector<int> v(26,0);
        
		    // Get frequency of every element
        for(int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a']++;
        }
			
		    // Freq of first element of string
	      int freq = v[s[0] - 'a'];
        
        // Check if frequency is not zero , then it should be equal to freq
		    for(int i = 0; i < v.size(); i++)
        {
            if(v[i] != 0 && v[i] != freq)
            {
                return false;
            }      
        }
        return true;
            
    }
};



