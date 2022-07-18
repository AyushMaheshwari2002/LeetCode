/* Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than
   target.
   Note that the letters wrap around.
         * For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.

                  Example 1:
                        Input: letters = ["c","f","j"], target = "a"
                        Output: "c"

                  Example 2:
                        Input: letters = ["c","f","j"], target = "c"
                        Output: "f"

                  Example 3:
                        Input: letters = ["c","f","j"], target = "d"
                        Output: "f"
*/




class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target)
    {
        sort(letters.begin(),letters.end());
        
        for(int i = 0; i < letters.size(); i++)
        {
            if(letters[i] > target)
                return letters[i];
        }
        
        return letters[0];        // if target is 'z' so that there is no element which is greater than 'z' so that the element which is present at index 0; 
                                  // we assume that like a cycle. Ex : ...x y z a b c...
    }
};



