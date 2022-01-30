/*  Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

            Example 1:
                    Input: s = "anagram", t = "nagaram"
                    Output: true

            Example 2:
                    Input: s = "rat", t = "car"
                    Output: false
*/



class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        vector<int> v(26,0);              //create a vector v of size 26 and store 0 in all indexes
            
        for(int i = 0; i < s.size(); i++)
        {
            v[s[i] - 'a']++;            // s[0] => a , v[a - 'a'] => v[97 - 97] => v[0] , this will store the value at index 0 and then v[0]++
        }
        for(int i = 0; i < t.size(); i++)
        {
            v[t[i] - 'a']--;           // t[0] => n , v[n - 'a'] => v[110 - 97] => v[13] , this will delete the value at index 13 and then v[13]++
        }
        
        for(int i = 0; i < 26; i++)        //traverse the vector v from 0 to 26 
        {
            if(v[i] != 0)                  //if all the index is not 0 then return False else True
                return false;
        }
        return true;
    }
};


