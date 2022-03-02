/* You are given a string title consisting of one or more words separated by a single space, where each word consists of English letters. Capitalize the string by 
   changing the capitalization of each word such that:
             * If the length of the word is 1 or 2 letters, change all letters to lowercase.
             * Otherwise, change the first letter to uppercase and the remaining letters to lowercase.
   Return the capitalized title.

              Example 1:
              Input: title = "capiTalIze tHe titLe"
              Output: "Capitalize The Title"
              Explanation:
              Since all the words have a length of at least 3, the first letter of each word is uppercase, and the remaining letters are lowercase.

              Example 2:
              Input: title = "First leTTeR of EACH Word"
              Output: "First Letter of Each Word"
              Explanation:
              The word "of" has length 2, so it is all lowercase.
              The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.

              Example 3:
              Input: title = "i lOve leetcode"
              Output: "i Love Leetcode"
              Explanation:
              The word "i" has length 1, so it is lowercase.
              The remaining words have a length of at least 3, so the first letter of each remaining word is uppercase, and the remaining letters are lowercase.
*/



class Solution {
public:
	string capitalizeTitle(string title) 
  {
		for(int i = 0; i < title.length(); i++) 
        {
			int firstIndex = i;                             // store the first index of the word

			while(i < title.length() && title[i] != ' ') 
            {
				title[i] = tolower(title[i]);          // converting the character at ith index to lower case ony by one
				i++;
			}
			
			// if word is of length greater than 2, then turn the first character of the word to upper case
			if(i - firstIndex > 2) 
            {
				title[firstIndex] = toupper(title[firstIndex]);  // converting the first character of the word to upper case
			}
		}

		return title;                      // return the final result
	}
};


