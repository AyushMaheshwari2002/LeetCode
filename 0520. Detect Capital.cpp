/* We define the usage of capitals in a word to be right when one of the following cases holds:
   All letters in this word are capitals, like "USA".
   All letters in this word are not capitals, like "leetcode".
   Only the first letter in this word is capital, like "Google".
   Given a string word, return true if the usage of capitals in it is right.

                  Example 1:
                  Input: word = "USA"
                  Output: true

                  Example 2:
                  Input: word = "FlaG"
                  Output: false
*/



class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int count = 0;
        for (int i = 0; i < word.length(); i++) // case 1 for all capital letters
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                count++;
            }
        }
        if (count == word.length())
            return true;

        count = 0;
        for (int i = 0; i < word.length(); i++) // case 2 for all small letters
        {
            if (word[i] >= 'a' && word[i] <= 'z')
            {
                count++;
            }
        }
        if (count == word.length())
            return true;

        count = 0;
        for (int i = 0; i < word.length()-1; i++) // case 3 for first letter of word capital rest small
        {
            if (word[0] >= 'A' && word[0] <= 'Z' && word[i + 1] >= 'a' && word[i + 1] <= 'z')
            {
                count++;
            }
        }
        if (count + 1 == word.length()) // loop running to length-1 therefore cnt is incremented
            return true;

        return false; // if none of the case match
    }
};


