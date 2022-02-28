/* You are given a string text of words that are placed among some number of spaces. Each word consists of one or more lowercase English letters and are separated by 
   at least one space. It's guaranteed that text contains at least one word.
   Rearrange the spaces so that there is an equal number of spaces between every pair of adjacent words and that number is maximized. If you cannot redistribute all the 
   spaces equally, place the extra spaces at the end, meaning the returned string should be the same length as text.
   Return the string after rearranging the spaces.

              Example 1:
              Input: text = "  this   is  a sentence "
              Output: "this   is   a   sentence"
              Explanation: There are a total of 9 spaces and 4 words. We can evenly divide the 9 spaces between the words: 9 / (4-1) = 3 spaces.

              Example 2:
              Input: text = " practice   makes   perfect"
              Output: "practice   makes   perfect "
              Explanation: There are a total of 7 spaces and 3 words. 7 / (3-1) = 3 spaces plus 1 extra space. We place this extra space at the end of the string.
*/



class Solution {
public:
    string reorderSpaces(string text) 
    {
       int spaces = 0;
        int i = 0;
        
        vector <string> words;
        
        while(i < text.length())
        {
            if(text[i] == ' ')
            {
                spaces ++;  //for spaces
                i++; 
            }
            
            else
            {
                string s;
                while(i < text.length() && text[i] != ' ')
                {
                    s += text[i];
                    i++;
                }
                words.push_back(s); //pushing word to the vecotor
            }
        }
        
        string ans;
        int rem_spaces = 0;   // calc remaning spaces which need to be add at end of string
        
        if(words.size() > 1)
        {
            rem_spaces = spaces % (words.size() - 1);
            int btwn = spaces / (words.size() - 1);    //for calc  equal spaces  b/w words
            
            for(int i = 0; i < words.size()-1; i++)
            {
                ans += words[i]; //adding whole word to ans string
                
                int j = 0;
                while(j < btwn)               // for spaces after word[i]
                {
                    ans += ' ';
                    j++;
                }
            }
        }
            
         else 
         {
             rem_spaces = spaces;
         }   
        
        ans += words[words.size() - 1];               //adding last word to ans
        while(rem_spaces > 0)
        {
            ans += ' ';
            rem_spaces --;
        }
        return ans;
    }
};


