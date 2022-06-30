/* Given a string s, return the number of segments in the string.
   A segment is defined to be a contiguous sequence of non-space characters.

          Example 1:
                Input: s = "Hello, my name is John"
                Output: 5
                Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

          Example 2:
                Input: s = "Hello"
                Output: 1
*/



class Solution {
public:
    int countSegments(string s) 
    {
        // Breaking input into word using string stream
        // Used for breaking words
        stringstream str(s);

        // To store individual words
        string word;

        int count = 0;
        while (str >> word)
        {
            count++;
        }
        
        return count;
    }
};



